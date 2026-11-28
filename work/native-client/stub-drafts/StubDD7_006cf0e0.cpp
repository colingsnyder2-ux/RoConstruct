// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x006cf0e0 (scalar deleting destructor of a CXTPHeapAllocatorT/BatchAllocManagerT instance:
// reset vtable, destroy the shared heap when its use flag is clear, operator delete when flags&1); class unknown, globals bare.
#include <new>
#include <windows.h>
extern "C" char g_008539ec[];
extern "C" int g_0097e12c;
extern "C" HANDLE g_0097e128;
extern "C" void* __fastcall fn_006cf0e0(void* self, int e, unsigned int f)
{
    *(void**)self = g_008539ec;
    if (g_0097e12c == 0)
    {
        if (g_0097e128 != 0)
            HeapDestroy(g_0097e128);
        g_0097e128 = 0;
    }
    if (f & 1)
        ::operator delete(self);
    return self;
}
