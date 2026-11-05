// from server: 25% by atomic.potato
struct S_func_007637e0
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_007637e0::f(int a1)
{
    m_x = a1;
}

struct S
{
    char pad0[8];
    void *m_x;
    void f(int a1);
};

void S::f(int a1)
{
    S_func_007637e0 *p = (S_func_007637e0 *)a1;
    p->f((int)this);
    ((void (__thiscall *)(void *, void *))0x760c10)(m_x, p);
}
