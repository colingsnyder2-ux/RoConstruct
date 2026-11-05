// from server: 38% by atomic.potato
struct S_func_006cb2b0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_006cb2b0::f()
{
    return &m_x;
}

struct SurfaceGetSet {
    char pad0[8];
    int (__thiscall *m_callback)(int*, float);
    int f(int*, float*);
};

int SurfaceGetSet::f(int* a, float* b)
{
    S_func_006cb2b0* p = (S_func_006cb2b0*)a;
    int* q = p ? p->f() : 0;
    return m_callback(q + 6, *b);
}
