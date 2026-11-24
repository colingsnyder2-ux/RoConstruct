// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a this-adjustor thunk. It subtracts 0x2c from ecx (a secondary
// base subobject back to the primary object) and tail-jumps to the function at 0x4690d0.
extern "C" void __fastcall fn_004690d0(void* self, int unusedEdx);

extern "C" void __fastcall fn_004690c0(void* self, int unusedEdx)
{
    fn_004690d0(reinterpret_cast<char*>(self) - 0x2c, unusedEdx);
}
