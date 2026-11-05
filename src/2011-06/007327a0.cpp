// from server: 67% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct VMouseEventDesc
{
    int f0;
    int f4;
};

struct VMouse
{
    char pad[0x94];
    VMouseEventDesc* entries;

    void getEvent(int index, VMouseEventDesc* out);
};

void VMouse::getEvent(int index, VMouseEventDesc* out)
{
    VMouseEventDesc* e = &entries[index];
    out->f0 = e->f0;
    out->f4 = e->f4;
    if (out->f4 != 0)
    {
        _InterlockedExchangeAdd((volatile long*)(out->f4 + 4), 1);
    }
}
