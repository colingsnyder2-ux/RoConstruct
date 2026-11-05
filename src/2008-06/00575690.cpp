// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct S {
    char padding[0x1c0];
    float rate;
    double first;
    double second;
    double third;

    double f();
};

inline const double& maximum(const double& a, const double& b)
{
    return a < b ? b : a;
}

double S::f()
{
    return maximum(0.0, 1.0 - (third + second + first) * (1.0 / rate)) * 100.0;
}
