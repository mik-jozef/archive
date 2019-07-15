/*/
  The part of the editor that contains tabs with editable text.
/*/

Vue.component("Tabs", {
  props: [ "tabs", "actions", "textAreaContent", "isUnsaved", "closingUnsaved", "autosave" ],
  computed: {
    file: function() {
      return this.tabs.arr[this.tabs.selectedIndex];
    },
  },
  template:
    "<div class='tabs'>"
    + "<p class='tabs-empty-message' v-if='tabs.arr.length == 0'>"
    +   "(Open a file by double clicking it in the menu on the left.)"
    + "</p>"
    + "<div v-else>"
    +   "<DialogSaveChanges v-if='closingUnsaved' :actions='actions' />"
    +   "<TabsPanel :tabs='tabs' :isUnsaved='isUnsaved' :autosave='autosave' :actions='{ ...actions }' />"
    +   "<TextArea :text='textAreaContent' :actions='{ ...actions }' />"
    +  "</div>"
  + "</div>",
});

Vue.component("TabsPanel", {
  props: [ "tabs", "actions", "isUnsaved", "autosave" ],
  template:
    "<div class='tabs-panel'>"
    + "<Tab v-for='(file, i) in tabs.arr' :file='file' :key='file.name'"
    +       ":isSelected='i === tabs.selectedIndex'"
    +       ":isTextUnsaved='isUnsaved'"
    +       " :actions='actions' :index='i' />"
    + "<p class='tabs-autosave-p' v-on:click='actions.toggleAutosave'>"
    +   "Autosave {{ autosave ? \"on\" : \"off\" }}"
    + "</p>"
  + "</div>",
});

Vue.component("Tab", {
  props: [ "file", "actions", "isSelected", "isTextUnsaved", "index" ],
  methods: {
    closeFile: function(e) {
      this.actions.closeFile(this.index);
      
      e.stopPropagation();
    },
    selectFile: function(e) {
      this.actions.selectFile(this.index);
    },
  },
  template:
    "<div v-on:click='selectFile' :class='[\"tabs-tab\", "
    +       "{ \"tabs-tab-selected\": isSelected && !isTextUnsaved, \"tabs-tab-unsaved\": isSelected && isTextUnsaved }]'>"
    + "{{file.name}}"
    + "<img class='tab-close-icon' src='/img/close-icon.png' v-on:click='closeFile' />"
  + "</div>",
});

Vue.component("TextArea", {
  props: [ "text", "actions" ],
  data: function() {
    return {
      textarea: this.text,
    };
  },
  watch: {
    text: function(newVal) {
      this.textarea = this.text;
    },
  },
  methods: {
    setText: function(e) {
      this.actions.setText(e.target.value);
    },
    saveFile: function(e) {
      e.preventDefault();
      
      this.actions.saveFile();
    },
  },
  template:
    "<div class='tabs-textarea-container'>"
    + "<textarea class='tabs-textarea' v-model='textarea' placeholder='(empty file)'"
    +       "v-on:input='setText' v-on:keydown.d.ctrl.exact.prevent='saveFile' />"
  + "</div>",
});

Vue.component("DialogSaveChanges", {
  props: [ "actions" ],
  template:
    "<Dialog :actions='{ cancelDialog: actions.cancelAction }' >"
    + "<h3>Save changes?</h3>"
    + "<input type='submit' value='Save file' v-on:click='actions.saveFile' /> "
    + "<input type='submit' value='Discard changes' v-on:click='actions.discardFile' /> "
    + "<input type='submit' value='Cancel' v-on:click='actions.cancelAction' />"
  + "</Dialog>"
});
