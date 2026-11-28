// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x007acd00 in Roblox.exe (vt_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_00874a8c[];
extern "C" void* __fastcall fn_007acd00(void* self,int e,unsigned int f)
{
    *(void**)self = g_00874a8c;
    if (f & 1) ::operator delete(self);
    return self;
}
