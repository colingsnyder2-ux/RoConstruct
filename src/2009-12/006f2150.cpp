// from server: 29% by atomic.potato
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
    int (*m_call)(int*, float);
    int method(int*);
};

int SurfaceGetSet::method(int* p)
{
    S_func_006cb2b0* q = (S_func_006cb2b0*)p;
    int* x = q ? q->f() : 0;
    return m_call(x, (float)*p);
}
