// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x00480bf0 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_0081f0f8[];
extern "C" void __fastcall fn_0048011f(void* self);
extern "C" void* __fastcall fn_00480bf0(void* self,int e,unsigned int f)
{
    *(void**)self = g_0081f0f8;
    fn_0048011f(self);
    if (f & 1) ::operator delete(self);
    return self;
}
