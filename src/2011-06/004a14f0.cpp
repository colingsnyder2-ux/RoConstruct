// from server: 81% by atomic.potato
struct CVideoStream
{
    char pad0[24];
    void *m_stream;
    int f();
};

int CVideoStream::f()
{
    if (m_stream == 0)
        return 0x80040209;

    struct VTable
    {
        char pad0[64];
        void (__thiscall *f)(void *);
    };

    VTable *vtable = *(VTable **)m_stream;
    vtable->f(m_stream);
    return 0;
}
