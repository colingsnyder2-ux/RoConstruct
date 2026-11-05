// from server: 58% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[4];
    volatile long refcount;
};

struct Holder {
    void* ptr;
    Inner* inner;
};

struct Outer {
    char pad0[0x84];
    void call5038d0(Holder* h);
};

void Outer::call5038d0(Holder* h) {
    Holder tmp;
    tmp.ptr = h->ptr;
    tmp.inner = h->inner;
    if (tmp.inner) {
        _InterlockedExchangeAdd(&tmp.inner->refcount, 1);
    }
    void (*fn)(void*, Holder*) = (void (*)(void*, Holder*))0x5038d0;
    fn((char*)this + 0x84, &tmp);
}
