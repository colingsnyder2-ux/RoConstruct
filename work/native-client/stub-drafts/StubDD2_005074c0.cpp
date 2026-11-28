// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x005074c0 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_008274a4[];
extern "C" void __fastcall fn_00486b9f(void* self);
extern "C" void* __fastcall fn_005074c0(void* self,int e,unsigned int f)
{
    *(void**)self = g_008274a4;
    fn_00486b9f(self);
    if (f & 1) ::operator delete(self);
    return self;
}
