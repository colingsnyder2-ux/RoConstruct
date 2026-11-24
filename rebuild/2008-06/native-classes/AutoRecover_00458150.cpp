// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers were available, so the vendor types are declared minimally below.
// INFERRED: fn_00457ff0 is the non-deleting destructor of CXTPHeapObjectT<CXTPReportRows,...>; it takes `this` in ecx.
// INFERRED: g_0097e10c is the allocator's counter and g_0097e114 is its "use heap allocator" flag.
// INFERRED: the target is defined as a C-linkage function because the class cannot be reproduced without its headers.
#include <stddef.h>

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* p);

struct CXTPReportRowAllocatorData;

template<class T>
struct CXTPHeapAllocatorT
{
    static void Free_mem(void* p);
};

extern volatile long g_0097e10c;
extern int g_0097e114;

struct CXTPHeapObjectRows;

extern "C" void __fastcall fn_00457ff0(CXTPHeapObjectRows* self);

extern "C" void* __fastcall fn_00458150(CXTPHeapObjectRows* self, int unusedEdx, unsigned int flags)
{
    fn_00457ff0(self);
    if (flags & 1)
    {
        // inlined CXTPHeapObjectT::operator delete
        if (g_0097e114)
        {
            CXTPHeapAllocatorT<CXTPReportRowAllocatorData>::Free_mem(self);
            return self;
        }
        InterlockedDecrement(&g_0097e10c);
        ::operator delete((void*)self);
    }
    return self;
}
