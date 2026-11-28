// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x0066f8e0 in Roblox.exe (vt_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_0084d1cc[];
extern "C" void* __fastcall fn_0066f8e0(void* self,int e,unsigned int f)
{
    *(void**)self = g_0084d1cc;
    if (f & 1) ::operator delete(self);
    return self;
}
