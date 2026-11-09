// from server: 62% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    void get(void*);
};

void S::get(void* p)
{
    long* a = *(long**)((char*)this + 0xcc);
    *(long**)p = a;
    long* b = *(long**)((char*)this + 0xd0);
    *(long**)((char*)p + 4) = b;
    if (b != 0)
        _InterlockedExchangeAdd((volatile long*)(b + 1), 1);
}
