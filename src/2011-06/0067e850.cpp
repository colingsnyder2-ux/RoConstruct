// from server: 93% by atomic.potato
struct S_func_0067e850
{
    char pad0[604];
    int m_flag;
    void *m_object;
    char f();
};

char S_func_0067e850::f()
{
    if (m_flag != 0)
    {
        struct VTable
        {
            char pad0[44];
            int (__thiscall *f)(void *);
        };

        VTable *vtable = *(VTable **)m_object;
        return vtable->f(m_object) == 13;
    }
    return 1;
}
