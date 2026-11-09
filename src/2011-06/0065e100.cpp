// from server: 87% by atomic.potato
struct S
{
    int unused;
    int unused2;
    int offset;
    double get(double *value);
};

double S::get(double *value)
{
    if (value)
        return *(double *)((char *)value + offset - 28);
    return *(double *)((char *)0 + offset);
}
