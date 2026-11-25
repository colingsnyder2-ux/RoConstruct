// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: The destination receives the adjusted object pointer in ECX.
extern "C" void __fastcall fn_004ab8c0(void* self);

// INFERRED: A cdecl parameter supplies the object pointer; this cannot reproduce
// the original thunk's direct use of the incoming ECX register.
extern "C" void __fastcall fn_004ab950(void* self)
{
    fn_004ab8c0(static_cast<char*>(self) + 4);
}
