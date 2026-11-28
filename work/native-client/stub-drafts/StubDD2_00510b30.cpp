// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x00510b30 in Roblox.exe (vt_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_008282cc[];
extern "C" void* __fastcall fn_00510b30(void* self,int e,unsigned int f)
{
    *(void**)self = g_008282cc;
    if (f & 1) ::operator delete(self);
    return self;
}
