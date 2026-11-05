// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct S { char pad[0x3d]; bool flag; bool get(); };
bool S::get() { return flag; }
