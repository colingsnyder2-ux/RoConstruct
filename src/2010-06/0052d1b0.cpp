// from server: 72% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S_func_0052d1b0
{
    void (**m_vtable)();
    char pad4[4];
    struct Ref
    {
        void (**m_vtable)();
        char pad4[4];
        volatile long m_refs;
    } *m_ref;

    void f();
};

void S_func_0052d1b0::f()
{
    m_vtable = (void (**)())0x00a1ee40;
    Ref *p = m_ref;
    if (p != 0)
    {
        if (_InterlockedExchangeAdd(&p->m_refs, -1) == 1)
            p->m_vtable[2]();
    }
}
