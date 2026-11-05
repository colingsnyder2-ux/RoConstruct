// from server: 68% by atomic.potato
struct S_func_00636ea0
{
    char pad0[388];
    int m_x;
    int *f();
};

int *S_func_00636ea0::f()
{
    return &m_x;
}

extern "C" int *__cdecl call_00636ea0(int *);

extern "C" void __stdcall call_00718ba0(int *, int);

struct SurfaceDescriptor
{
    void f(void *, int, int);
};

void SurfaceDescriptor::f(void *p, int a, int b)
{
    int *x;
    if (p)
        x = (int *)((char *)p - 28);
    else
        x = 0;
    x = call_00636ea0(x);
    call_00718ba0(x + 2, b);
}
