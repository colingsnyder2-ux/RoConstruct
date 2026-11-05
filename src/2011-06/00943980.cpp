// from server: 61% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S_00943980
{
    virtual ~S_00943980();
    void f(void*, unsigned int);
};

void S_00943980::f(void* result, unsigned int index)
{
    struct Entry
    {
        void* first;
        volatile long* second;
    };

    Entry* entries = *(Entry**)this;
    Entry* entry = entries + index;
    *(void**)result = entry->first;
    *(volatile long**)((char*)result + 4) = entry->second;
    if (entry->second != 0)
        _InterlockedExchangeAdd(entry->second, 1);
}
