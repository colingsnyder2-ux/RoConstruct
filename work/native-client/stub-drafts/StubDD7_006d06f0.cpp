// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x006d06f0 (scalar deleting destructor of a CXTPHeapAllocatorT/BatchAllocManagerT instance:
// reset vtable, destroy the shared heap when its use flag is clear, operator delete when flags&1); class unknown, globals bare.
#include <new>
#include <windows.h>
extern "C" char g_008536ac[];
extern "C" int g_0097e11c;
extern "C" HANDLE g_0097e118;
extern "C" void __fastcall fn_006cf49f(void* self);
extern "C" void* __fastcall fn_006d06f0(void* self, int e, unsigned int f)
{
    *(void**)self = g_008536ac;
    fn_006cf49f(self);
    if (g_0097e11c == 0)
    {
        if (g_0097e118 != 0)
            HeapDestroy(g_0097e118);
        g_0097e118 = 0;
    }
    if (f & 1)
        ::operator delete(self);
    return self;
}
