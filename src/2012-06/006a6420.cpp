// from server: 67% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    void f(void**);
};

void S::f(void** p)
{
    void* value = *(void**)((char*)this + 0x10);
    *p = 0;
    *p = value;
    if (value != 0)
        _InterlockedExchangeAdd((volatile long*)value, 1);
}
