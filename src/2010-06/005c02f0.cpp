// from server: 60% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[4];
    volatile long ref1;
    volatile long ref2;
    virtual void v0();
    virtual void v1();
};

struct Outer {
    char pad0[4];
    Inner* p;
};

struct Holder {
    char pad0[4];
    Outer* out;
};

extern Holder* __cdecl getHolder(Holder*);

struct Result {
    Inner* a;
    Inner* b;
};

struct S {
    Result* f(Result* out);
};

Result* S::f(Result* out) {
    Holder h;
    h.out = 0;
    Holder* ph = getHolder(&h);
    Inner* inner = ph->out ? (Inner*)((char*)ph->out + 0x18) : 0;
    out->a = inner;
    Inner* b = ph->out->p;
    out->b = b;
    if (b) {
        _InterlockedExchangeAdd(&b->ref1, 1);
    }
    Inner* esi = (Inner*)h.out;
    if (esi) {
        if (_InterlockedExchangeAdd(&esi->ref1, -1) == 1) {
            esi->v0();
            if (_InterlockedExchangeAdd(&esi->ref2, -1) == 1) {
                esi->v1();
            }
        }
    }
    return out;
}
