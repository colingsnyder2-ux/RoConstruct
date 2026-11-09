// from server: 65% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S {
    int value;
    void* object;
    void get(void*);
};

void S::get(void* out)
{
    *(long*)out = *(long*)((char*)this + 0xa4);
    *(void**)((char*)out + 4) = *(void**)((char*)this + 0xa8);
    if (*(void**)((char*)this + 0xa8) != 0)
        _InterlockedExchangeAdd((volatile long*)((char*)*(void**)((char*)this + 0xa8) + 4), 1);
}
