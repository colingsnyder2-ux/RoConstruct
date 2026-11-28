// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: prop_SoundEnabled is a file-local static whose destructor resets the vtable
// and frees a heap pointer at +0x18. The real class is unknown, so declare the globals
// as externs and the base vtable as an unknown global.
extern "C" void* g_00977730;
extern "C" void* g_00977718;
extern "C" char g_0080b730[]; // INFERRED: vtable of the base class, address taken only

extern "C" void fn_007fe5c0(void)
{
    if (g_00977730)
        operator delete(g_00977730);
    g_00977718 = (void*)g_0080b730; // INFERRED: base vtable pointer reset
}
