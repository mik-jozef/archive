/*/
  Components of filesystem explorer.
  
  Files and folders in localStorage have the following structure:
  
  Folder: {
    folder: true,
    entries: array of files and folders,
    name: name of the folder,
    expanded: true iff expanded in the menu,
  }
  
  File: {
    folder: false,
    name: name of the file,
    content: content of the file,
  }
/*/

Vue.component("FileSystem", {
  props: [ "actions", "rootFolder" ],
  template:
    "<div class='fs'>"
    + "<h2>Files</h2>"
    + "<div class='folders'>"
    +   "<Folder :folder='rootFolder' :actions='actions' />"
    + "</div>"
  + "</div>",
});

Vue.component("Folder", {
  props: [ "folder", "parent", "actions" ],
  computed: {
    folders: function() { return this.folder.entries.filter(a => a.folder) },
    files: function() { return this.folder.entries.filter(a => !a.folder) },
  },
  methods: {
    toggleExpanded: function() {
      this.actions.toggleExpanded(this.folder);
    },
  },
  template:
    "<div class='fs-folder'>"
    + "<div class='fs-folder-top'>"
    +   "<div class='fs-folder-name' v-on:click='toggleExpanded'>"
    +     "<img :src='folder.expanded ? \"/img/folder-expanded.png\" : \"/img/folder-hidden.png\"' class='cursor-pointer' />"
    +     " {{folder.name}}"
    +   "</div>"
    +   "<img src='/img/fs-edit.png' class='fs-icons' v-on:click='actions.editEntryDialog(parent, folder)' />"
    +   "<img src='/img/fs-add-entry.png' class='fs-icons' v-on:click='actions.addEntryDialog(folder)' />"
    +   "<div class='clear-both' />"
    + "</div>"
    + "<div class='fs-folder-entries' v-show='folder.expanded'>"
    +   "<Folder v-for='entry in folders' :folder='entry' :actions='actions' :parent='folder' :key='entry.name' />"
    +   "<File v-for='entry in files' :file='entry' :actions='actions' :parent='folder' :key='entry.name' />"
    + "</div>"
  + "</div>",
});

Vue.component("File", {
  props: [ "file", "parent", "actions" ],
  computed: {
    folders: function() { return this.folder.entries.filter(a => a.folder) },
    files: function() { return this.folder.entries.filter(a => !a.folder) },
  },
  methods: {
    openFile: function(e) {
      e.preventDefault();
      
      this.actions.openFile(this.file);
    },
  },
  template:
    "<div class='fs-file'>"
    + "<div class='fs-folder-top'>"
    +   "<div class='fs-folder-name fs-file-name' v-on:dblclick='openFile'>"
    +     "{{file.name}}"
    +   "</div>"
    +   "<img src='/img/fs-edit.png' class='fs-icons' v-on:click='actions.editEntryDialog(parent, file)' />"
    +   "<div class='clear-both' />"
    + "</div>"
  + "</div>",
});
