// from server: 22% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl func_975470(void*);
extern "C" void __cdecl func_70a780(void*, void*);

struct Inner {
    char pad0[4];
    volatile long refcount;
};

struct Outer {
    Inner* ptr;
    char pad4[4];
    double d;
    Outer(void*, void*, void*);
};

Outer::Outer(void* a, void* b, void* c) {
    Inner* p = (Inner*)operator_new(0x18);
    if (p) {
        func_70a780(p, c);
    } else {
        p = 0;
    }
    ptr = p;
    if (p) {
        _InterlockedExchangeAdd(&p->refcount, 1);
    }
    func_975470(&d);
    d = 0.0;
    d = d + *(double*)&b;
}
