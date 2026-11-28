// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x00492870 in Roblox.exe (call_free scalar deleting destructor); class unknown, callees declared bare.
#include <new>
#include <stdlib.h>
extern "C" void __fastcall fn_004899e0(void* self);
extern "C" void* __fastcall fn_00492870(void* self,int e,unsigned int f)
{
    fn_004899e0(self);
    if (f & 1) free(self);
    return self;
}
