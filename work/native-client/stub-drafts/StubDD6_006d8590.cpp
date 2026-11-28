// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x006d8590 (scalar deleting destructor of a CXTPHeapObjectT-style pooled object: free via the
// pool when its flag global is set, else InterlockedDecrement(counter) + operator delete); class unknown, callees bare.
#include <new>
#include <windows.h>
extern "C" int g_0097e114;
extern "C" LONG g_0097e10c;
extern "C" void __fastcall fn_006d8100(void* self);
extern "C" void __cdecl fn_00420a80(void* p);
extern "C" void* __fastcall fn_006d8590(void* self, int e, unsigned int f)
{
    fn_006d8100(self);
    if (f & 1)
    {
        if (g_0097e114 != 0)
        {
            fn_00420a80(self);
            return self;
        }
        InterlockedDecrement(&g_0097e10c);
        ::operator delete(self);
    }
    return self;
}
