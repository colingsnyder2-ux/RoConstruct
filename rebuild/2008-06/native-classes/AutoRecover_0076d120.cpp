// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: The jump target receives its object pointer in ECX.
extern "C" void __fastcall fn_0076d0e0(void* self);

// INFERRED: A cdecl parameter is stack-passed, so this cannot reproduce the
// original ECX adjustment exactly without a different ABI or inline assembly.
extern "C" void __fastcall fn_0076d120(void* self)
{
    fn_0076d0e0(static_cast<char*>(self) + 4);
}
