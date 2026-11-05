// from server: 48% by atomic.potato
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
    int m_pad0;
    int m_pad1;
    int (*m_call)(int*, float);
    int f(int*, float*);
};

int S::f(int* p, float* q)
{
    S_func_00636ea0* x = (S_func_00636ea0*)p;
    int* y = x ? x->f() : 0;
    return m_call(y + 4, *q);
}
