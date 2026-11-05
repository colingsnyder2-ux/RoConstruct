// from server: 57% by atomic.potato
struct S
{
    double f();
    int count;
    double value;
};

double S::f()
{
    if (value <= 0.0)
        return 0.0;
    return (double)count / value;
}
