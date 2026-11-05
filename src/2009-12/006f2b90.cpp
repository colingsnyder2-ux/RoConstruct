// from server: 13% by atomic.potato
struct S_func_006cb2b0
{
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_006cb2b0::f()
{
    return &m_x;
}

struct SurfaceDescriptor
{
    int* f(int*, int*);
};

int* SurfaceDescriptor::f(int* a, int* b)
{
    S_func_006cb2b0* p = (S_func_006cb2b0*)a;
    int* q = p ? p->f() : 0;
    return ((SurfaceDescriptor*)q)->f(b, (int*)this);
}
