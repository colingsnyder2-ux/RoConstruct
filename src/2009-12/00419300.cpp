// from server: 80% by atomic.potato
struct S
{
    int f(void *, void *, void *);
};

int S::f(void *a, void *, void *b)
{
    struct V
    {
        int (**table)();
    };

    V *p = *(V **)((char *)a - 0xcc);
    p = *(V **)((char *)p + 0x20);
    return ((int (__thiscall *)(void *, void *))p->table[0x1d0 / 4])(p, b);
}
