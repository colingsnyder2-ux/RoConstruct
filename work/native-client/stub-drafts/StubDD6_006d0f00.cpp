// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x006d0f00 (scalar deleting destructor of a CXTPHeapObjectT-style pooled object: free via the
// pool when its flag global is set, else InterlockedDecrement(counter) + operator delete); class unknown, callees bare.
#include <new>
#include <windows.h>
extern "C" int g_0097e134;
extern "C" LONG g_0097e12c;
extern "C" void __fastcall fn_006da430(void* self);
extern "C" void __cdecl fn_006cf160(void* p);
extern "C" void* __fastcall fn_006d0f00(void* self, int e, unsigned int f)
{
    fn_006da430(self);
    if (f & 1)
    {
        if (g_0097e134 != 0)
        {
            fn_006cf160(self);
            return self;
        }
        InterlockedDecrement(&g_0097e12c);
        ::operator delete(self);
    }
    return self;
}
