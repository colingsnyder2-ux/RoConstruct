// from server: 52% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[4];
    volatile long refcount;
};

struct Outer {
    char pad0[8];
    int field8;
    Inner* fieldC;
    Inner* field10;
    int field14;
    void __cdecl method(int, Inner*, int);
};

void Outer::method(int a, Inner* b, int c) {
    Inner* p = field10;
    if (p) {
        _InterlockedExchangeAdd(&p->refcount, 1);
    }
    void (*fn)(int, Inner*, int) = (void (*)(int, Inner*, int))0x513bb0;
    fn(field8, fieldC, field14);
}
