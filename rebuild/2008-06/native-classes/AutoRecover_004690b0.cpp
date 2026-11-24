// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: this-adjusting thunk (ecx -= 0x28, tail jump to 0x4690d0); return type unknown, void assumed.
extern "C" void __fastcall fn_004690d0(char* self, int unusedEdx);

extern "C" void __fastcall fn_004690b0(char* self, int unusedEdx)
{
    fn_004690d0(self - 0x28, unusedEdx);
}
