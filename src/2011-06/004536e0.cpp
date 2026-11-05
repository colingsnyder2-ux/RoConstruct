// from server: 32% by atomic.potato
struct S
{
    int f(void **a, void **b);
};

int S::f(void **a, void **b)
{
    void **p = b;
    void *q = 0;

    if (a != p)
    {
        q = *p;
        *p = 0;
    }

    if (q)
    {
        void **vtable = *(void ***)q;
        typedef void (__thiscall *Fn)(void *, int);
        Fn fn = (Fn)vtable[0];
        fn(q, 1);
    }

    return 0;
}
