// from server: 53% by atomic.potato
struct S_func_0066c140
{
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_0066c140::f()
{
    return &m_x;
}

struct SurfaceGetSet
{
    int m_unknown;
    int* m_callback;
    int f(int*, float*);
};

int SurfaceGetSet::f(int* a, float* b)
{
    S_func_0066c140* p = (S_func_0066c140*)a;
    int* q = p ? p->f() : 0;
    float value = *b;
    return ((int (__thiscall *)(int*, float))m_callback)(q + 6, value);
}
