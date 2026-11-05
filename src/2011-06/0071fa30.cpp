// from server: 35% by atomic.potato
struct S_func_0066c140 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_0066c140::f()
{
    return &m_x;
}

struct SurfaceDescriptor {
    void* f(void*, int, int);
};

void* SurfaceDescriptor::f(void* p, int a, int b)
{
    S_func_0066c140* q;
    if (p)
        q = (S_func_0066c140*)((char*)p - 28);
    else
        q = 0;
    int* x = q->f();
    return (void*)(((char*)x) + 40);
}
