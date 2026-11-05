// from server: 78% by atomic.potato
struct S_func_004a14d0
{
    char pad0[24];
    void *m_stream;
    int f();
};

int S_func_004a14d0::f()
{
    if (m_stream == 0)
        return (int)0x80040209;

    struct VTable
    {
        void *entries[16];
    };

    VTable *vtable = *(VTable **)m_stream;
    typedef int (__thiscall *Callback)(void *);
    return ((Callback)vtable->entries[15])(m_stream);
}
