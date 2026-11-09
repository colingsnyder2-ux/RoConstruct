// from server: 41% by atomic.potato
struct S_func_004cc450
{
    char pad0[2120];
    int m_x;
    int f();
};

int S_func_004cc450::f()
{
    return m_x;
}

struct S
{
    char pad0[4];
    int m_pad0;
    int f();
};

int S::f()
{
    if (m_pad0 != 0)
    {
        S_func_004cc450 *p = *(S_func_004cc450 **)((char *)this - 84);
        int v = p->f();
        return v;
    }
    return 0;
}
