// from server: 51% by atomic.potato
struct S_func_0066c140 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_0066c140::f()
{
    return &m_x;
}

struct SurfaceGetSet {
    int m_pad0;
    int m_pad1;
    int (__thiscall *m_call)(int, float);

    void f(int* p);
};

void SurfaceGetSet::f(int* p)
{
    S_func_0066c140 s;
    int* q = s.f();
    int* r = p ? p - 7 : 0;
    m_call((int)q, (float)*r);
}
