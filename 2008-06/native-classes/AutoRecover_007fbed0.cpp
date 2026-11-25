// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: unknown globals declared as externs
extern "C" void* g_00971350;
extern "C" void* g_00971338;
// INFERRED: base vtable symbol stored at 0x80b730
extern "C" char g_0080b730;

extern "C" void fn_007fbed0(void)
{
    if (g_00971350)
        operator delete(g_00971350);
    g_00971338 = &g_0080b730;
}
