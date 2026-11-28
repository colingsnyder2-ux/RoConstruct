// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x00701220 in Roblox.exe (vt_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_0085b1c8[];
extern "C" void* __fastcall fn_00701220(void* self,int e,unsigned int f)
{
    *(void**)self = g_0085b1c8;
    if (f & 1) ::operator delete(self);
    return self;
}
