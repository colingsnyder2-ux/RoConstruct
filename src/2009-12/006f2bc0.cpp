// from server: 31% by atomic.potato
struct S_func_006cb2b0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_006cb2b0::f()
{
    return &m_x;
}

extern "C" int* __cdecl call_006cb2b0();
extern "C" void __cdecl call_0071d610(int*, int, int);

struct SurfaceDescriptor {
    void* f(void*, int, int);
};

void* SurfaceDescriptor::f(void* p, int a, int b)
{
    int* x = p ? (int*)((char*)p - 28) : 0;
    int* y = call_006cb2b0();
    y += 2;
    call_0071d610(y, a, b);
    return y;
}
