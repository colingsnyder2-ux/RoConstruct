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

extern "C" int* __cdecl f_0066c140();

struct SurfaceGetSet
{
    int pad0;
    int pad1;
    int (__thiscall *m_function)(int*, float);
    void SurfaceSet(int*, float);
};

void SurfaceGetSet::SurfaceSet(int* value, float input)
{
    int* p = value ? value - 7 : 0;
    int* q = f_0066c140();
    m_function(q + 10, *value);
}
