// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: static initializer: constructs a global at 0x9738f0, then registers its destructor via atexit.
#pragma optimize("g", off)
extern "C" int __fastcall fn_0054feb0(void* self);
extern "C" int __cdecl atexit(void (__cdecl *)(void));

extern "C" char g_009738f0[];

extern "C" void __cdecl fn_007fc650(void);

extern "C" void fn_007f26c0(void)
{
    fn_0054feb0(g_009738f0);
    atexit(fn_007fc650);
}
