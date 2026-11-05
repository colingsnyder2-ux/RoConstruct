// from server: 61% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    void f(S* value);
};

void S::f(S* value)
{
    *(long*)this = *(long*)value;
    *(long*)((char*)this + 4) = *(long*)((char*)value + 4);

    if (*(long*)((char*)this + 4) != 0)
        _InterlockedExchangeAdd((volatile long*)((char*)*(long*)((char*)this + 4) + 8), 1);
}
