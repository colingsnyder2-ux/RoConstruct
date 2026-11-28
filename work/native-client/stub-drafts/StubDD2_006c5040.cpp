// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x006c5040 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_00852c5c[];
extern "C" void __fastcall fn_006a0ed1(void* self);
extern "C" void* __fastcall fn_006c5040(void* self,int e,unsigned int f)
{
    *(void**)self = g_00852c5c;
    fn_006a0ed1(self);
    if (f & 1) ::operator delete(self);
    return self;
}
