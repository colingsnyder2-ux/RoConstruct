// from server: 45% by atomic.potato
struct S_func_007b2f20
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_007b2f20::f(int a1)
{
    m_x = (int)a1;
}

extern "C" void __cdecl sub_007b8f00(void *, int);

struct S
{
    char pad0[8];
    void *m_x;
    void f(int a1);
};

void S::f(int a1)
{
    S_func_007b2f20 *p = (S_func_007b2f20 *)a1;
    p->f((int)this);
    sub_007b8f00(m_x, a1);
}
