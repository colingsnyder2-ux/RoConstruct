// from server: 33% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    long refcount;
    long weakrefcount;
};

struct Inner {
    char pad[0x14];
};

struct S {
    int field0;
    void construct(Inner* a, int b, int c, RefCounted* d, int e, int f);
};

void S::construct(Inner* a, int b, int c, RefCounted* d, int e, int f) {
    Inner local;
    local = *a;
    this->field0 = 0;
    if (d) {
        _InterlockedExchangeAdd(&d->refcount, 1);
    }
    ((void (__thiscall*)(S*, Inner*))0x743710)(this, &local);
    if (d) {
        if (_InterlockedExchangeAdd(&d->refcount, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))d->vptr[1])(d);
            if (_InterlockedExchangeAdd(&d->weakrefcount, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))d->vptr[2])(d);
            }
        }
    }
}
