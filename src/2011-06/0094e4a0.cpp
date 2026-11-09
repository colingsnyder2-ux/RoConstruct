// from server: 66% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    virtual void destroy();
    virtual void destroy2();
    volatile long ref1;
    volatile long ref2;
};

void __stdcall release(RefCounted* p, int, int, int, int, int, int) {
    if (p) {
        if (_InterlockedExchangeAdd(&p->ref1, -1) == 1) {
            p->destroy();
            if (_InterlockedExchangeAdd(&p->ref2, -1) == 1) {
                p->destroy2();
            }
        }
    }
}
