// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x005a3050 in Roblox.exe (call_free scalar deleting destructor); class unknown, callees declared bare.
#include <new>
#include <stdlib.h>
extern "C" void __fastcall fn_005a28c0(void* self);
extern "C" void* __fastcall fn_005a3050(void* self,int e,unsigned int f)
{
    fn_005a28c0(self);
    if (f & 1) free(self);
    return self;
}
