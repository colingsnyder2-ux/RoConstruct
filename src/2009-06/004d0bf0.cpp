// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Settings { char pad[0x2f19]; bool flag; };
Settings* getSettings();
bool getFlag() { Settings* s = getSettings(); return s ? s->flag : false; }
