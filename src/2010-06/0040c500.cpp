// from server: 64% by atomic.potato
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
    Inner* p0;
    Inner* p1;
};

extern "C" Holder* __cdecl sub_40C150(Holder* out);

struct Result {
    Inner* a;
    Inner* b;
};

struct S {
    Result* __stdcall f(Result* out);
};

Result* __stdcall S::f(Result* out) {
    Holder h;
    h.p0 = 0;
    Holder* r = sub_40C150(&h);
    Inner* c = r->p0;
    if (c) {
        c = (Inner*)((char*)c + 0x18);
    } else {
        c = 0;
    }
    out->a = c;
    Inner* d = r->p1;
    out->b = d;
    if (d) {
        _InterlockedExchangeAdd(&d->ref1, 1);
    }
    Inner* e = h.p0;
    if (e) {
        if (_InterlockedExchangeAdd(&e->ref1, -1) == 1) {
            e->v1();
            if (_InterlockedExchangeAdd(&e->ref2, -1) == 1) {
                e->v2();
            }
        }
    }
    return out;
}
