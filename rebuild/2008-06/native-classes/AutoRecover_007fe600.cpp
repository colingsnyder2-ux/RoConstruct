// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout of the BoundProp object as seen by the atexit destructor:
// vtable at +0x00, a heap-owned pointer at +0x18.
struct BoundPropLayout {
    void* vtable;
    int pad[5];
    void* owned;
};

extern "C" BoundPropLayout g_00977734;
// INFERRED: base-class vtable symbol written back during destruction
extern "C" void* g_0080b730[];

extern "C" void __cdecl fn_007fe600(void)
{
    // INFERRED: the dynamic atexit destructor deletes the owned member, then resets the vtable
    void* p = g_00977734.owned;
    if (p) {
        ::operator delete(p);
    }
    g_00977734.vtable = (void*)g_0080b730;
}
