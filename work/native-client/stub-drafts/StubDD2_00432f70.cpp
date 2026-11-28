// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x00432f70 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_00811cdc[];
extern "C" void __fastcall fn_006a1075(void* self);
extern "C" void* __fastcall fn_00432f70(void* self,int e,unsigned int f)
{
    *(void**)self = g_00811cdc;
    fn_006a1075(self);
    if (f & 1) ::operator delete(self);
    return self;
}
