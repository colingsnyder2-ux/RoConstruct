// from server: 63% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[4];
    volatile long ref1;
    volatile long ref2;
    virtual void vf1();
    virtual void vf2();
};

struct Holder {
    Inner* p;
    char pad[4];
};

struct Outer {
    char pad0[4];
    volatile long ref;
};

extern "C" Holder* __cdecl sub_5d6c60(Holder* out);

struct Result {
    Inner* a;
    Inner* b;
};

struct S {
    Result* f(Result* out);
};

Result* S::f(Result* out) {
    Holder h;
    h.p = 0;
    Holder* r = sub_5d6c60(&h);
    Inner* p = r->p;
    Inner* v;
    if (p) {
        v = (Inner*)((char*)p + 0x18);
    } else {
        v = 0;
    }
    out->a = v;
    Inner* q = *(Inner**)((char*)r + 4);
    out->b = q;
    if (q) {
        _InterlockedExchangeAdd(&q->ref1, 1);
    }
    Inner* esi = h.p;
    if (esi) {
        if (_InterlockedExchangeAdd(&esi->ref1, -1) == 1) {
            esi->vf1();
            if (_InterlockedExchangeAdd(&esi->ref2, -1) == 1) {
                esi->vf2();
            }
        }
    }
    return out;
}
