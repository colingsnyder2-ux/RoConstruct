// from server: 43% by atomic.potato
struct S
{
    double f();
};

extern "C" double *fn(void *, int, void *);

double S::f()
{
    int x;
    fn((char *)this + 0xa8, -1, &x);
    return *(double *)((char *)fn((char *)this + 0xa8, -1, &x) + 8);
}
