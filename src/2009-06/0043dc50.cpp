// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Child43 { int find(int a, bool b); };
struct S43 { char pad[0x8c]; Child43* child; int get(int a, bool b); };
int S43::get(int a, bool b) { if (child) return child->find(a, b); return 0; }
