// from server: 47% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_5394B0(void*);

struct VHumanoidEventDesc
{
    void Dispatch(void*, void*, void*);
};

void VHumanoidEventDesc::Dispatch(void* a, void* b, void* c)
{
    void* local[2];
    local[0] = a;
    local[1] = b;

    if (c != 0)
    {
        _InterlockedExchangeAdd((volatile long *)((char *)c + 4), 1);
    }

    void* p = *(void **)((char *)this + 0x34);
    int off = *(int *)((char *)c + 0x138);
    int idx = *(int *)(off + (int)p);
    idx += *(int *)((char *)this + 0x30);
    sub_5394B0((char *)c + 0x138 + idx);

    if (c != 0)
    {
        if (_InterlockedExchangeAdd((volatile long *)((char *)c + 4), -1) == 1)
        {
            (*(void (__thiscall **)(void *))(*(char **)c + 4))(c);
            if (_InterlockedExchangeAdd((volatile long *)((char *)c + 8), -1) == 1)
            {
                (*(void (__thiscall **)(void *))(*(char **)c + 8))(c);
            }
        }
    }
}
