// from server: 66% by atomic.potato
struct S
{
    int f();
    void *p;
};

int S::f()
{
    struct V
    {
        int (*fn)(V *);
        int pad[71];
        int value;
    };

    V *p = (V *)((char *)this->p + 0x120);
    int r = p->fn(p);
    return *(int *)((char *)r + 0x144) == 0;
}
