// from server: 32% by atomic.potato
struct S_func_00750a60
{
    char pad0[436];
    int m_x;
    int* f();
};

int* S_func_00750a60::f()
{
    return &m_x;
}

struct SurfaceDescriptor
{
    int f(int*, int*, int*);
};

int SurfaceDescriptor::f(int* a, int* b, int* c)
{
    S_func_00750a60* p = (S_func_00750a60*)a;
    int* q = p ? p->f() : 0;
    q += 4;
    return ((int*)q)[0] = b[0];
}
