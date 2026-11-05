// from server: 28% by atomic.potato
struct S_func_004e9330 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_004e9330::f(int a1)
{
    m_x = a1;
}

struct S_func_007b41b0 {
    void f(S_func_004e9330 *a1);
};

struct S_func_007efbe0 {
    char pad0[8];
    S_func_007b41b0 *m_x;
    void f(S_func_004e9330 *a1);
};

void S_func_007efbe0::f(S_func_004e9330 *a1)
{
    a1->f((int)this);
    m_x->f(a1);
}
