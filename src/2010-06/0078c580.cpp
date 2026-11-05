// from server: 29% by atomic.potato
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

struct SpatialFilter
{
    char pad0[8];
    S_func_007637e0* m_x;
    void f(S_func_007637e0* a1);
};

void SpatialFilter::f(S_func_007637e0* a1)
{
    a1->f((int)this);
    m_x->f((int)a1);
}
