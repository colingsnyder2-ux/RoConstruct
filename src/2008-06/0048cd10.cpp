// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

struct Control {
    long reserved;
    volatile long references;
};

struct S {
    long a;
    long b;
    Control* c;
    long d;
    Control* e;

    S* f(const S* source);
};

S* S::f(const S* source)
{
    a = source->a;
    b = source->b;
    c = source->c;
    if (c) {
        volatile long* count = &c->references;
        _ReadWriteBarrier();
        _InterlockedExchangeAdd(count, 1);
    }
    d = source->d;
    e = source->e;
    if (e) {
        volatile long* count = &e->references;
        _ReadWriteBarrier();
        _InterlockedExchangeAdd(count, 1);
    }
    return this;
}
