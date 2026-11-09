// from server: 75% by atomic.potato
struct S_func_00636ea0
{
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_00636ea0::f()
{
    return &m_x;
}

extern "C" int* __cdecl f_00636ea0(int*);

struct SurfaceGetSet
{
    int pad0;
    int pad1;
    int (__thiscall *m_callback)(void*, float);
    void f(void*, float*);
};

void SurfaceGetSet::f(void* surface, float* value)
{
    int* p = surface ? (int*)surface - 7 : 0;
    int* result = f_00636ea0(p);
    m_callback((void*)(result + 2), *value);
}
