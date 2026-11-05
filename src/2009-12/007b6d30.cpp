// from server: 76% by atomic.potato
struct S
{
    int f(void *);
};

int S::f(void *p)
{
    void **a = (void **)p;
    void *b = a[4];
    if (b)
    {
        void *c = a[5];
        if (c && b != c)
        {
            void **d = *(void ***)((char *)this + 8);
            ((void (__thiscall *)(void *, void *))d[3])(d, p);
        }
    }
    return 0;
}
