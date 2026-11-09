// from server: 80% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct ChatLine
{
    int *get(int *result);
};

int *ChatLine::get(int *result)
{
    result[0] = *(int *)((char *)this + 0x90);
    result[1] = *(int *)((char *)this + 0x94);
    if (result[1] != 0)
        _InterlockedExchangeAdd((volatile long *)(result[1] + 1), 1);
    return result;
}
