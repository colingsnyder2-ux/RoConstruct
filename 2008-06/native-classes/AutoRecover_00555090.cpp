// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: The jump target accepts the adjusted object pointer in ECX.
extern "C" void __fastcall fn_00422c60(void* self);

// INFERRED: A cdecl argument supplies the object pointer.
// This cannot reproduce the original ECX-based entry without assembly.
extern "C" void __fastcall fn_00555090(char* self)
{
    fn_00422c60(self + 8);
}
