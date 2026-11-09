// from server: 42% by atomic.potato
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

struct SurfaceGetSet
{
    int m_pad0[2];
    int m_callback;
    int set(float value);
};

int SurfaceGetSet::set(float value)
{
    S_func_006cb2b0* p;
    if (m_callback)
        p = (S_func_006cb2b0*)((char*)m_callback - 28);
    else
        p = 0;
    int* q = p->f();
    int (**vtable)(int*, float) = (int (**)(int*, float))((char*)q + 32);
    return (*vtable)(q, value);
}
