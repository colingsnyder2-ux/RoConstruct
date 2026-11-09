// from server: 74% by atomic.potato
struct S
{
    void f();
    void *p0;
    void *p1;
    void *p2;
};

void S::f()
{
    void **p;
    void *q;

    p = (void **)p1;
    if (p != 0)
    {
        q = *p;
        if (q != 0)
        {
            typedef void (__thiscall *F)(void *, void *, int);
            ((F)q)(p2, p2, 2);
        }
        p1 = 0;
    }
}
