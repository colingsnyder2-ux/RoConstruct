// from server: 67% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    virtual void onZeroRefs1();
    virtual void onZeroRefs2();
    volatile long ref1;
    volatile long ref2;
};

void __stdcall release(RefCounted* p, int, int, int, int, int)
{
    if (p) {
        if (_InterlockedExchangeAdd(&p->ref1, -1) == 1) {
            p->onZeroRefs1();
            if (_InterlockedExchangeAdd(&p->ref2, -1) == 1) {
                p->onZeroRefs2();
            }
        }
    }
}
