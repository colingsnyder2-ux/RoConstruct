// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a this-adjustor thunk. It subtracts 0xa4 from ecx and tail-jumps to
// func_00568d40. The callee's real signature is unknown, so it is declared as a __thiscall
// member helper (__fastcall with a dummy edx argument), per the naming convention.
extern "C" void __fastcall fn_00568d40(void* self, int unusedEdx);

extern "C" void __fastcall fn_00568e70(char* self, int unusedEdx)
{
    fn_00568d40(self - 0xa4, unusedEdx);
}
