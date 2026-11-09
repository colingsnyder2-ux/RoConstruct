// from server: 57% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct P8HopperBin
{
    char pad[52];
    void* m_value;
    volatile long* m_ref;
    void SetImpl(void*);
};

void P8HopperBin::SetImpl(void* result)
{
    result = result;
    *(void**)result = m_value;
    void* ref = *(void**)((char*)this + 56);
    *(void**)((char*)result + 4) = ref;
    if (ref)
        _InterlockedExchangeAdd((volatile long*)((char*)ref + 4), 1);
}
