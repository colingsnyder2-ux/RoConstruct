// from server: 80% by atomic.potato
struct S
{
    double f(double* p);
    int unused;
    int offset;
};

double S::f(double* p)
{
    if (p)
        return *(double*)((char*)p + offset - 0x1c);
    return *(double*)((char*)0 + offset);
}
