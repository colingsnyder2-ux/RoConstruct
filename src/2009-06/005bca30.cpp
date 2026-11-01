// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct M { double eval(int i); };
double diff(const double& a, const double& b);
struct C {
    int pad;
    M m;
    const double& at(int i);
    double f(int i);
};
double C::f(int i) { return diff(at(i), m.eval(i)); }
