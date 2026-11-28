// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x00510750 in Roblox.exe (vt_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_008282bc[];
extern "C" void* __fastcall fn_00510750(void* self,int e,unsigned int f)
{
    *(void**)self = g_008282bc;
    if (f & 1) ::operator delete(self);
    return self;
}
