// from server: 40% by atomic.potato
struct S
{
    int f(void *, void *);
};

int S::f(void *a, void *b)
{
    *(int *)((char *)this + 0x2eb0470) = 0;
    void *p = *(void **)b;
    *(void **)b = 0;
    if (p)
    {
        void **v = *(void ***)p;
        ((void (__thiscall *)(void *, int))*v)(p, 1);
    }
    return 0;
}
