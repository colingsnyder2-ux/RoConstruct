// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT /EHsc
struct E { int a, b; };
int h(int n, struct H* y, int x);
struct H { H* p; int pad; E* cur; H* get(); int m1(); void f(const H& o); };
void H::f(const H& o) { h(cur - o.cur, get()->get(), get()->m1()); }
