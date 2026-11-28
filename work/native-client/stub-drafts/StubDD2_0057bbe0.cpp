// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x0057bbe0 in Roblox.exe (call_free scalar deleting destructor); class unknown, callees declared bare.
#include <new>
#include <stdlib.h>
extern "C" void __fastcall fn_0057ad70(void* self);
extern "C" void* __fastcall fn_0057bbe0(void* self,int e,unsigned int f)
{
    fn_0057ad70(self);
    if (f & 1) free(self);
    return self;
}
