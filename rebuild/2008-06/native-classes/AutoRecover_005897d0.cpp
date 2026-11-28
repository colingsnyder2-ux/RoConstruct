// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the original is an adjustor thunk (add ecx,4; jmp fn_00589720), so `this` arrives in ecx.
// The harness requires a __cdecl definition, and plain C++ cannot read ecx from a cdecl function
// without inline asm. So `self` is declared as an ordinary cdecl parameter. This is an approximation.
// INFERRED: the callee's return type and arguments are unknown, so it is declared void.
extern "C" void __fastcall fn_00589720(void* self);

extern "C" void __fastcall fn_005897d0(char* self)
{
    fn_00589720(self + 4);
}
