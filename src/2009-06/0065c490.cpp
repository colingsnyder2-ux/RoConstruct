// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Msg { void go(); };
struct P { virtual void f(int); char pad[0xa4]; Msg m; char pad2[0x1d8-0xa8-sizeof(Msg)]; bool a; char p3[0x13]; bool b; };
void P::f(int) { a = true; b = false; m.go(); }
