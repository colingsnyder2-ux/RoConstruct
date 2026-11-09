// from server: 63% by atomic.potato
struct S_func_006cb2b0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_006cb2b0::f()
{
    return &m_x;
}

extern "C" int* call_006cb2b0(S_func_006cb2b0*);

extern "C" void call_0071d610(int*, int, int);

struct SurfaceDescriptor {
    void* f(void*, int, int);
};

void* SurfaceDescriptor::f(void* p, int a, int b)
{
    int* x;
    if (p)
        x = (int*)((char*)p - 28);
    else
        x = 0;
    x = call_006cb2b0((S_func_006cb2b0*)x);
    call_0071d610(x + 6, a, b);
    return x + 6;
}
