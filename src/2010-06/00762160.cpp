// from server: 27% by atomic.potato
struct S_func_007637e0
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_007637e0::f(int a1)
{
    m_x = (int)a1;
}

struct S
{
    void f(int a1);
};

void S::f(int a1)
{
    S_func_007637e0 *p = (S_func_007637e0 *)this;
    p->f(a1);
    ((S_func_007637e0 *)((char *)this + 8))->f(a1);
}
