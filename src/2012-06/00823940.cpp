// from server: 44% by atomic.potato
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
    int (*m_function)(int);
    void f(int* a, int* b);
};

void SurfaceGetSet::f(int* a, int* b)
{
    int* p = a ? ((S_func_00750a60*)a)->f() : 0;
    int* q = p + 8;
    m_function(*b);
}
