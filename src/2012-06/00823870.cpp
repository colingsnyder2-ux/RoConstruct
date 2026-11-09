// from server: 38% by atomic.potato
struct S_func_00750a60
{
    char pad0[436];
    int m_x;
    int* f();
};

int* S_func_00750a60::f()
{
    return &m_x;
}

struct SurfaceGetSet
{
    int m_pad0;
    int m_pad1;
    int (__thiscall *m_func)(int*, float);
    int f(int*, float*);
};

int SurfaceGetSet::f(int* p, float* value)
{
    S_func_00750a60* q = (S_func_00750a60*)p;
    int* x = q ? q->f() : 0;
    return m_func(x + 4, *value);
}
