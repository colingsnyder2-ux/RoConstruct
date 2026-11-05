// from server: 68% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    int f(void*);
    void* vptr;
    char padding[0x84];
    void* first;
    volatile long second;
};

int S::f(void* result)
{
    result = result;
    *(void**)result = first;
    *(void**)((char*)result + 4) = (void*)second;
    if (second != 0)
        _InterlockedExchangeAdd(&second + 1, 1);
    return 0;
}
