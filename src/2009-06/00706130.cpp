// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <new>
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement)
struct T { char pad[0x10]; long count; };
inline void add_ref(T* p) { _InterlockedIncrement(&p->count); }
struct P {
    T* p;
    P(const P& o) : p(o.p) { if (p) add_ref(p); }
};
P* uninit_copy(P* first, P* last, P* dest)
{
    for (; first != last; ++dest, ++first)
        new (dest) P(*first);
    return dest;
}
