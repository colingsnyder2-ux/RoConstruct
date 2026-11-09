// from server: 60% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S_0048ee40
{
    void* m_vtable;
    int m_refCount;
    int m_control;
    void f();
};

void S_0048ee40::f()
{
    m_vtable = (void*)0x9b2eec;
    S_0048ee40* p = (S_0048ee40*)m_control;
    if (p != 0)
    {
        volatile long* count = (volatile long*)((char*)p + 8);
        if (_InterlockedExchangeAdd(count, -1) == 1)
        {
            void (**vtable)(void) = (void (**)(void))p->m_vtable;
            vtable[2]();
        }
    }
}
