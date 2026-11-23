// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a this-pointer adjustor thunk (sub ecx,0x10; jmp real_method).
// The real method at 0x00568d40 is a __thiscall member, declared __fastcall with a dummy edx.
extern "C" void __fastcall fn_00568d40(void* self, int unusedEdx);

extern "C" void __fastcall fn_00568d20(char* self, int unusedEdx)
{
    fn_00568d40(self - 0x10, unusedEdx);
}
