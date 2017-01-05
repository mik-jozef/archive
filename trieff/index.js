/**
 * Provides createFile() and openFile() functions for
 * accessing TrieffFile class.
 * 
 * Trieff or .trieff?
 * Trieff refers to specification or document components (e.g. trieff head),
 * .trieff refers to a file with extension '.trieff' or the extension itself
 * 
 * Notes and limitations (some may be fixed in future versions):
 * 1. [A] must be less than or equal to 6
 * 2. Absolutely no data validity control of file contents is
 *    performed.
 * 3. Numeric overflow for large file is not checked for.
 * 4. If error appears during write operation, file will get corrupted.
 * 5. This implementation is not good for use cases where entries are
 *    deleted frequently as deleted entry is just rewritten data address,
 *    nodes leading to that address are not removed, which means unused space.
 * 6. Changes to the document will be visible only after they were written
 *    to file, querying the document after calling addEntry() may not show
 *    latest state.
 * 
 * Created and maintained by Jozef Mikusinec.
 * Provided under MIT license.
 * Contact me at mik.jozef+trieff@gmail.com
 * For typos/grammatical mistakes please
 * use mik.jozef+grammar@gmail.com
 */
 
var TrieffFile = require("./trieff");
var fs = require("fs");
 
 /**
 * Opens a .trieff file. Does nothing if callback is not provided.
 * 
 * :Params
 * path String: path to the file
 * numOfNodes Number (optional): minimum number of nodes, will be rewritten
 *   if lower than current amount of nodes times, default 1
 *   TrieffFile.defaultBufferSizeMultiplier
 * 
 * :Callback
 * err Error | null:
 * file TrieffFile | null: .trieff file opened, null if there's an error
 * 
 * :Returns
 * undefined
 */
exports.openFile = function openFile(path, numOfNodes, callback) {
  
  //validate arguments
  if (typeof callback !== 'function') {
    if (typeof numOfNodes === 'function') {
      callback = numOfNodes;
    } else {
      return;
    }
  }
  
  if (typeof path !== 'string') {
    callback(new Error("Path is not a string: " + path), null);
    return;
  }
  
  if (typeof numOfNodes !== 'number') {
    numOfNodes = 1;
  }
  
  //open file
  fs.open(path, 'r+', function fsOpen(err, fd) {
    if (err) {
      callback(err, null);
      return;
    }
    
    //buffer for head data
    var buffer = new Buffer(28);
    fs.read(fd, buffer, 0, 28, 0, function readHead(err, bytesRead, buffer) {
      if (err) {
        callback(err, null);
        return;
      }
      
      if (bytesRead < 28) {
        callback(new Error("Trieff - file too small."), null);
        return;
      }
      
      var options = {};
      options.g = buffer.readUInt32BE(0);
      options.n = buffer.readUInt32BE(4);
      options.a = buffer.readUInt32BE(8);
      options.d = buffer.readUInt32BE(12);
      options.f = buffer.readUInt32BE(16);
      options.min = buffer.readUInt32BE(20);
      options.max = buffer.readUInt32BE(24);
      
      //assuring buffer will be big enough
      if (numOfNodes < (options.g + 1) * TrieffFile.defaultBufferSizeMultiplier) {
        numOfNodes = Math.ceil((options.g + 1) * TrieffFile.defaultBufferSizeMultiplier);
      }
      buffer = new Buffer(numOfNodes * (options.n * options.a + options.d) + options.f + 28);
      
      //read entire file
      fs.read(fd, buffer, 0, buffer.length, 0, function readAll(err, bytesRead, buffer) {
        if (err) {
          callback(err, null);
          return;
        }
        
        if (bytesRead < 28 + options.f) {
          callback(new Error("Trieff - file too small."), null);
          return;
        }
        
        options.string = buffer.toString('utf8', 28, 28 + options.f);
        
        callback(null, new TrieffFile(fd, options, buffer));
      });
    });
  });
}

/**
 * Creates a new .trieff file.
 * 
 * :Params
 * path String: path to the file
 * numOfNodes Number (optional): number of empty nodes created beforehand,
 *   default 1
 * options Object (optional):
 *   options.flag string: file open mode
 *   options.filetype boolean: add .trieff file extension to 'path'
 *     if it's not already there
 *   options[n,a,d,min,max,string] Number: .trieff head data,
 *     refer to trieff specification for more info
 *   options[n,a,d,min,max] must be integers, otherwise they are
 *     reassigned to default values
 *   options[n,f] will be assigned internaly if options.string
 *     is a non-empty string, otherwise it options.n must
 *     be assigned explicilty
 *   default: {flag: 'wx+', filetype: true, a: 32, d: 64, min: 0,
 *     max: 20, string: 'abcdefghijklmnopqrstuvwxyz0123456789_'}
 * 
 * :Callback
 * err Error | null:
 * file TrieffFile | null: newly created .trieff file, null if
 *   there's an error
 * 
 * :Returns
 * undefined
 */
exports.createFile = function createFile(path, numOfNodes, options, callback) {
  
  //validate arguments
  if (typeof callback !== 'function') {
    if (typeof options === 'function') {
      callback = options;
      
      if (typeof numOfNodes === 'object') {
        options = numOfNodes;
      }
    } else if (typeof numOfNodes === 'function') {
      callback = numOfNodes;
    } else {
      return;
    }
  }
  
  if (typeof path !== 'string') {
    callback(new Error("Path is not a string: " + path), null);
    return;
  }
  
  if (typeof numOfNodes !== 'number') {
    numOfNodes = 1;
  }
  
  if (typeof options !== 'object') {
    options = {};
  }
  
  options.flag = options.flag || 'wx+';
  if (!options.filetype && options.filetype !== false) {
    options.filetype = true;
  }
  
  //add .trieff extension
  var pathLib = require("path");
  path = pathLib.normalize(path);
  var parsedPath = pathLib.parse(path);
  
  if (parsedPath.ext !== ".trieff" && options.filetype) {
    parsedPath.base += ".trieff";
    parsedPath.ext = ".trieff";
    path = pathLib.format(parsedPath);
  }
  
  //open file
  fs.open(path, options.flag, function fsOpen(err, fd) {
    if (err) {
      callback(err, null);
      return;
    }
    
    delete options.flag;
    delete options.filetype;
    
    //set default options, check value sanity
    options.g = 0
    if (!options.a || options.a % 1 !== 0 || options.a < 1 || options.a > 6) {
      options.a = 4;
    }
    if (!options.d || options.d % 1 !== 0 || options.d < 1) {
      options.d = 8;
    }
    if (!options.min || options.min % 1 !== 0 || options.min < 0) {
      options.min = 0;
    }
    if (!options.max || options.max % 1 !== 0 || options.max < options.min) {
      options.max = 20 >= options.min ? 20 : options.min;
    }
    if (typeof options.string !== 'string') {
      options.string = "abcdefghijklmnopqrstuvwxyz0123456789_";
    }
    if (options.string) {
      options.n = options.string.length;
    }
    options.f = Buffer.byteLength(options.string, 'utf8');
    
    if (numOfNodes < 1) numOfNodes = 1;
    if (!options.n || options.n < 0 || options.n % 1 !== 0) {
      callback(new Error("Options.p not set, real or negative."), null);
      return;
    }
    
    //create buffer for 'numOfNodes' nodes, write head
    var buffer = new Buffer(numOfNodes * (options.n * options.a + options.d) + options.f + 28);
    buffer.writeUInt32BE(0, 0);
    buffer.writeUInt32BE(options.n, 4);
    buffer.writeUInt32BE(options.a, 8);
    buffer.writeUInt32BE(options.d, 12);
    buffer.writeUInt32BE(options.f, 16);
    buffer.writeUInt32BE(options.min, 20);
    buffer.writeUInt32BE(options.max, 24);
    buffer.write(options.string, 28, 'utf8');
    buffer.fill(0, 28 + options.f, buffer.length);
    
    //write buffer to file, callback new TrieffFile
    fs.write(fd, buffer, 0, buffer.length, function writeFile(err, written, buffer) {
      if (err) {
        callback(err, null);
        return;
      }
      
      callback(null, new TrieffFile(fd, options, buffer));
    });
  });
}