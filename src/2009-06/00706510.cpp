// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <new>
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
extern "C" long __cdecl _InterlockedExchangeAdd(long volatile*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
#pragma intrinsic(_InterlockedIncrement)
struct Data { char pad[0x10]; long count; };
struct Handle {
    Data* p;
    Handle(const Handle& o) : p(o.p) { if (p) _InterlockedIncrement(&p->count); }
};
void fill_n(Handle* first, unsigned int n, const Handle& val)
{
    for (; n > 0; --n, ++first)
        new (first) Handle(val);
}
