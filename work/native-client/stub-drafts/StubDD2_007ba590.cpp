// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x007ba590 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_00875d4c[];
extern "C" void __fastcall fn_0048011f(void* self);
extern "C" void* __fastcall fn_007ba590(void* self,int e,unsigned int f)
{
    *(void**)self = g_00875d4c;
    fn_0048011f(self);
    if (f & 1) ::operator delete(self);
    return self;
}
