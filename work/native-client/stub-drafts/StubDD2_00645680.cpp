// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x00645680 in Roblox.exe (vt_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_0084ad44[];
extern "C" void* __fastcall fn_00645680(void* self,int e,unsigned int f)
{
    *(void**)self = g_0084ad44;
    if (f & 1) ::operator delete(self);
    return self;
}
