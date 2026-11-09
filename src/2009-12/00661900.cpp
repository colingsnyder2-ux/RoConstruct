// from server: 41% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
};

struct Holder {
    void* ptr;
    RefCounted* ref;
};

extern "C" Holder* __cdecl sub_6611B0(Holder* out);

struct S {
    Holder* f(Holder* out);
};

Holder* S::f(Holder* out) {
    Holder tmp;
    sub_6611B0(&tmp);
    void* p = tmp.ptr;
    if (p != 0) {
        out->ptr = (char*)p + 0x18;
    } else {
        out->ptr = 0;
    }
    out->ref = tmp.ref;
    if (out->ref != 0) {
        _InterlockedExchangeAdd(&out->ref->refcount, 1);
    }
    RefCounted* r = tmp.ref;
    if (r != 0) {
        if (_InterlockedExchangeAdd(&r->refcount, -1) == 1) {
            void (*fn)(RefCounted*) = *(void (**)(RefCounted*))((char*)r->vptr + 4);
            fn(r);
            if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 1) {
                void (*fn2)(RefCounted*) = *(void (**)(RefCounted*))((char*)r->vptr + 8);
                fn2(r);
            }
        }
    }
    return out;
}
