/**
 * This module provides TrieffFile class for reading and manipulating .trieff
 * files. Shouldn't be created directly, there are createFile() and openFile()
 * functions in index.js.
 */
"use strict";

var fs = require("fs");
var events = require("events");

/**
 * TrieffFile object will be callbacked from createFile and openFile. Used to
 * modify and retrieve information from a .trieff file.
 * 
 * :Params
 * fd Number: file descriptor of a .trieff file
 * head Object: trieff head variables, see Trieff spec for more info
 * buffer Buffer: stores the .trieff file for faster reading
 * 
 * :Callback
 * none
 * 
 * :Object extends EventListener
 * Fields:
 * fd Number (internal): file descriptor of the opened file
 * head Object: Contains trieff head variables, see trieff
 *   specification for more info.
 *   head[a,d,f] are divided by 8 internally to represent
 *     number of bytes instead of bits
 * headLength Number (internal): Length of .trieff file head in bytes,
 * nodeLength Number (internal): Length of one node in bytes
 * buffer Buffer (internal): Contains all data of this file
 * bufferHead Buffer (internal): Slice of 'buffer', contains head of the document
 * bufferBody Buffer (internal): Slice of 'buffer', contains body of the document
 * bufferSizeMultiplier Number: When buffer is full, new buffer with space for
 *   head.g * bufferSizeMultiplier nodes will be created
 * emptyBuffer Buffer: Empty buffer with length of head.d, this value is returned
 *   when 'key' in addEntry(.) is invalid, use addEntry(key, this.emptyBuffer)
 *   to delete a key.
 * defaultBufferSizeMultiplier (static): all new TrieffFiles will be initialized
 *   with this value as bufferSizeMultiplier, default 1.5
 * writeQueue Array (internal): Contains queue of write operations to be written
 * isBeingWritten boolean (internal): True if writing to the file
 * 
 * Methods:
 * resize(multiplier, minResize): Resizes this.buffer
 *   multiplier Number: the new buffer will have space for
 *     head.g * bufferSizeMultiplier nodes
 *   minResize Number: minimal number of nodes to add
 *   returns undefined: undefined
 * 
 * getEntry(key): Returns value assigned to 'key'. Keys are not updated until
 *     written to file, this method may return old value some time after calling
 *     addEntry(.).
 *   key String | Array: Key to retrieve.
 *   returns Buffer: buffer containing value assigned to 'key', or copy of emptyBuffer.
 * 
 * addEntry(key, value[, callback]): Assigns 'value' to 'key',
 *     use addEntry(key, this.emptyBuffer) to delete an entry.
 *   key String | Array: Key to which 'value' will be assigned
 *   value Buffer | Number: Value assigned to 'key'
 *   callback function: Function called after value is written to file
 *       and is visible through getEntry(.) Will be only called if true is returned.
 *     err Error | null:
 *     key String | null: String made of allowed characters or null if array was
 *       used as key
 *     numKey Array:
 *     value Buffer:
 *     
 *   returns boolean: true if write will be attempted (i.e. file is still open and
 *     arguments are valid) and callback will be called.
 * 
 * close([callback]): Close .trieff file so write operations will not be possible.
 *     Reading is still posible through buffer. Does nothing if
 *     file was already closed. Unfinished writes will still be
 *     accessible from this.writeQueue.
 *   callback function:
 *     err | null:
 *   returns undefined:
 * 
 * arrayToString(array[, checkLength]): Converts array of integers to string of allowed characters
 *   array Array: array of integers which will be converted
 *   checkLength boolean: count too short/long array as invalid, default true
 *   returns String | undefined: String made of allowed characters or undefined
 *     if array contains negative, real or numbers greater than head.n
 * 
 * stringToArray(string[, checkLength]): Converts string of allowed characters to array of
 *     their respective integers
 *   string String: String made of allowed characters
 *   checkLength boolean: count too short/long string as invalid, default true
 *   returns Array | undefined: Array of integers or undefined if string is invalid
 * 
 * Listeners:
 * _writeAction: Attemts to write first element of writeQueue if !isBeingWritten
 */
var TrieffFile = function(fd, head, buffer) {
  events.EventEmitter.call(this);
  this.fd = fd;
  this.head = head;
  
  this.headLength = this.head.f + 28;
  this.nodeLength = this.head.n * this.head.a + this.head.d;
  
  this.buffer = buffer;
  this.bufferHead = buffer.slice(0, this.headLength);
  this.bufferBody = buffer.slice(this.headLength, buffer.length);
  this.bufferSizeMultiplier = TrieffFile.defaultBufferSizeMultiplier;
  
  this.writeQueue = [];
  this.isBeingWritten = false;
  
  this.emptyBuffer = new Buffer(this.head.d);
  this.emptyBuffer.fill(0);
  
  this.on('_writeAction', function() {
    write(this);
  });
};

TrieffFile.prototype = Object.create(events.EventEmitter.prototype);
TrieffFile.defaultBufferSizeMultiplier = 1.5;

/**
 * Used by TrieffFile.addEntry() and TrieffFile.close()
 * to prevent simultaneous writes/writes after file is closed.
 */
function write(trieff) {
  //if file is open and no _writeAction is running now and there is something to write
  if (trieff.fd !== -1 && !trieff.isBeingWritten && trieff.writeQueue.length != 0) {
    var action = trieff.writeQueue.shift();
    trieff.isBeingWritten = true;
    var callback = action.callback || function() {};
    
    //if closing file
    if (action.close) {
      fs.close(trieff.fd, function closeFile(err) {
        if (err) {
          callback(err);
          return;
        }
        
        trieff.fd = -1;
        trieff.isBeingWritten = false;
        
        callback(null);
      });
      return;
    }
    
    //reads through existing addresses until empty address is found
    var address = 0, lastAddress;
    for (var f = 0; f < action.numKey.length; f++) {
      lastAddress = address;
      address = trieff.bufferBody.readUIntBE(address * trieff.nodeLength
            + action.numKey[f] * trieff.head.a, trieff.head.a);
      
      if (address === 0) {
        break;
      }
    }
    
    //if modifying existing entry, modify just the entry
    if (f === action.numKey.length) {
      var writeStart = address * trieff.nodeLength + trieff.head.n * trieff.head.a;
      
      fs.write(trieff.fd, action.value, 0, trieff.head.d, writeStart + trieff.headLength, function (err) {
        if (err) {
          trieff.isBeingWritten = false;
          callback(err, action.key, action.numKey, action.value);
          trieff.emit('_writeAction');
          return;
        }
        
        action.value.copy(trieff.bufferBody, writeStart);
        trieff.isBeingWritten = false;
        callback(null, action.key, action.numKey, action.value);
        trieff.emit('_writeAction');
      });
    } else {
      //if buffer is too small, resize
      if (trieff.bufferBody.length < (trieff.head.g + action.numKey.length - f + 1) * trieff.nodeLength) {
        trieff.resize(trieff.bufferSizeMultiplier, action.numKey.length - f);
      }
      
      //buffers for parts of the file which need to be changed:
      //head.g, address to the newly created nodes and the nodes themselves
      var bufHeadG, bufAddress, bufAppend;
      bufHeadG = new Buffer(4);
      bufHeadG.writeUInt32BE(trieff.head.g + action.numKey.length - f, 0);
      bufAddress = new Buffer(trieff.head.a);
      bufAddress.writeUIntBE(trieff.head.g + 1, 0, trieff.head.a);
      bufAddress.trieffWritePosition = lastAddress * trieff.nodeLength + action.numKey[f] * trieff.head.a;
      bufAppend = new Buffer((action.numKey.length - f) * trieff.nodeLength);
      bufAppend.trieffWritePosition = (trieff.head.g + 1) * trieff.nodeLength;
      bufAppend.fill(0);
      
      var tempG = trieff.head.g + 1;
      for (var f2 = 0; f2 < action.numKey.length - f - 1; f2++) {
        bufAppend.writeUIntBE(++tempG, f2 * trieff.nodeLength + action.numKey[f2 + f + 1] * trieff.head.a, trieff.head.a);
      }
      
      action.value.copy(bufAppend, f2 * trieff.nodeLength + trieff.head.n * trieff.head.a);
      
      var done = 0, isErr = false;
      
      //used as a callback in the next three fs.write(.) invocations
      var writeCallback = function writeCallback(err) {
        if (err) {
          isErr = true;
          callback(err, action.key, action.numKey, action.value);
        }
        
        done++;
        if (done === 3) {
          if (isErr) {
            this.isBeingWritten = false;
            return;
          }
          
          //calls callback
          updateBuffer(trieff, bufHeadG, bufAddress, bufAppend, callback, action);
        }
      };
      
      //update head.g
      fs.write(trieff.fd, bufHeadG, 0, 4, 0, function(err) {
        writeCallback(err);
      });
      
      //add missing address to what is in bufAppend
      fs.write(trieff.fd, bufAddress, 0, trieff.head.a, bufAddress.trieffWritePosition + trieff.headLength, function(err) {
        writeCallback(err);
      });
      
      //append bufAppend to file
      fs.write(trieff.fd, bufAppend, 0, bufAppend.length, bufAppend.trieffWritePosition + trieff.headLength, function(err) {
        writeCallback(err);
      });
    }
  }
}

/**
 * Writes new entries to buffer after they have been written to file.
 */
function updateBuffer(trieff, bufHeadG, bufAddress, bufAppend, callback, action) {
  bufHeadG.copy(trieff.bufferHead);
  bufAddress.copy(trieff.bufferBody, bufAddress.trieffWritePosition);
  bufAppend.copy(trieff.bufferBody, bufAppend.trieffWritePosition);
  trieff.head.g = bufHeadG.readUInt32BE(0);
  
  trieff.isBeingWritten = false;
  callback(null, action.key, action.numKey, action.value);
  trieff.emit('_writeAction');
}

/**
 * Creates new buffer greater than the previous one and copies its content
 * into the new buffer.
 */
TrieffFile.prototype.resize = function resize(multiplier, minResize) {
  if (multiplier <= 1) {
    multiplier = Trieff.defaultBufferSizeMultiplier >= 1 ?
          Trieff.defaultBufferSizeMultiplier : 1;
  }
  
  var newSize = Math.ceil(this.head.g * multiplier);
  if (newSize < this.head.g + minResize + 1) {
    newSize = this.head.g + minResize + 1;
  }
  
  var newBuffer = new Buffer(newSize * this.nodeLength + this.headLength);
  newBuffer.fill(0, this.buffer.length, newBuffer.length);
  this.buffer.copy(newBuffer);
  
  this.buffer = newBuffer;
  this.bufferHead = this.buffer.slice(0, this.headLength);
  this.bufferBody = this.buffer.slice(this.headLength, this.buffer.length);
};

/**
 * Retrieves value assigned to key 'key'.
 * 
 * :Params
 * key String | Array: key made of allowed characters or array of
 *   numbers
 * 
 * :Callback
 * none
 * 
 * :Returns
 * buffer containing value assigned to 'key' or copy of emptyBuffer if 'key' is
 *   invalid or not found
 */
TrieffFile.prototype.getEntry = function getEntry(key) {
  var value = new Buffer(this.head.d);
  this.emptyBuffer.copy(value);
  
  //key length check
  if (key.length < this.head.min || key.length > this.head.max) {
    return value;
  }
  
  //for every character/number in key
  var currentKey, address = 0;
  for (var f = 0; f < key.length; f++) {
    // if string convert to number
    if (typeof key === 'string') {
      currentKey = this.head.string.indexOf(key.charAt(f));
      } else {
      currentKey = key[f];
    }
    
    //if invalid key, return empty buffer
    if (typeof currentKey !== 'number' || currentKey >= this.head.n || currentKey < 0 || currentKey % 1 !== 0) {
      return value;
    }
    
    //read next address
    address = this.bufferBody.readUIntBE(address * this.nodeLength
          + currentKey * this.head.a, this.head.a);
    
    //if address does not exist
    if (address === 0) {
      return value;
    }
  }
  
  address = address * this.nodeLength + this.head.n * this.head.a;
  this.bufferBody.copy(value, 0, address, address + this.head.d);
  
  return value;
};

/**
 * Adds new key-value pair. Returns true if the write will be attempted, i.e. key
 * and value are valid. Callback is only called if true was returned.
 * 
 * Use addEntry(key, 0, callback) to delete entry. No new node will be created
 * for a value of zero. Note you can't actually delete any value. Allocate one
 * more byte as a flag and if you need that.
 * 
 * :Params
 * key String | Array: key made of allowed characters/array of numbers
 * value Buffer: value to be assigned to 'key'
 * 
 * :Callback
 * err Error | null: file write error
 * key String | null: key added, null if array was used
 * numKey Array: key added, always present
 * value Buffer: value assigned to 'key'
 * 
 * :Returns
 * true if write will be attempted, i.e arguments are valid, false otherwise
 */
TrieffFile.prototype.addEntry = function addEntry(key, value, callback) {
  //this function only performs data validity checks and passes
  //results to writeQueue, then emits '_writeAction'
  
  //if file is closed; see TrieffFile.close
  if (this.fd === -1
        || key.length < this.head.min
        || key.length > this.head.max ) {
    return false;
  }
  
  //if value is invalid
  if (!(value instanceof Buffer) || value.length !== this.head.d) {
    return false;
  }
  
  //key string to array conversion
  var numKey = [];
  if (typeof key === 'string') {
    for (var f = 0; f < key.length; f++) {
      numKey[f] = this.head.string.indexOf(key.charAt(f));
    }
  } else {
    numKey = key;
    key = null;
  }
  
  //create local copy of value to prevent rewriting before it is added
  var valueCopy = new Buffer(value.length);
  value.copy(valueCopy);
  value = valueCopy;
  
  //key validity check
  for (var f = 0; f < numKey.length; f++) {
    if (numKey[f] >= this.head.n || numKey[f] < 0 || numKey[f] % 1 !== 0) {
      return false;
    }
  }
  
  this.writeQueue.push(
  { key: key
  , numKey: numKey
  , value: value
  , callback: callback
  });
  
  // _writeAction makes sure no writes are performed simultaneously
  this.emit('_writeAction');
  return true;
};

/**
 * Converts array of integers to string of allowed characters.
 * :Params
 * array Array: array of integers which will be converted
 * checkLength boolean (optional): count too short/long array as invalid,
 *   default true
 * 
 * :Callback
 * none
 * 
 * :Returns
 * String | undefined: String made of allowed characters or undefined
 *     if array contains negative, real or numbers greater than head.n
 */
TrieffFile.prototype.arrayToString = function arrayToString(array, checkLength) {
  if (checkLength !== false
        && (array.length < this.head.min || array.length > this.head.max)) {
    return;
  }
  
  var s = [];
  for (var f = 0; f < array.length; f++) {
    if (array[f] < 0 || array[f] >= this.head.n || array[f] % 1 !== 0) {
      return;
    } else s[f] = this.head.string.charAt(array[f]);
  }
  
  return s.join("");
};

/**
 * Converts string of allowed characters to array of their respective integers
 * 
 * :Params
 * string String: String made of allowed characters
 * checkLength boolean (optional): count too short/long string as invalid,
 *   default true
 * 
 * :Callback
 * none
 * 
 * :Returns
 * Array | undefined: Array of integers or undefined if string is invalid
 */
TrieffFile.prototype.stringToArray = function stringToArray(string, checkLength) {
  if (checkLength !== false
        && (string.length < this.head.min || string.length > this.head.max)) {
    return;
  }
  
  var a = [];
  for (var f = 0; f < string.length; f++) {
    a[f] = this.head.string.indexOf(string.charAt(f));
    
    if (a[f] === -1) {
      return;
    }
  }
  
  return a;
};

/**
 * Close .trieff file so write operations will not be possible.
 * Reading is still posible through buffer. Does nothing if
 * file was already closed. Unfinished writes will still be
 * accessible from this.writeQueue.
 *  
 * :Params
 * none
 * 
 * :Callback (optional)
 * err Error | null: error from fs.close
 * 
 * :Returns
 * undefined
 */
TrieffFile.prototype.close = function close(callback) {
  if (this.fd !== 1) {
    if (typeof callback !== 'function') {
      callback = function() {};
    }
    
    this.writeQueue.push(
    { close: true
    , callback: callback
    });
    
    this.emit('_writeAction');
  } else {
    callback(null);
  }
};

module.exports = TrieffFile;