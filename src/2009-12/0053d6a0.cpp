// from server: 67% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    virtual void destroy();
    virtual void release();
    volatile long ref1;
    volatile long ref2;
};

void __stdcall sub_53D6A0(RefCounted* p, int) {
    if (p) {
        if (_InterlockedExchangeAdd(&p->ref1, -1) == 1) {
            p->destroy();
            if (_InterlockedExchangeAdd(&p->ref2, -1) == 1) {
                p->release();
            }
        }
    }
}
