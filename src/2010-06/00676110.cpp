// from server: 39% by atomic.potato
struct S_func_007d2540 {
    char pad0[32];
    int m_x;
    int f();
};

int S_func_007d2540::f()
{
    return m_x;
}

struct S {
    int f();
};

int S::f()
{
    S_func_007d2540 *p = (S_func_007d2540 *)((char *)this + 8);
    int *q = (int *)p->f();
    if (q != 0)
        return ((S_func_007d2540 *)q)->f() - 8;
    return 0;
}
