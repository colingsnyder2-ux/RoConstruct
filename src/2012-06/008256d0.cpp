// from server: 39% by atomic.potato
struct S_func_00750a60 {
    char pad0[436];
    int m_x;
    int* f();
};

int* S_func_00750a60::f()
{
    return &m_x;
}

extern "C" int* __cdecl func_00750a60();
extern "C" void __cdecl func_00822df0(int*, int, int);

struct SurfaceDescriptor {
    void f(void*, int, int);
};

void SurfaceDescriptor::f(void* p, int a, int b)
{
    int* x;
    if (p)
        x = (int*)p - 7;
    else
        x = 0;
    x = func_00750a60();
    x[2];
    func_00822df0(x + 2, a, b);
}
