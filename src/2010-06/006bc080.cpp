// from server: 55% by atomic.potato
struct S
{
    char pad[12];
    struct T
    {
        void **vtable;
    };
    T *p;
    T *f(double a, double b, void *c, void *d, T *e);
};

S::T *S::f(double a, double b, void *c, void *d, T *e)
{
    return ((S::T *(__thiscall *)(S::T *, T *, void *, void *, double, double))
        p->vtable[11])(p, e, d, c, b, a);
}
