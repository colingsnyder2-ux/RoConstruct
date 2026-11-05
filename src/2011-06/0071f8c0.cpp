// from server: 13% by atomic.potato
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

struct S_func_0075ece0
{
    void g(int*, int);
};

void S_func_0075ece0::g(int*, int)
{
}

struct SurfaceDescriptor
{
    void f(void*, int, int);
};

void SurfaceDescriptor::f(void* p, int a, int b)
{
    S_func_0066c140* q = (S_func_0066c140*)((char*)p - 28);
    if (!p)
        q = 0;
    int* x = q->f();
    S_func_0075ece0* y = (S_func_0075ece0*)x;
    y->g(&a, b);
}
