// from server: 46% by atomic.potato
struct S_func_0052f670
{
    int m_x;
    int f();
};

int S_func_0052f670::f()
{
    return m_x;
}

struct S
{
    int f(S_func_0052f670*);
};

int S::f(S_func_0052f670* p)
{
    return p->f();
}
