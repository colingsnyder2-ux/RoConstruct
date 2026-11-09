// from server: 56% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    int a;
    long ref;
};

struct Holder {
    int a;
    Inner* p;
};

extern "C" Holder* __cdecl sub_84e0e0(int);

struct S {
    void __cdecl f(Holder* out);
};

void S::f(Holder* out) {
    Holder* r = sub_84e0e0(*(int*)((char*)out));
    out->a = r->a;
    out->p = r->p;
    if (out->p) {
        _InterlockedExchangeAdd(&out->p->ref, 1);
    }
}
