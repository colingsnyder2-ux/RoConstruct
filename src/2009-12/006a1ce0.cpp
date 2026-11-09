// from server: 52% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    void f(void**);
    void* vptr;
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
};

void S::f(void** out)
{
    out[0] = d;
    out[1] = e;
    if (e != 0)
        _InterlockedExchangeAdd((volatile long*)((char*)e + 4), 1);
}
