// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
double g(const double* p);
struct S { const double* m(int b, int a); double f(int a, int b); };
double S::f(int a, int b) { return g(m(b, a)); }
