/*/
  Main component of the text editor.
/*/

import "./dialog.js";
import "./filesystem.js";
import "./tabs.js";

// Key under which the filesystem is saved in localStorage.
const rootLS = "rootFolder";

const DialogType = {
  none: {},
  editEntry: {},
  addEntry: {},
}

const NextActionType = {
  openFile: {},
  selectFile: {},
  closeFile: {},
}

Vue.component("App", {
  data: function() {
    let rootFolder = localStorage.getItem(rootLS);
    
    if (!rootFolder) {
      rootFolder = '{ "folder": true, "name": "(root folder)", "entries": [], "expanded": true }';
      
      localStorage.setItem(rootLS, rootFolder);
    }
    
    rootFolder = JSON.parse(rootFolder);
    
    return {
      dialog: DialogType.none,
      dialogData: null,
      DialogType,
      NextActionType,
      nextAction: null,
      rootFolder,
      tabs: {
        arr: [],
        selectedIndex: null,
      },
      textAreaContent: null,
      closingUnsaved: false,
      autosave: false,
    };
  },
  computed: {
    isUnsaved: function() {
      if (this.tabs.selectedIndex === null) return undefined;
      
      return this.tabs.arr[this.tabs.selectedIndex].content !== this.textAreaContent;
    },
  },
  methods: {
    saveFS: function() {
      localStorage.setItem(rootLS, JSON.stringify(this.rootFolder));
    },
    editEntryDialog: function(parent, entry) {
      this.dialog = DialogType.editEntry;
      this.dialogData = { entry, parent };
      
      this.cancelAction();
    },
    addEntryDialog: function(folder) {
      this.dialog = DialogType.addEntry;
      this.dialogData = folder;
      
      this.cancelAction();
      
      folder.expanded = true;
      
      this.saveFS();
    },
    cancelDialog: function() {
      this.dialog = DialogType.none;
      this.dialogData = null;
    },
    editEntry: function(parent, entry, name) {
      if (name === "") throw new Error("Empty name");
      if (parent.entries.some(a => a.name === name)) throw new Error("Renaming to existing entry");
      
      entry.name = name;
      
      this.saveFS();
      
      this.cancelDialog();
    },
    addEntry(folder, entryType, name) {
      if (name === "") throw new Error("Empty name");
      if (folder.entries.some(a => a.name === name)) throw new Error("Adding existing entry");
      
      const entry = entryType === "file"
          ? { folder: false, name, content: "" }
          : { folder: true, entries: [], name, expanded: true };
      
      folder.entries.push(entry);
      
      this.saveFS();
      
      this.cancelDialog();
    },
    deleteEntry: function(parent, name) {
      parent.entries = parent.entries.filter(a => a.name !== name);
      
      this.saveFS();
      
      this.cancelDialog();
    },
    toggleExpanded: function(folder) {
      folder.expanded = !folder.expanded;
      
      this.saveFS();
    },
    toggleAutosave: function() {
      this.autosave = !this.autosave;
    },
    setClosingUnsaved: function(nextAction, value = this.isUnsaved) {
      this.closingUnsaved = value;
      this.nextAction = nextAction;
    },
    openFile: function(file) {
      let index = this.tabs.arr.indexOf(file);
      
      if (index != -1) {
        this.selectFile(index);
        
        return;
      }
      
      if (this.isUnsaved) {
        this.setClosingUnsaved({ type: this.NextActionType.openFile, file });
        
        return;
      }
      
      this.tabs.arr.push(file);
      
      this.selectFile(this.tabs.arr.length - 1);
    },
    closeFile: function(index) {
      if (this.isUnsaved) {
        this.setClosingUnsaved({ type: this.NextActionType.closeFile, index });
        
        return;
      }
      
      if (this.tabs.arr.length === 1) {
        this.tabs.selectedIndex = null;
        
        this.tabs.arr.splice(index, 1);
        
        return
      }
      
      if (this.tabs.selectedIndex > index
            || this.tabs.selectedIndex + 1 === this.tabs.arr.length) {
        this.tabs.selectedIndex--;
      }
      
      this.tabs.arr.splice(index, 1);
      
      this.textAreaContent = this.tabs.arr[this.tabs.selectedIndex].content;
    },
    selectFile: function(index) {
      if (this.isUnsaved) {
        this.setClosingUnsaved({ type: this.NextActionType.selectFile, index });
        
        return;
      }
      
      this.tabs.selectedIndex = index;
      
      this.textAreaContent = this.tabs.arr[index].content;
    },
    setText: function(text) {
      this.textAreaContent = text;
      
      if (this.autosave) {
        this.saveFile();
      }
    },
    saveFile: function() {
      this.tabs.arr[this.tabs.selectedIndex].content = this.textAreaContent;
      
      this.saveFS();
      this.doAction();
    },
    discardFile: function() {
      this.textAreaContent = this.tabs.arr[this.tabs.selectedIndex].content;
      
      this.doAction();
    },
    cancelAction: function() {
      this.setClosingUnsaved(null, false);
    },
    doAction: function() {
      if (!this.nextAction) return;
      
      switch (this.nextAction.type) {
        case this.NextActionType.openFile: this.openFile(this.nextAction.file); break;
        case this.NextActionType.selectFile: this.selectFile(this.nextAction.index); break;
        case this.NextActionType.closeFile: this.closeFile(this.nextAction.index); break;
      }
      
      this.setClosingUnsaved(null);
    },
  },
  template:
    "<div class='app'>"
    + "<DialogEdit v-if='dialog == DialogType.editEntry'"
    +       ":actions='{ cancelDialog, editEntry, deleteEntry }'"
    +       ":entry='dialogData.entry'"
    +       ":parent='dialogData.parent' />"
    
    + "<DialogAdd v-if='dialog == DialogType.addEntry'"
    +       ":actions='{ cancelDialog, addEntry }' :folder='dialogData' />"
    
    + "<FileSystem :rootFolder='rootFolder' :actions='{ editEntryDialog, addEntryDialog, toggleExpanded, openFile }' />"
    + "<Tabs :tabs='tabs' :textAreaContent='textAreaContent' :autosave='autosave'"
    +       ":actions='{ closeFile, selectFile, setText, saveFile, discardFile, cancelAction, toggleAutosave }'"
    +       ":isUnsaved='isUnsaved' :closingUnsaved='closingUnsaved' />"
  + "</div>",
});
