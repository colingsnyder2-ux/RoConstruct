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
    Inner* q;
    char pad[4];
};

extern Holder* __cdecl getHolder(Holder* out);

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
    Holder* r = getHolder(&h);
    Inner* p = r->p;
    if (p) {
        p = (Inner*)((char*)p + 0x18);
    } else {
        p = 0;
    }
    out->a = p;
    Inner* q = r->q;
    out->b = q;
    if (q) {
        _InterlockedExchangeAdd(&q->ref1, 1);
    }
    Inner* old = h.p;
    if (old) {
        if (_InterlockedExchangeAdd(&old->ref1, -1) == 1) {
            old->vf1();
            if (_InterlockedExchangeAdd(&old->ref2, -1) == 1) {
                old->vf2();
            }
        }
    }
    return out;
}
