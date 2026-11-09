// from server: 65% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct CSelectionPropGrid
{
    void* m_vtable;
    volatile long m_refCount;
};

extern "C" void* __cdecl create_00437f40(void*, void**);

void* __cdecl create_0043a580(CSelectionPropGrid* unused, CSelectionPropGrid** out)
{
    void* value = 0;
    void* result = create_00437f40(&value, (void**)out);
    *out = (CSelectionPropGrid*)result;
    if (result != 0)
        _InterlockedExchangeAdd(&((CSelectionPropGrid*)result)->m_refCount, 1);
    return result;
}
