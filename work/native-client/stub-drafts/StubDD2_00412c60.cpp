// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x00412c60 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_0080e4a4[];
extern "C" void __fastcall fn_006a0d33(void* self);
extern "C" void* __fastcall fn_00412c60(void* self,int e,unsigned int f)
{
    *(void**)self = g_0080e4a4;
    fn_006a0d33(self);
    if (f & 1) ::operator delete(self);
    return self;
}
