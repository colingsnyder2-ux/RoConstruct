// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x00472820 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_0081ce1c[];
extern "C" void __fastcall fn_0047168f(void* self);
extern "C" void* __fastcall fn_00472820(void* self,int e,unsigned int f)
{
    *(void**)self = g_0081ce1c;
    fn_0047168f(self);
    if (f & 1) ::operator delete(self);
    return self;
}
