// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no Accoutrement class header was available, so the adjustor thunk is written
// as a plain C-linkage function instead of the real
// RBX::Accoutrement::`vector deleting destructor'`adjustor{164}' member.
// INFERRED: 0x5b15c0 is the primary vector deleting destructor of RBX::Accoutrement
// (__thiscall: this in ecx, flags on the stack, callee pops), declared here as __fastcall
// with a dummy edx argument.
extern "C" void* __fastcall fn_005b15c0(void* self, int unusedEdx, unsigned int flags);

// INFERRED: the target is reported as __cdecl, so the object pointer and flags are taken
// as ordinary stack parameters. The original code subtracts 0xa4 from this and tail-jumps
// to the primary deleting destructor.
extern "C" void* __cdecl fn_005b0f40(void* self, unsigned int flags)
{
    // this -= 164; forward to the real deleting destructor.
    return fn_005b15c0((void*)((unsigned int)self - 0xa4u), 0, flags);
}
