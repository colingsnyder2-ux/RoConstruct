// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout of the static BoundProp<TextureId,1> prop_SkyRt object:
// vtable at +0x00 (0x976cb0), a heap pointer at +0x18 (0x976cc8).
struct PropSkyRtLayout {
    const void* vtable;
    char pad[0x14];
    void* heapPtr;
};

extern PropSkyRtLayout g_00976cb0;
extern const char g_0080b730[];

extern "C" void __cdecl fn_007fe1e0(void)
{
    if (g_00976cb0.heapPtr)
        operator delete(g_00976cb0.heapPtr);
    g_00976cb0.vtable = g_0080b730;
}
