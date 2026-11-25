// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

struct FakeBoundProp {
    void* vtable;       // 0x973d54
    char pad[0x14];
    void* heapMember;   // 0x973d6c
};

// INFERRED: layout of the static BoundProp<TextureId,1> object
extern FakeBoundProp g_00973d54;
// INFERRED: base vtable address 0x80b730
extern char g_0080b730[];

extern "C" void fn_007fc8e0(void)
{
    if (g_00973d54.heapMember)
        ::operator delete(g_00973d54.heapMember);
    g_00973d54.vtable = g_0080b730;
}
