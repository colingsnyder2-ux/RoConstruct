// from server: 65% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    void Get(void*);
};

void S::Get(void* p)
{
    long* q = (long*)((char*)this + 0x1ac);
    *(long*)p = *(long*)((char*)this + 0x1a8);
    *(long*)((char*)p + 4) = *q;
    if (*q)
        _InterlockedExchangeAdd((volatile long*)((char*)*q + 4), 1);
}
