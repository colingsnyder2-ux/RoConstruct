// from server: 46% by atomic.potato
struct S
{
    int f(int);
};

int S::f(int arg)
{
    struct V
    {
        int (**table)(V *, int);
    };

    V *p = *(V **)((char *)this + 0x10);
    int value = *(int *)((char *)this + 0x18);
    return p->table[4](p, value);
}
