// from server: 76% by atomic.potato
struct S_func_008d6a40 {
    struct VTable {
        void (__thiscall *f)(void *, int, float, float);
    };

    char pad0[16];
    int m_value;
    VTable **m_vtable;
    void __cdecl f(int, int, float, float);
};

void S_func_008d6a40::f(int a, int b, float c, float d)
{
    if (m_value != 0)
        (*m_vtable)->f(m_vtable, b, c, d);
}
