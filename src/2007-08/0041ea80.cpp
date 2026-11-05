// from server: 28% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    virtual void onZeroRefs();
    virtual void onFinalRelease();
    volatile long refCount;
    volatile long weakCount;
};

struct Sub1 {
    virtual void v1();
};

struct Sub2 {
    virtual void v2();
};

struct Sub3 {
    virtual void v3();
};

struct Holder {
    char pad[0x308];
    RefCounted* ptr;
};

struct Outer {
    void cleanup();
};

void __stdcall helper1();
void __stdcall helper2();
void __stdcall helper3();
void __stdcall helper4();

void Outer::cleanup()
{
    helper1();

    Holder* h = (Holder*)this;
    RefCounted* p = h->ptr;
    if (p) {
        if (_InterlockedExchangeAdd(&p->refCount, -1) == 1) {
            p->onZeroRefs();
            if (_InterlockedExchangeAdd(&p->weakCount, -1) == 1) {
                p->onFinalRelease();
            }
        }
    }

    ((Sub1*)this)->v1();
    ((Sub2*)this)->v2();
    ((Sub3*)this)->v3();
    helper4();
}
