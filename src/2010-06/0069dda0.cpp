// from server: 57% by atomic.potato
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

extern "C" void __cdecl f_00636ea0();
extern "C" void __cdecl f_00718ba0(int*, int, int);

struct SurfaceDescriptor
{
    void f(void*, int, int);
};

void SurfaceDescriptor::f(void* p, int a, int b)
{
    S_func_00636ea0* x = (S_func_00636ea0*)p;
    int* y = x ? x->f() : 0;
    f_00718ba0(y + 8, a, b);
}
