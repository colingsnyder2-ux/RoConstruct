// from server: 30% by atomic.potato
struct S_func_007637e0 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_007637e0::f(int a1)
{
    m_x = a1;
}

struct S {
    char pad0[8];
    S_func_007637e0 *m_stage;
    void f(int a1);
};

void S::f(int a1)
{
    S_func_007637e0 *p = (S_func_007637e0 *)this;
    p->f(a1);
    m_stage->f(a1);
}
