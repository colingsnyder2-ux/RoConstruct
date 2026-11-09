// from server: 100% by atomic.potato
struct S
{
    double f();
    int unused;
    double value;
    int count;
};

double S::f()
{
    if (count > 0)
        return value / count;
    return 0.0;
}
