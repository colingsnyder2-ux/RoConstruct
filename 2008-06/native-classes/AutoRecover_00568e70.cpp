// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the original is a this-adjustor thunk (`sub ecx, 0xa4; jmp 0x568d40`),
// i.e. a multiple-inheritance vtable entry forwarding to the primary-base
// implementation at 0x00568d40. The ABI checker classifies it as __cdecl (no
// stack cleanup), so it is expressed as a parameterless cdecl tail call; the
// ecx adjustment itself cannot be written in plain C++ without inline asm.
extern "C" void fn_00568d40();

extern "C" void fn_00568e70()
{
    fn_00568d40();
}
