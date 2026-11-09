// from server: 50% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[4];
    volatile long refcount;
};

struct Holder {
    char pad0[4];
    void* fn;
    Inner* obj;
};

struct Outer {
    int __cdecl invoke(Holder* h, int a, int b);
};

int Outer::invoke(Holder* h, int a, int b)
{
    Inner* o = h->obj;
    Inner* local = o;
    if (o != 0)
        _InterlockedExchangeAdd(&o->refcount, 1);
    void (*f)(int, int) = (void (*)(int, int))h->fn;
    f(a, b);
    return 0;
}
