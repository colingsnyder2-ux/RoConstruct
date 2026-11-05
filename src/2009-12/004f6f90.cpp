// from server: 58% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S {
    void f(void*);
    void* vptr;
    int a[40];
};

void S::f(void* p)
{
    int* q = (int*)p;
    q[0] = a[41];
    q[1] = a[42];
    if (q[1] != 0)
        _InterlockedExchangeAdd((volatile long*)((char*)q[1] + 4), 1);
}
