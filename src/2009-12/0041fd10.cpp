// from server: 62% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    void f(void*);
};

void S::f(void* p)
{
    int* q = (int*)p;
    q[0] = *(int*)((char*)this + 0x12c);
    q[1] = *(int*)((char*)this + 0x130);
    if (q[1] != 0)
        _InterlockedExchangeAdd((volatile long*)((char*)q[1] + 4), 1);
}
