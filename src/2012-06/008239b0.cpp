// from server: 59% by atomic.potato
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

struct SurfaceGetSet
{
    int m_pad0;
    int m_pad1;
    int (*m_call)(float, int);
    void f(void*, float*);
};

void SurfaceGetSet::f(void* p, float* value)
{
    S_func_00750a60* s;
    if (p)
        s = (S_func_00750a60*)((char*)p - 28);
    else
        s = 0;

    int* x = s->f();
    m_call(*value, (int)(x + 8));
}
