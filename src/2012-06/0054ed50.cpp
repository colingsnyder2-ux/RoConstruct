// from server: 77% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
};

void __cdecl f(void* source, void* destination)
{
    if (destination)
    {
        *(long*)destination = *(long*)source;
        *(long*)((char*)destination + 4) = *(long*)((char*)source + 4);
        if (*(long*)((char*)source + 4))
            _InterlockedExchangeAdd((volatile long*)((char*)source + 8), 1);
    }
}
