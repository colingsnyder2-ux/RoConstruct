// from server: 66% by atomic.potato
struct S_func_007637e0 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_007637e0::f(int a1)
{
    m_x = (int)a1;
}

struct S {
    void f(int a1);
    void (**vftable)();
};

S_func_007637e0 g;

void S::f(int a1)
{
    g.f(a1);
    vftable[13]();
}
