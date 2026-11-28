// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x00421110 in Roblox.exe (vt_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_0080f860[];
extern "C" void* __fastcall fn_00421110(void* self,int e,unsigned int f)
{
    *(void**)self = g_0080f860;
    if (f & 1) ::operator delete(self);
    return self;
}
