// from server: 72% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* p0;
    long refcount;
};

struct Outer {
    void* p0;
    Inner* p1;
};

extern "C" Outer* __cdecl sub_419390(void*);

Outer* __cdecl sub_419730(void* a, Outer* out) {
    Inner* inner = (Inner*)sub_419390(a);
    out->p0 = inner->p0;
    Inner* r = inner;
    out->p1 = r;
    long* rc = &r->refcount;
    if (rc != 0) {
        _InterlockedExchangeAdd(rc, 1);
    }
    return out;
}
