// from server: 75% by atomic.potato
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

extern "C" int* __cdecl f_0066c140(int*);

struct SurfaceGetSet
{
    int pad0;
    int pad1;
    int (__thiscall *m_call)(void*, float);
    int f(void*, float*);
};

int SurfaceGetSet::f(void* p, float* value)
{
    int* x;
    if (p)
        x = (int*)((char*)p - 28);
    else
        x = 0;
    x = f_0066c140(x);
    return m_call((char*)x + 32, *value);
}
