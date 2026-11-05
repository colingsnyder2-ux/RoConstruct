// from server: 29% by atomic.potato
struct S_func_008c62c0 {
    char pad0[32];
    int m_x;
    int f();
};

int S_func_008c62c0::f()
{
    return m_x;
}

struct S {
    int f();
};

int S::f()
{
    S_func_008c62c0 *p = (S_func_008c62c0 *)((char *)this + 8);
    int x = p->f();
    if (x == 0)
        return 0;
    p = (S_func_008c62c0 *)x;
    x = p->f();
    if (x == 0)
        return 0;
    return x - 8;
}
