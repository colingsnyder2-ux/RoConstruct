// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct B { B(); };
struct S : B { int v; S(int x); };
S::S(int x) { v = x; }
