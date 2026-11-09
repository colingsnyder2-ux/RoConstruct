// from server: 53% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Sub
{
    int storage[14];
    void copy(const Sub& other);
};

struct S
{
    int f0;
    Sub sub;
    int f40;
    int* p44;
    int f48;
    int* p4c;

    S(const S& other);
};

S::S(const S& other)
{
    f0 = other.f0;
    sub.copy(other.sub);
    f40 = other.f40;
    p44 = other.p44;
    if (p44)
        _InterlockedExchangeAdd((volatile long*)((char*)p44 + 8), 1);
    f48 = other.f48;
    p4c = other.p4c;
    if (p4c)
        _InterlockedExchangeAdd((volatile long*)((char*)p4c + 4), 1);
}
