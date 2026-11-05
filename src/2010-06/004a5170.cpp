// from server: 65% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct PlaceholderValue
{
    long refcount;
};

struct Placeholder
{
    unsigned char pad[0x9c];
    void* first;
    PlaceholderValue* second;

    void f(PlaceholderValue** result);
};

void Placeholder::f(PlaceholderValue** result)
{
    result[0] = (PlaceholderValue*)first;
    result[1] = second;
    if (second != 0)
        _InterlockedExchangeAdd(&second->refcount, 1);
}
