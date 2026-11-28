// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#pragma optimize("g", off)
extern "C" int __fastcall fn_00551600(void* self);
extern "C" void __cdecl fn_007fc660(void);
extern "C" int __cdecl _atexit(void (__cdecl *)(void));
extern "C" char g_00973934[];

extern "C" void fn_007f26e0(void)
{
    // INFERRED: callee is thiscall with no stack args actually pushed
    fn_00551600((void*)g_00973934);
    _atexit(fn_007fc660);
}
