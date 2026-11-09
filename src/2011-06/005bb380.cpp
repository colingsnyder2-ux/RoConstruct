// from server: 61% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct VRegion3Holder
{
    void* field_0;
    void* field_4;
};

void assign(VRegion3Holder* self, void* out)
{
    void* src = *(void**)self;
    void* p;
    if (src != 0)
        p = (char*)src + 0x1c;
    else
        p = 0;
    *(void**)out = p;

    long* ref = (long*)((char*)self + 4);
    *(long*)((char*)out + 4) = (long)ref;
    if (ref != 0)
    {
        _InterlockedExchangeAdd((volatile long*)((char*)ref + 4), 1);
    }
}
