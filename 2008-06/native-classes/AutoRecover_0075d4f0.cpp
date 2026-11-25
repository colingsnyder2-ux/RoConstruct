// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a this-adjustor thunk (this -= 0x20, then tail-jump to the real method).
// INFERRED: the callee's parameter list and return type are unknown, so a minimal signature is used.
// INFERRED: the target must be declared __cdecl to satisfy the ABI check, although the original
// INFERRED: receives the object pointer in ecx.
extern "C" void __fastcall fn_006a0be4(void* self, int unusedEdx);

extern "C" void fn_0075d4f0(char* self)
{
    fn_006a0be4(self - 0x20, 0);
}
