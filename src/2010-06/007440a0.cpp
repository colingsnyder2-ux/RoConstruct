// from server: 55% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    volatile long m_ref1;
    volatile long m_ref2;
};

void release(RefCounted* p)
{
    if (p) {
        if (_InterlockedExchangeAdd(&p->m_ref1, -1) == 1) {
            p->f1();
            if (_InterlockedExchangeAdd(&p->m_ref2, -1) == 1)
                p->f2();
        }
    }
}

void __stdcall f_007440a0(RefCounted* a, RefCounted* b, int, int, int)
{
    release(a);
    release(b);
}
