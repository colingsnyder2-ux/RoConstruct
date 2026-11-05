// from server: 60% by atomic.potato
struct S_func_008de100
{
    char pad0[36];
    int m_x;
    int f();
};

int S_func_008de100::f()
{
    return m_x;
}

int f(S_func_008de100 *);

int f(S_func_008de100 *p)
{
    S_func_008de100 *q = (S_func_008de100 *)((char *)p + 8);
    int r = f(q);
    if (r)
        return f((S_func_008de100 *)((char *)r - 8));
    return 0;
}
