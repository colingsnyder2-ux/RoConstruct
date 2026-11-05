// from server: 77% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* p0;
    long ref;
};

struct Outer {
    Inner* p;
};

extern "C" Outer* __cdecl sub_6a4f20(void*);

struct S {
};

Outer* __cdecl f(void** out) {
    Outer* tmp = 0;
    Outer* r = sub_6a4f20(&tmp);
    Inner* in = r->p;
    *out = in;
    Inner* in2 = *(Inner**)((char*)r + 4);
    out[1] = in2;
    if (in2) {
        _InterlockedExchangeAdd(&in2->ref, 1);
    }
    return r;
}
