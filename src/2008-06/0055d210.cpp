// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

struct RefCount {
    long reserved;
    volatile long count;
};

struct Pair {
    void* first;
    RefCount* firstCount;
    void* second;
    RefCount* secondCount;
};

struct S {
    char stringData[28];
    long value;
    void* first;
    RefCount* firstCount;
    void* second;
    RefCount* secondCount;

    S(const S& source, const Pair& pair);
};

extern void (__thiscall* string_copy)(void*, const void*);

S::S(const S& source, const Pair& pair)
{
    string_copy(this, &source);
    value = source.value;
    first = pair.first;
    firstCount = pair.firstCount;
    if (firstCount) {
        volatile long* count = &firstCount->count;
        _ReadWriteBarrier();
        _InterlockedIncrement(count);
    }
    second = pair.second;
    secondCount = pair.secondCount;
    if (secondCount) {
        RefCount* counter = secondCount;
        _ReadWriteBarrier();
        volatile long* count = &counter->count;
        _ReadWriteBarrier();
        _InterlockedIncrement(count);
    }
}
