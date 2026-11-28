// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x004c7090 in Roblox.exe (vt_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_008265e4[];
extern "C" void* __fastcall fn_004c7090(void* self,int e,unsigned int f)
{
    *(void**)self = g_008265e4;
    if (f & 1) ::operator delete(self);
    return self;
}
