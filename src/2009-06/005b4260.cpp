// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct S { int a; int b; void g(int p, int x); void f(int x); };
void S::f(int x) { g(b, x); }
