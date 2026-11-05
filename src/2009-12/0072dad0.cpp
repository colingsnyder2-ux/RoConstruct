// from server: 80% by atomic.potato
struct S
{
    double f(double* p);
    int pad;
    int value;
};

double S::f(double* p)
{
    if (p)
        return *(double*)((char*)p + value - 28);
    return *(double*)value;
}
