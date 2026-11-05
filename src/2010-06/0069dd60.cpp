// from server: 57% by atomic.potato
struct S_func_00636ea0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_00636ea0::f()
{
    return &m_x;
}

extern "C" int* f_00718ba0(int*, int, int);

struct SurfaceDescriptor {
    void f(void*, int, int);
};

void SurfaceDescriptor::f(void* p, int a, int b)
{
    S_func_00636ea0* q;
    if (p)
        q = (S_func_00636ea0*)((char*)p - 28);
    else
        q = 0;
    int* r = q->f();
    f_00718ba0(r + 6, a, b);
}
