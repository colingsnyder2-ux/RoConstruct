// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x005b2ea0 in Roblox.exe (call_free scalar deleting destructor); class unknown, callees declared bare.
#include <new>
#include <stdlib.h>
extern "C" void __fastcall fn_005b1230(void* self);
extern "C" void* __fastcall fn_005b2ea0(void* self,int e,unsigned int f)
{
    fn_005b1230(self);
    if (f & 1) free(self);
    return self;
}
