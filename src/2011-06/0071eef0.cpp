// from server: 36% by atomic.potato
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
    int* (__thiscall *m_func)(int*);
    int m_padding;
    int (__thiscall *m_call)(int*, int*);
    int f(int*, int*);
};

int* S_func_0066c140::*unused;

int SurfaceGetSet::f(int* value, int* other)
{
    S_func_0066c140* p;
    int* result;

    if (value)
        p = (S_func_0066c140*)((char*)value - 28);
    else
        p = 0;

    result = p->f();
    return m_call((int*)result, other);
}
