// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0080b730[];   // INFERRED: unnamed global at 0x0080b730 in the original
// INFERRED: static BoundProp<TextureId,1> destructor frees a heap pointer member
// (global at 0x97be78), then resets a vtable pointer (global at 0x97be5c = ((int)&g_0080b730)).
// Modeled as raw globals since the BoundProp layout is not available here.
extern "C" void fn_006a067a(void* p);

struct BoundPropTexLayout {
    void* vtbl;                 // at 0x97be5c
    char pad[0x18 - 4];
    void* heapPtr;              // at 0x97be78
};

extern BoundPropTexLayout g_prop_SkyRt;

static void __cdecl dtor_prop_SkyRt()
{
    if (g_prop_SkyRt.heapPtr)
        fn_006a067a(g_prop_SkyRt.heapPtr);
    g_prop_SkyRt.vtbl = (void*)((int)&g_0080b730);
}
