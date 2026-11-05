// from server: 38% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[4];
    volatile long m_ref;
};

struct Sub {
    char pad0[4];
    Inner* m_ptr;
};

struct S_func_0052df50 {
    Sub* m_head;
    Sub m_sub;
    int f(Sub* p);
};

extern "C" void __stdcall sub_0052cd30(Sub* p);

int S_func_0052df50::f(Sub* p)
{
    m_head = p;
    sub_0052cd30(&m_sub);
    if (p != 0) {
        Sub* d = (Sub*)((char*)p + 4);
        if (d != 0) {
            d->m_ptr = (Inner*)p;
            Inner* old = m_sub.m_ptr;
            if (old != d->m_ptr) {
                if (old != 0) {
                    _InterlockedExchangeAdd(&old->m_ref, 1);
                }
                Inner* cur = d->m_ptr;
                if (cur != 0) {
                    if (_InterlockedExchangeAdd(&cur->m_ref, -1) == 1) {
                        void (**vt)(void) = *(void (***)(void))cur;
                        vt[2]();
                    }
                }
                d->m_ptr = old;
            }
        }
    }
    return (int)this;
}
