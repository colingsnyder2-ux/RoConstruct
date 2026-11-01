// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct Counter {
    volatile long value;
    __forceinline void retain();
};

__forceinline void Counter::retain()
{
    volatile long* p = &value;
    _ReadWriteBarrier();
    _InterlockedExchangeAdd(p, 1);
}

struct Ref {
    long reserved;
    Counter count;
    __forceinline void retain();
};

__forceinline void Ref::retain()
{
    count.retain();
}

extern unsigned char initialTable[];
extern unsigned char finalTable[];
extern void* globalObject;
extern Ref* globalReference;

struct S {
    unsigned long tag;
    void* object;
    Ref* reference;
    unsigned long a, b, c, d, e, f;

    S();
};

S::S()
{
    tag = reinterpret_cast<unsigned long>(initialTable);
    object = globalObject;
    reference = globalReference;
    if (reference)
        reference->retain();
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    tag = reinterpret_cast<unsigned long>(finalTable);
    f = 0;
}
