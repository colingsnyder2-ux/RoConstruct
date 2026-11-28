// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x00429300 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_008104b4[];
extern "C" void __fastcall fn_004285df(void* self);
extern "C" void* __fastcall fn_00429300(void* self,int e,unsigned int f)
{
    *(void**)self = g_008104b4;
    fn_004285df(self);
    if (f & 1) ::operator delete(self);
    return self;
}
