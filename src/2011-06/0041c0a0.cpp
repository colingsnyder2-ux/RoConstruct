// from server: 46% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* vptr;
    char pad[0x14];
};

struct RefObj {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
};

struct Holder {
    Inner* p;
    RefObj* q;
};

extern "C" void* __cdecl sub_41C020(void** out);

struct S {
    Holder* f(Holder* out);
};

Holder* S::f(Holder* out) {
    void* tmp = 0;
    sub_41C020(&tmp);
    Inner* ip = (Inner*)tmp;
    Inner* val;
    if (ip != 0) {
        val = (Inner*)((char*)ip + 0x18);
    } else {
        val = 0;
    }
    out->p = val;
    RefObj* r = *(RefObj**)((char*)ip + 4);
    out->q = r;
    if (r != 0) {
        _InterlockedExchangeAdd(&r->ref1, 1);
    }
    RefObj* old = (RefObj*)tmp;
    if (old != 0) {
        if (_InterlockedExchangeAdd(&old->ref1, -1) == 1) {
            void (*fn1)(RefObj*) = *(void (**)(RefObj*))(*(void***)old + 4);
            fn1(old);
            if (_InterlockedExchangeAdd(&old->ref2, -1) == 1) {
                void (*fn2)(RefObj*) = *(void (**)(RefObj*))(*(void***)old + 8);
                fn2(old);
            }
        }
    }
    return out;
}
