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
    unsigned long a;
    unsigned long b;
    unsigned long c;
    unsigned long d;
    unsigned long e;
    Control* control;

    S(const S& source);
};

S::S(const S& source) {
    a = source.a;
    b = source.b;
    c = source.c;
    d = source.d;
    e = source.e;
    control = source.control;
    if (control) {
        volatile long* references = &control->references;
        _ReadWriteBarrier();
        _InterlockedExchangeAdd(references, 1);
    }
}
