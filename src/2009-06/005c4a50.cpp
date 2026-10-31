// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct M { void g(int x); };
struct S { int a, b; M m; int f(int x); };
int S::f(int x) { m.g(x); return x; }
