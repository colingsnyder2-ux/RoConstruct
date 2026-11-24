// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no Workspace header was available, so the real class-member name
// of this compiler-generated adjustor thunk cannot be written directly. The
// fn_<addr> convention is used instead. The thunk adjusts `this` by -16 and
// tail-jumps to the primary vector deleting destructor at 0x005a3050.
// INFERRED: because the thunk's own code is a bare `jmp` with no `ret`, its ABI
// is modelled as __cdecl (caller pops), with `this` and the flags passed as
// plain arguments.

extern "C" void* fn_005a3050(void* self, unsigned int flags);

extern "C" void* fn_005a2c80(void* self, unsigned int flags)
{
    return fn_005a3050((char*)self - 16, flags);
}
