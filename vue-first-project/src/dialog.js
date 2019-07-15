/*/
  Dialog component.
/*/

Vue.component("Dialog", {
  props: [ "actions" ],
  methods: {
    backgroundClick: function(e) {
      if (e.target == this.$el) {
        e.stopPropagation();
        
        this.actions.cancelDialog();
      }
    }
  },
  template:
    "<div class='text-editor-dialog-background' v-on:click='backgroundClick'>"
    + "<div class='text-editor-dialog'>"
    +   "<slot />"
    + "</div>"
  + "</div>",
});

Vue.component("DialogAdd", {
  data: function() {
    return {
      entryType: "file",
      name: "",
      error: null,
    };
  },
  props: [ "actions", "folder" ],
  methods: {
    validate: function() {
      if (this.name === "") {
        this.error = "Name cannot be empty.";
        
        return;
      }
      
      if (this.folder.entries.some(a => a.name === this.name)) {
        this.error = "This name already exists";
        
        return;
      }
      
      this.error = null;
    },
    validateAndAddEntry: function() {
      this.validate();
      
      if (this.error) return;
      
      this.actions.addEntry(this.folder, this.entryType, this.name);
    },
  },
  template:
    "<Dialog :actions='actions'>"
    + "<h3>Create new file/folder</h3>"
    + "<p>Create a <input type='radio' value='file' v-model='entryType' />"
    + " file / <input type='radio' value='folder' v-model='entryType'> folder.</p>"
    + "<p>Name: <input v-model='name' v-on:change='validate' /></p>"
    + "<p class='dialog-error' v-if='error'>"
    +   "{{ error }}"
    + "</p>"
    + "<p>"
    +   "<input type='submit' value='Create' v-on:click='validateAndAddEntry' /> "
    +   "<input type='submit' value='Cancel' v-on:click='actions.cancelDialog' />"
    + "</p>"
  + "</Dialog>",
});

Vue.component("DialogEdit", {
  data: function() {
    return {
      name: this.entry.name,
      error: null,
    }
  },
  props: [ "actions", "entry", "parent" ],
  methods: {
    validate: function() {
      if (this.name === "") {
        this.error = "Name cannot be empty.";
        
        return;
      }
      
      if (this.parent && this.parent.entries.some(a => a.name === this.name)) {
        this.error = "This name already exists";
        
        return;
      }
      
      this.error = null;
    },
    validateAndEditEntry: function() {
      this.validate();
      
      if (this.error) return;
      
      this.actions.editEntry(this.parent, this.entry, this.name);
    },
    deleteEntry: function() {
      this.actions.deleteEntry(this.parent, this.entry.name);
    },
  },
  template:
    "<Dialog :actions='actions'>"
    + "<h3>Edit file/folder</h3>"
    + "<p>Name: <input v-model='name' v-on:change='validate' /></p>"
    + "<p class='dialog-error' v-if='error'>"
    +   "{{ error }}"
    + "</p>"
    + "<p>"
    +   "<input type='submit' value='Edit name' v-on:click='validateAndEditEntry' /> "
    +   "<input type='submit' value='Delete' v-on:click='deleteEntry' :disabled='!parent' /> "
    +   "<input type='submit' value='Cancel' v-on:click='actions.cancelDialog' />"
    + "</p>"
  + "</Dialog>",
});
