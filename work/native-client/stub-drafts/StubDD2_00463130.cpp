// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x00463130 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_0081a8ec[];
extern "C" void __fastcall fn_006a0ed1(void* self);
extern "C" void* __fastcall fn_00463130(void* self,int e,unsigned int f)
{
    *(void**)self = g_0081a8ec;
    fn_006a0ed1(self);
    if (f & 1) ::operator delete(self);
    return self;
}
