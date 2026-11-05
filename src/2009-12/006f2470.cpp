// from server: 52% by atomic.potato
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
    int m_0;
    int m_4;
    int (*m_set)(int*, float);

    int f(int* p, float* value);
};

int SurfaceGetSet::f(int* p, float* value)
{
    S_func_006cb2b0* base;
    int* result;

    if (p)
        base = (S_func_006cb2b0*)((char*)p - 28);
    else
        base = 0;

    result = base->f();
    return m_set(result + 10, *value);
}
