// from server: 100% by atomic.potato
struct S
{
    int f(void *, void *);
    void *a[78];
};

int S::f(void *p, void *q)
{
    struct V
    {
        void *v;
    };

    V *x = p ? (V *)((char *)p + 28) : 0;
    void *t = a[78];
    t = *(void **)((char *)t + 28);

    typedef int (__thiscall *F)(void *, V *, void *);
    return ((F)(*(void ***)t)[4])(t, x, q);
}
