// from server: 45% by atomic.potato
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
    int m_pad4;
    int (__thiscall *m_func)(int*, float);
    int surface(float* value);
};

int SurfaceGetSet::surface(float* value)
{
    S_func_00750a60* p = (S_func_00750a60*)value;
    int* x = p ? p->f() : 0;
    return m_func((int*)this, *value);
}
