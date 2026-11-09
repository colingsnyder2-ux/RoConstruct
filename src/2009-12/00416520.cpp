// from server: 55% by atomic.potato
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

struct S {
    void __cdecl f(Outer* out);
};

extern Inner* __cdecl sub_416420(Outer* out);

void S::f(Outer* out) {
    Inner* p = sub_416420(out);
    out->a = p->a;
    out->ref = p->ref;
    if (out->ref != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)out->ref + 4), 1);
    }
}
