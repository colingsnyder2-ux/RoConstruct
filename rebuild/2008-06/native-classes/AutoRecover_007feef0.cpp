// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: static BoundProp layout: vptr at +0, heap-owned pointer at +0x18
extern "C" void* g_00979cd4;
extern "C" void* g_00979cbc;

// INFERRED: vtable address of the base class (0x80b730) written back by the dtor
extern "C" char g_0080b730[];

extern "C" void fn_007feef0(void)
{
    void* p = g_00979cd4;
    if (p) {
        operator delete(p);
    }
    g_00979cbc = (void*)g_0080b730;
}
