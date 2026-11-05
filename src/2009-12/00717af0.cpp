// from server: 5% by atomic.potato
struct S_func_007733f0 {
    char pad0[52];
    int m_x;
    int f();
};

int S_func_007733f0::f()
{
    return m_x;
}

struct S_func_00717af0 {
    int f();
};

int S_func_00717af0::f()
{
    S_func_007733f0 *p = (S_func_007733f0 *)this;
    int x = p->f();
    if (x)
        return 0;
    return 0;
}
