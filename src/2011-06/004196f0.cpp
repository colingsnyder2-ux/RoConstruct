// from server: 53% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    int a;
    long ref;
};

struct Outer {
    int a;
    long ref;
};

extern "C" Inner* __cdecl sub_419300(Outer*);

struct S {
    void __cdecl f(Outer*);
};

void S::f(Outer* p) {
    Inner* r = sub_419300(p);
    p->a = r->a;
    long c = r->ref;
    p->ref = c;
    if (c != 0) {
        _InterlockedExchangeAdd(&r->ref, 1);
    }
}
