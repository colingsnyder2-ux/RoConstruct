// from server: 65% by atomic.potato
struct S_func_00636ea0
{
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_00636ea0::f()
{
    return &m_x;
}

struct SurfaceGetSet
{
    char pad0[8];
    int m_callback;
    void f(int* object, float* value);
};

void SurfaceGetSet::f(int* object, float* value)
{
    S_func_00636ea0* p;
    if (object)
        p = (S_func_00636ea0*)((char*)object - 28);
    else
        p = 0;

    p->f();

    typedef void (__thiscall *Callback)(int*, float);
    Callback callback = (Callback)m_callback;
    callback((int*)((char*)p->f() + 40), *value);
}
