// from server: 61% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S {
    int value0;
    int value1;
    int value2;
    int value3;
    long* value4;
    void f(long*);
};

void S::f(long* result)
{
    long* p = value4;
    result[0] = (long)p;
    result[1] = 0;
    if (p != 0)
        _InterlockedExchangeAdd((volatile long*)((char*)p + 4), 1);
}
