// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct X { void g(); };
struct Sub { void f(int a, X* b); };
struct H { char pad[0x19c]; Sub s; void m(int a, X* b); };
void H::m(int a, X* b) { s.f(a, b); if (b) b->g(); }
