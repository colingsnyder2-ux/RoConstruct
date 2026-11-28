// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: header-free model of the compiler-generated atexit destructor
// for Sky::prop_SkyRt. The static object lives at 0x974750; its member at
// 0x974768 is a heap pointer, and the vtable is reset to 0x80b730.
extern void* g_00974768;
extern const void* g_00974750;
extern const char g_0080b730[];

extern "C" void fn_007fced0(void)
{
    if (g_00974768)
        operator delete(g_00974768);
    g_00974750 = g_0080b730;
}
