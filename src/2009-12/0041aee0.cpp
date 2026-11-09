// from server: 90% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" long __stdcall InterlockedIncrement(volatile long*);

struct NameData
{
    long value;
    volatile long* reference;
};

struct CNameItem
{
    long value;
    volatile long* reference;
    CNameItem(NameData*);
};

CNameItem::CNameItem(NameData* data)
{
    InterlockedIncrement((volatile long*)0xb7a220);
    value = data->value;
    reference = data->reference;
    if (reference != 0)
        _InterlockedExchangeAdd(reference + 2, 1);
}
