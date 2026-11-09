// from server: 51% by atomic.potato
struct S
{
    int f(float *);
    int *a;
    int (*b)(int);
};

int S::f(float *p)
{
    int *q = p ? (int *)((char *)p - 28) : 0;
    return b(*((int *)q) + (int)*p);
}
