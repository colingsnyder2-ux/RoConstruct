// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct M { int g(); };
int f(int);
struct A { int a, b; M m; void h(); };
void A::h() { f(m.g()); }
