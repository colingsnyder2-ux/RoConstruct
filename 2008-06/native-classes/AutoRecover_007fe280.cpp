// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the real target is the compiler-generated atexit destructor for
// RBX::Sky::prop_SkyRt; it cannot be named in source, so it is expressed
// with the fn_<address> convention. The static's members are modelled as
// unknown globals, and the base vtable as an unknown global as well.

extern "C" void* g_00976ce4;   // INFERRED: owned pointer member of prop_SkyRt
extern "C" void* g_00976ccc;   // INFERRED: vtable slot of prop_SkyRt
extern "C" char g_0080b730[];  // INFERRED: base-class vtable

extern "C" void fn_007fe280(void)
{
    if (g_00976ce4)
        operator delete(g_00976ce4);
    g_00976ccc = (void*)g_0080b730;
}
