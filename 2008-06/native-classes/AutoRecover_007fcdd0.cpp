// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: stand-in for the static BoundProp<TextureId,1> object layout.
extern "C" {
    extern void* g_009745f4;   // heap pointer member (e.g. owned string buffer)
    extern void* g_009745dc;   // vtable slot of the static prop object
    extern char  g_0080b730[]; // vtable of base descriptor class
}

// INFERRED: atexit destructor for RBX::Sky::prop_SkyRt
extern "C" void __cdecl fn_007fcdd0(void)
{
    if (g_009745f4)
        operator delete(g_009745f4);
    g_009745dc = (void*)g_0080b730;
}
