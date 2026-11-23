// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" void fn_00596cd0(const function_buffer* in_buffer, function_buffer* out_buffer, int op);

// INFERRED: unknown global at 0x00949af8 (vtable-like / static table); only its address is stored.
extern "C" char g_00949af8[];

// INFERRED: argument types and return type; the disassembly only shows 32-bit values.
extern "C" int fn_00597040(int a0, void** a1, int a2)
{
    if (a2 == 3) {
        *a1 = (void*)g_00949af8;
        return a2; // eax still holds 3 on this path
    }

    // low byte of a2 is cleared in place, then reloaded
    int masked = a2 & ~0xff;
    // INFERRED: ecx/edx at the call are leftovers (masked, a1); modelled as self/unusedEdx.
    return fn_00596cd0((void*)masked, (int)a1, a0, (int)a1, a2, masked);
}
