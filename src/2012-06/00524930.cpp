// from server: 47% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    char pad0[8];
    volatile long refcount;
};

struct Holder {
    char pad0[8];
    RefCounted* p;
};

extern "C" void __cdecl sub_51C940(void*);
extern "C" bool __cdecl sub_5226C0(void*);

struct S {
    int field0;
    char pad4[4];
    void* field8;
    int f(int a, int b, int c, RefCounted* d, int e, RefCounted* f2);
};

int S::f(int a, int b, int c, RefCounted* d, int e, RefCounted* f2)
{
    void* local[5];
    local[0] = (void*)a;
    local[1] = (void*)b;
    local[2] = (void*)c;
    local[3] = (void*)e;
    local[4] = (void*)f2;
    if (d) {
        _InterlockedExchangeAdd(&d->refcount, 1);
    }
    if (f2) {
        _InterlockedExchangeAdd(&f2->refcount, 1);
    }
    bool r = sub_5226C0((void*)0xd7c434);
    this->field0 = r ? 0xd7c434 : 0;
    sub_51C940(local);
    return this->field0;
}
