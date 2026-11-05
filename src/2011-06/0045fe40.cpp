// from server: 30% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[8];
    volatile long refcount;
};

struct Outer {
    char pad0[4];
    Inner* ptr;
};

struct Holder {
    Outer* p0;
    Outer* p1;
};

struct S {
    void* field0;
    char pad1[4];
    Outer* field8;
    void* ctor(void* a, void* b);
};

void* S::ctor(void* a, void* b)
{
    Inner* esi = (Inner*)b;
    Outer* ebx = (Outer*)this;
    Outer* ebp = (Outer*)((char*)this + 4);
    ebx->ptr = esi;
    ((Holder*)ebp)->p0 = (Outer*)a;
    ((Holder*)ebp)->p1 = (Outer*)b;
    if (esi != 0) {
        Holder* edi = (Holder*)((char*)esi + 0x2c);
        if (edi != 0) {
            edi->p0 = (Outer*)esi;
            Inner* esi2 = (Inner*)ebp->ptr;
            if (esi2 != (Inner*)edi->p1) {
                if (esi2 != 0) {
                    _InterlockedExchangeAdd(&esi2->refcount, 1);
                }
                Inner* ecx = (Inner*)edi->p1;
                if (ecx != 0) {
                    if (_InterlockedExchangeAdd(&ecx->refcount, -1) == 1) {
                        void** vt = *(void***)ecx;
                        void (*fn)(void*) = (void (*)(void*))vt[2];
                        fn(ecx);
                    }
                }
                edi->p1 = (Outer*)esi2;
            }
        }
    }

    return this;
}
