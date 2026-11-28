// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x005e2760 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_0083e07c[];
extern "C" void __fastcall fn_0064548f(void* self);
extern "C" void* __fastcall fn_005e2760(void* self,int e,unsigned int f)
{
    *(void**)self = g_0083e07c;
    fn_0064548f(self);
    if (f & 1) ::operator delete(self);
    return self;
}
