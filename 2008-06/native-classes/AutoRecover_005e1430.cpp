// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: this-adjustor thunk (this -= 0xc4, tail-jump). Callee's return type and stack args are unknown, so it is declared as taking only ecx/edx and returning int.
extern "C" int __fastcall fn_005e1470(char* self, int unusedEdx);

extern "C" int __fastcall fn_005e1430(char* self, int unusedEdx)
{
    return fn_005e1470(self - 0xc4, unusedEdx);
}
