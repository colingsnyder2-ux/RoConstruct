// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_workspace_b7f04cf67c63dbb3.cpp

// Candidate translation unit (score above; library headers required).

#include <intrin.h>

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)



struct Range {
    void* base;
    char padding[8];
    unsigned first;
    unsigned last;
};

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<Range> SharedRange;

void __cdecl callback();
void __cdecl process(void*, unsigned, void*, unsigned, void (__cdecl*)());

void __stdcall sub_005a2420(SharedRange range)
{
    Range* endObject = range.get();
    unsigned last = endObject->last;
    if (endObject->first > last)
        _invalid_parameter_noinfo();

    void* lastBase = endObject->base;

    Range* beginObject = range.get();
    unsigned first = beginObject->first;
    if (first > beginObject->last)
        _invalid_parameter_noinfo();

    process(beginObject->base, first, lastBase, last, callback);
}