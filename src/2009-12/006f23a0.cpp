// from server: 26% by atomic.potato
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
    int m_dispatch;
    void* m_pad;
    int (__thiscall *m_call)(void*, int);
    int f(void*, int*);
};

int SurfaceGetSet::f(void* p, int* q)
{
    S_func_006cb2b0* s = (S_func_006cb2b0*)this;
    S_func_006cb2b0* t;

    if (p)
        t = (S_func_006cb2b0*)((char*)p - 0x1c);
    else
        t = 0;

    int* x = t->f();
    return m_call((char*)x + 0x20, *q);
}
