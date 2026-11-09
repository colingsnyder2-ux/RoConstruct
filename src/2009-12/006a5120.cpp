// from server: 57% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    int a;
    volatile long ref;
};

struct Outer {
    int a;
    int b;
};

extern Inner* __cdecl sub_6a4e90(Outer* p);

void __cdecl sub_6a5120(Outer* src, Outer* dst) {
    Inner* r = sub_6a4e90(src);
    dst->a = r->a;
    dst->b = r->ref;
    if (r->ref != 0) {
        _InterlockedExchangeAdd(&r->ref, 1);
    }
}
