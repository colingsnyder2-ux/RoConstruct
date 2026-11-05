// from server: 37% by atomic.potato
struct S_func_007b2f20
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_007b2f20::f(int a1)
{
    m_x = a1;
}

struct S
{
    int f(int a1);
    char pad0[8];
    int *m_ptr;
};

int S::f(int a1)
{
    S_func_007b2f20 *p = (S_func_007b2f20 *)this;
    p->f(a1);
    return m_ptr[3];
}
