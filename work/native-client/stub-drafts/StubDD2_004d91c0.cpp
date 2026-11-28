// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x004d91c0 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_00826bac[];
extern "C" void __fastcall fn_004d8fef(void* self);
extern "C" void* __fastcall fn_004d91c0(void* self,int e,unsigned int f)
{
    *(void**)self = g_00826bac;
    fn_004d8fef(self);
    if (f & 1) ::operator delete(self);
    return self;
}
