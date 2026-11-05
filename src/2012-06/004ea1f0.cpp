// from server: 69% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S_func_004ea1f0 {
    int m_value;
    int m_pad;
    struct Ref {
        int m_vftable;
        int m_pad;
        volatile long m_refcount;
    };
    Ref* m_ref;
    void f();
};

void S_func_004ea1f0::f()
{
    m_value = 0xb69ee4;
    Ref* p = m_ref;
    if (p != 0 && _InterlockedExchangeAdd(&p->m_refcount, -1) == 1)
        ((void (__thiscall *)(Ref*))(*(int*)p + 8))(p);
}
