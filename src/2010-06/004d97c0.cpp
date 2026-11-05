// from server: 19% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
};

struct Inner {
    char pad[0x28];
    RefCounted* ptr;
};

struct Outer {
    char pad[0x2c];
    Inner inner;
};

struct Holder {
    RefCounted* p;
};

extern "C" void* __stdcall sub_742810(void*);
extern "C" void __cdecl sub_4588f0(void*, void*);

struct S_func_004d97c0 {
    Holder* f(Outer* src);
};

Holder* S_func_004d97c0::f(Outer* src)
{
    Holder local;
    local.p = 0;
    int flags = 0;
    RefCounted* old = 0;

    if (src != 0) {
        void* tmp;
        sub_742810(&src->inner);
        sub_4588f0(&local, &tmp);
        old = local.p;
        flags = 2;
    } else {
        old = 0;
        local.p = 0;
    }

    Holder* dst = (Holder*)0;
    dst->p = local.p;

    if (dst->p != 0) {
        _InterlockedExchangeAdd(&dst->p->refcount, 1);
    }

    if (old != 0) {
        if (_InterlockedExchangeAdd(&old->refcount, -1) == 1) {
            old->vptr;
        }
    }

    return dst;
}
