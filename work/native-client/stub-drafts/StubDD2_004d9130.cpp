// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x004d9130 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_00826b94[];
extern "C" void __fastcall fn_004d8e9f(void* self);
extern "C" void* __fastcall fn_004d9130(void* self,int e,unsigned int f)
{
    *(void**)self = g_00826b94;
    fn_004d8e9f(self);
    if (f & 1) ::operator delete(self);
    return self;
}
