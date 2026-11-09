// from server: 100% by atomic.potato
struct S_func_005751c0
{
    char pad0[8];
    struct VTable
    {
        int pad0[2];
        void (__thiscall *f)(void *, int, float);
    };
    VTable **m_vtable;
    void f(int a, float b);
};

void S_func_005751c0::f(int a, float b)
{
    m_vtable[0]->f(m_vtable, a, b);
}
