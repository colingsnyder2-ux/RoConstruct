// from server: 44% by atomic.potato
struct S
{
    double f();
};

double S::f()
{
    return *(const double *)((const char *)this + 0x1b0);
}
