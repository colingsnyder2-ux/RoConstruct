// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
int g(int x, int y);
struct S { int pad; int n; int m(int a); int f(int a); };
int S::f(int a) { return g(m(a), n); }
