// from server: 46% by atomic.potato
struct S
{
    int f(int, int);
    void *p;
};

int S::f(int value, int unused)
{
    struct V
    {
        int (**call)(void *, int, int);
    };

    V *v = (V *)((char *)p);
    int (**table)(void *, int, int) = v->call;
    table[2](v, value, 0);
    return value;
}
