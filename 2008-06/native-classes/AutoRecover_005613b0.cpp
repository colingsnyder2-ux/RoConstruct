// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: 4th arg is a by-value tag; the disassembly passes (op & ~0xff).
extern "C" void fn_00560f00(const void* const* in, void** out, int op, int tag);

// INFERRED: unknown global at 0x944430 (type_info / vtable-like pointer stored for the get_functor_type case).
extern "C" char g_00944430;

extern "C" void fn_005613b0(const void* const* in, void** out, int op)
{
    if (op == 3) {
        *out = &g_00944430;
        return;
    }
    fn_00560f00(in, out, op, op & ~0xff);
}
