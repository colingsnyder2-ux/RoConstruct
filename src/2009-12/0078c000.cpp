// from server: 46% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    int value;
    void* ref;
    int __cdecl f(int);
};

int S::f(int value)
{
    this->value = value;
    void* p = this->ref;
    this->ref = p;
    if (p != 0)
        _InterlockedExchangeAdd((volatile long*)((char*)p + 4), 1);
    return 0;
}
