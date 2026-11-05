// from server: 53% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    void f(void*);
};

struct R
{
    volatile long count;
};

void S::f(void* out)
{
    R* p = *(R**)((char*)this + 0xa0);
    *(void**)out = *(void**)((char*)this + 0x9c);
    *(R**)((char*)out + 4) = p;
    if (p != 0)
        _InterlockedExchangeAdd(&p->count, 1);
}
