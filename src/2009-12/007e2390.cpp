// from server: 67% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct PasteVerb {
    void *value;
    void f(void *);
};

void PasteVerb::f(void *source)
{
    void *p = *(void **)source;
    value = p;
    if (p != 0)
        _InterlockedExchangeAdd((volatile long *)((char *)p + 16), 1);
}
