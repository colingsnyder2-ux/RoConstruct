// from server: 76% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct WeakThreadRef
{
    int ref;
    void setRef(int*);
};

void WeakThreadRef::setRef(int* value)
{
    ref = *value;
    if (ref != 0)
        _InterlockedExchangeAdd((volatile long*)ref, 1);
}
