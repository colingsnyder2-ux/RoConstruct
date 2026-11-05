// from server: 57% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[4];
    volatile long ref1;
    volatile long ref2;
    virtual void vf1();
    virtual void vf2();
};

struct Outer {
    Inner* p;
    char pad[0x14];
    Inner inner;
};

struct Holder {
    Inner* p;
    long ref;
};

extern "C" Holder* __cdecl sub_660F30(Holder** out);

struct Result {
    Inner* p;
    long ref;
};

struct S {
    Result* f(Result* out);
};

Result* S::f(Result* out) {
    Holder* h = 0;
    Holder* r = sub_660F30(&h);
    Inner* ip = r->p;
    if (ip) {
        ip = (Inner*)((char*)ip + 0x18);
    } else {
        ip = 0;
    }
    out->p = ip;
    long ref = r->ref;
    out->ref = ref;
    if (ref) {
        _InterlockedExchangeAdd((volatile long*)((char*)ref + 4), 1);
    }
    Inner* esi = h ? h->p : 0;
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
