// from server: 100% by atomic.potato
struct S
{
    char pad0[304];
    double c;
    char pad1[84];
    int a;
    int b;
    double f();
};

double S::f()
{
    int n = (b - a) >> 3;
    double x = (double)n;
    if (n < 0)
        x += 4294967296.0;
    return c / x;
}
