// from server: 75% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S_func_00945970 {
    void* m_vftable;
    int m_value;
    struct Ref {
        void* m_vftable;
        long m_refcount;
    };
    Ref* m_ref;
    void f();
};

void S_func_00945970::f()
{
    m_vftable = (void*)0xaf6d4c;
    Ref* p = m_ref;
    if (p != 0 && _InterlockedExchangeAdd(&p->m_refcount, -1) == 1)
        ((void (__thiscall *)(Ref*))(*(void***)p)[2])(p);
}
