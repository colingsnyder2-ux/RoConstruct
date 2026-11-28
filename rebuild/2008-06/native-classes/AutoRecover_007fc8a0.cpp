// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header available; globals modeled as raw externs.
extern "C" void* g_00973d50;
extern "C" const void* g_00973d34;
extern "C" const char g_0080b730[];

// INFERRED: dynamic atexit destructor for Instance::propParent
extern "C" void __cdecl fn_007fc8a0(void)
{
    if (g_00973d50)
        operator delete(g_00973d50);
    g_00973d34 = g_0080b730;
}
