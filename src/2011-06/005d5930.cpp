// from server: 17% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[4];
    volatile long ref1;
    volatile long ref2;
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

struct Holder {
    Inner* p;
    char pad0[4];
    volatile long ref;
    volatile long ref2;
    virtual void v1();
    virtual void v2();
};

struct Src {
    char pad0[4];
    Holder* h;
};

extern Src* __cdecl getSrc();

struct Result {
    Inner* a;
    Holder* b;
};

struct S {
    Result* f(Result* out);
};

Result* S::f(Result* out) {
    Src* s = getSrc();
    Inner* ip = 0;
    if (s->h) {
        ip = (Inner*)((char*)s->h + 0x18);
    }
    out->a = ip;
    Holder* hp = s->h;
    out->b = hp;
    if (hp) {
        _InterlockedExchangeAdd(&hp->ref, 1);
    }
    Holder* old = 0;
    if (old) {
        if (_InterlockedExchangeAdd(&old->ref, -1) == 1) {
            old->v1();
            if (_InterlockedExchangeAdd(&old->ref2, -1) == 1) {
                old->v2();
            }
        }
    }
    return out;
}
