// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct A { int a; int n; void g(int, int); void h(int); };
void A::h(int x) { g(x, n); }
