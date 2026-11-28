// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x006f98d0 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_0085a610[];
extern "C" void __fastcall fn_0041119f(void* self);
extern "C" void* __fastcall fn_006f98d0(void* self,int e,unsigned int f)
{
    *(void**)self = g_0085a610;
    fn_0041119f(self);
    if (f & 1) ::operator delete(self);
    return self;
}
