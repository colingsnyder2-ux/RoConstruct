// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the destructor of the static BoundProp<TextureId,1> prop_SkyRt frees a
// pointer-sized member at 0x97a680 (operator delete) and then resets the
// vtable-like field at 0x97a668 to the base-class vtable at 0x80b730.
extern "C" void* g_0097a680;
extern "C" void* g_0097a668;
extern "C" char g_0080b730[];

void __cdecl operator_delete_stub(void* p);

extern "C" void __cdecl fn_007ff6a0(void)
{
    // body reproduces the disassembly
    void*& member = *reinterpret_cast<void**>(&g_0097a680);
    if (member) {
        ::operator delete(member);
    }
    *reinterpret_cast<void**>(&g_0097a668) = g_0080b730;
}
