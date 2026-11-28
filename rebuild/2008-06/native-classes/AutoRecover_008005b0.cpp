// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: static BoundProp<TextureId,1> RBX::Sky::prop_SkyRt atexit destructor.
// Frees heap pointer at 0x97c818 (operator delete), then stores vtable 0x80b730 at 0x97c800.
extern "C" void __cdecl fn_006a067a(void* p);

struct BoundPropTextureIdSkyRt {
    void* vtable;
    char pad[0x18 - 4];
    void* heapPtr;
};

extern "C" BoundPropTextureIdSkyRt g_0097c800;
extern "C" char g_0080b730[];

extern "C" void fn_008005b0(void)
{
    if (g_0097c800.heapPtr)
        fn_006a067a(g_0097c800.heapPtr);
    g_0097c800.vtable = g_0080b730;
}
