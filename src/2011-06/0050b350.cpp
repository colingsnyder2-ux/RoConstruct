// from server: 21% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Sub
{
    void** vtbl;
    void Release();
};

struct ServerReplicator
{
    char pad0[0x1d14];
    Sub* field_1d14;
    void sub_0050a500();
};

void ServerReplicator::sub_0050a500()
{
    Sub* p = field_1d14;
    if (p)
    {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1)
        {
            (*(void(__thiscall**)(Sub*))(*(void***)p)[1])(p);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1)
            {
                (*(void(__thiscall**)(Sub*))(*(void***)p)[2])(p);
            }
        }
    }
}
