// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x006cf130 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_00853b7c[];
extern "C" void __fastcall fn_006cb6ff(void* self);
extern "C" void* __fastcall fn_006cf130(void* self,int e,unsigned int f)
{
    *(void**)self = g_00853b7c;
    fn_006cb6ff(self);
    if (f & 1) ::operator delete(self);
    return self;
}
