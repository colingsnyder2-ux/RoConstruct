// from server: 43% by atomic.potato
struct S_func_00750a60 {
    char pad0[436];
    int m_x;
    int* f();
};

int* S_func_00750a60::f()
{
    return &m_x;
}

struct SurfaceGetSet {
    int m_pad0;
    int m_pad1;
    int (*m_call)(int);
    int f(int* a, int* b);
};

int SurfaceGetSet::f(int* a, int* b)
{
    int* p = a ? a - 7 : 0;
    S_func_00750a60* q = reinterpret_cast<S_func_00750a60*>(this);
    int* r = q->f();
    return m_call(*b);
}
