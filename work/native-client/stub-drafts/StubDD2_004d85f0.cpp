// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x004d85f0 in Roblox.exe (vt_call_delete scalar deleting destructor); class unknown, callees declared bare.
#include <new>
extern "C" char g_00826c0c[];
extern "C" void __fastcall fn_004d7e2f(void* self);
extern "C" void* __fastcall fn_004d85f0(void* self,int e,unsigned int f)
{
    *(void**)self = g_00826c0c;
    fn_004d7e2f(self);
    if (f & 1) ::operator delete(self);
    return self;
}
