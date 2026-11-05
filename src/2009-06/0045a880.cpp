// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct R { double v; bool b; };
struct S { R g(const double& a, double b); R f(const double& a); };
R S::f(const double& a) { return g(a, 60.0); }
