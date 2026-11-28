// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x007b9600 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_00875d2c[];
extern "C" void __fastcall fn_007b954f(void* self);
extern "C" void* __fastcall fn_007b9600(void* self,int e,unsigned int f)
{
    *(void**)self = g_00875d2c;
    fn_007b954f(self);
    if (f & 1) ::operator delete(self);
    return self;
}
