// from server: 57% by atomic.potato
struct S_func_006cb2b0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_006cb2b0::f()
{
    return &m_x;
}

extern "C" void call_0071d610(int*, int, int);

struct SurfaceDescriptor {
    void f(void*, int, int);
};

void SurfaceDescriptor::f(void* p, int a, int b)
{
    S_func_006cb2b0* q = (S_func_006cb2b0*)p;
    int* x = q ? q->f() : 0;
    call_0071d610(x + 4, a, b);
}
