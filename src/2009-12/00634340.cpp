// from server: 65% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct FactoryProductArg
{
    void* first;
    volatile long* second;
};

struct FactoryProduct
{
    void* first;
    volatile long* second;
};

FactoryProduct* __stdcall FactoryProductCreate(FactoryProduct* result, FactoryProductArg* value)
{
    result->first = value->first ? static_cast<char*>(value->first) + 0x1c : 0;
    result->second = value->second;

    if (result->second != 0)
        _InterlockedExchangeAdd(result->second + 1, 1);

    return result;
}
