// from server: 41% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    int (__cdecl *callback)(void*);
    void* value;
    volatile long* count;
    int f();
};

int S::f()
{
    int a = value ? *(int*)value : 0;
    int* p = (int*)&a;
    if (value)
        _InterlockedExchangeAdd((volatile long*)(p + 1), 1);
    return callback((void*)p);
}
