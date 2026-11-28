// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x004d9160 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_00826b9c[];
extern "C" void __fastcall fn_004d8f0f(void* self);
extern "C" void* __fastcall fn_004d9160(void* self,int e,unsigned int f)
{
    *(void**)self = g_00826b9c;
    fn_004d8f0f(self);
    if (f & 1) ::operator delete(self);
    return self;
}
