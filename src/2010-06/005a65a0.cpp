// from server: 85% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct VVector2Holder
{
    void* __cdecl construct(void* a, void* b);
};

void* VVector2Holder::construct(void* a, void* b)
{
    int* src = (int*)b;
    int* dst = (int*)a;

    int* p = (int*)src[0];
    int* q;
    if (p != 0)
        q = (int*)((char*)p + 0x1c);
    else
        q = 0;

    dst[0] = (int)q;
    int ref = src[1];
    dst[1] = ref;
    if (ref != 0)
    {
        _InterlockedExchangeAdd((volatile long*)(ref + 4), 1);
    }
    return a;
}
