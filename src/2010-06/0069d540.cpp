// from server: 43% by atomic.potato
struct S_func_00636ea0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_00636ea0::f()
{
    return &m_x;
}

struct S {
    int m_pad0[2];
    int (*m_func)(int);
    int f(S_func_00636ea0* a, int* b);
};

int S::f(S_func_00636ea0* a, int* b)
{
    int* p = a ? a->f() : 0;
    return m_func(*b);
}
