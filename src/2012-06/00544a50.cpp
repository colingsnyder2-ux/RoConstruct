// from server: 54% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

typedef void (__thiscall *Vfn)(void*);

struct RefCounted {
    Vfn* vptr;
    volatile long ref1;
    volatile long ref2;
};

struct Inner {
    void* p0;
    RefCounted* p1;
};

struct Outer {
    void* p0;
    RefCounted* p1;
};

extern "C" void __cdecl sub_5448A0(Inner* out, void* arg);

struct S {
    Outer* __thiscall f(void* arg);
};

Outer* __thiscall S::f(void* arg) {
    Inner tmp;
    tmp.p0 = 0;
    tmp.p1 = 0;
    sub_5448A0(&tmp, arg);
    Outer* out = (Outer*)arg;
    out->p0 = tmp.p0;
    out->p1 = tmp.p1;
    if (out->p1 != 0) {
        _InterlockedExchangeAdd(&out->p1->ref1, 1);
    }
    RefCounted* r = tmp.p1;
    if (r != 0) {
        if (_InterlockedExchangeAdd(&r->ref1, -1) == 1) {
            r->vptr[1](r);
        }
        if (_InterlockedExchangeAdd(&r->ref2, -1) == 1) {
            r->vptr[2](r);
        }
    }
    return out;
}
