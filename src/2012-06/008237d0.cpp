// from server: 38% by atomic.potato
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
    int pad0;
    int pad4;
    int (__thiscall *m_set)(int*, float);
    int f(int*, float*);
};

int SurfaceGetSet::f(int* p, float* value)
{
    S_func_00750a60* s = (S_func_00750a60*)p;
    int* x = s ? s->f() : 0;
    return m_set(x + 2, *value);
}
