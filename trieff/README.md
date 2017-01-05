### Note
This is one of my first programming projects in Javascript. (Or, at least, that's what I remember.)

## Installation and usage

#### Node.js
`node install trieff`

#### Example
```
var trieff;
require("trieff").createFile("./path/file.trieff", function createFile(err, file) {
  if (err) throw err;
  
  trieff = file;
  
  var buffer = new Buffer(8);
  buffer.write("World");
  
  trieff.addEntry("hello", buffer, function(err, key, numKey, value) {
    getData();
  });
});

function getData() {
  console.log(trieff.getEntry("hello")); //World
}
```

## Specification
Specification for .trieff file format can be found at [Github](https://github.com/mik-jozef/trieff/blob/master/trieff%20specification.txt).

## API

This serves as a quick illustration of what this module can do. Full API can be found at [Github wiki](https://github.com/mik-jozef/trieff/wiki). There are also few [examples](https://github.com/mik-jozef/trieff/wiki/Examples).

### Getting the file


#### require("trieff").createFile(path[, numOfNodes][, options], callback)
Creates a new .trieff file at 'path' with 'numOfNodes' nodes.  Callback gets two arguments: `(err, file)`, where file is instance of TrieffFile.

#### require("trieff").openFile(path[, numOfNodes], callback)
Opens an existing .trieff file at 'path' and allocates space for at least 'numOfNodes'. Callback gets two arguments: `(err, file)`, where file is instance of TrieffFile.

### TrieffFile extends EventEmitter
Class for using .trieff files. Shouldn't be created directly. Use `openFile()` or `createFile()` instead.

### TrieffFile fields

#### head Object
Contains .trieff head variables. Refer to the trieff specification for more info or see below in section "How .trieff works". Changing those will seriously corrupt the file.

#### emptyBuffer Buffer
Empty buffer. You can use `addEntry(key, emptyBuffer)` to delete an entry.

#### bufferSizeMultiplier Number
When an internal buffer is full, a new one with length approximately `buffer.length * bufferSizeMultiplier` will be created.

#### defaultBufferSizeMultiplier Number (static)
When a new file is created/opened, `bufferSizeMultiplier` is initialized to this.

### TrieffFile methods

#### resize(multiplier Number, minResize Number)
Resizes internal buffer approximately to length oldLength * multiplier, creating at least `minResize` nodes. Returns undefined.

#### getEntry(key String | Array)
Returns value assigned to `key`. This method relies only on internal buffer, no file operations are made. More about `key` in the full API or in the section "What is a key?".

#### addEntry(key String | Array, value Buffer[, callback])
Assigns `value` to `key`. Changes are visible only after they are written to disk, calling `getEntry(key)` right after `addEntry(key, value)` will not show the latest state. It is safe to call `addEntry()` before the previous finished. Callback is only called when write will be attempted, i.e arguments are valid. Returns true if arguments are valid, false otherwise.

#### close([callback])
Closes file used by this object. Reading is still possible. Does nothing if called multiple times. No subsequent writess will be possible. Writes not even started will be accessible through `this.writeQueue`.

#### arrayToString(array Array[, checkLength boolean])
Converts valid Array key to String key. Returns undefined if `array` is not valid.

#### stringToArray(string String[, checkLength boolean])
Converts valid String key to Array key. Returns undefined if `string` is not valid.

## How .trieff works

### What is a trie?

Trie is a tree data structure, where key is defined by value's position in the trie. All descendants of a node have common prefix. There's a [nice article](https://en.wikipedia.org/wiki/Trie) on Wikipedia on tries.

### Trieff head

Every .trieff file contains head, which is the first thing in the document. It contains trieff `head variables` and string of `allowed characters`. Trieff head variables are accesible in `TrieffFile.head` Changing these will corrupt your file.

* [G] - Greatest node address used in this document (internal)
* [N] - Number of node addresses per node
* [A] - Length of node address in bytes 
* [D] - Length of data address in bytes
* [F] - Length of `allowed characters` string in bytes (internal)
* [min] - minimum length of a query
* [max] - maximum length of a query

Head contains these variables in the specified order and `allowed characters` string, which contains every character usable as key.

You can set trieff head contents (except \[F], and in most cases [N]) during file creation using the `options` argument. You can specify three more parameters to `options`:
* `flag String`: one of [node filesystem flags](https://nodejs.org/api/fs.html#fs_fs_open_path_flags_mode_callback)
* `filetype boolean`: which if true will add .trieff extension to path of it's not already there
* `string String`: `allowed characters` string.

```
//Default options object:
{ //g: don't set
, n: 37 //set only if string is empty, default string.length
, a: 4
, d: 8
, //f: don't set
, min: 0
, max: 20
, flag: 'wx+'
, filetype: true
, string: "abcdefghijklmnopqrstuvwxyz0123456789_"
}
```

```
createFile("./test.png", {filetype: false}, function(err, file) {
  //trieff in stealth mode
  //would end up as "./test.png.trieff" if (filetype == true)
});
```

### Trieff body

Trieff body consists only of nodes. Every node has [N] node addresses and one data address. Data address contains saved values. Node addresses point to child nodes, one node address == one allowed character. Important thing to remember is that every node has a data address, so if you set key "hi", then "h" will also have value (0). For this reason, every `getEntry(unknownKey)` returns empty buffer, even if key was invalid.

### What is a key?
You can use two types of keys interchangeably: strings made of `allowed characters` or arrays of non-negative integers, where every integer is smaller than [N]. Integer `i` is equivalent of `this.head.string.charAt(i)`. If `this.head.string === "abc"`, then keys "aca" and [0, 2, 0] are identical and will give you the same result. There are two conversion methods in TrieffFile, arrayToString() and stringToArray(), see above.

### Did I forget anything?

Is something unclear? Spotted an error or a typo? Have a suggestion? Contact me at [mik.jozef@gmail.com](mailto:mik.jozef@gmail.com). Also, this is one of my first programming projects, I'll appreciate your feedback.








