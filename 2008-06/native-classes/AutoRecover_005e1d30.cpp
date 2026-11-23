// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: this-adjusting thunk (ecx -= 0x24, then tail jump) into fn_005e1de0
extern "C" void __fastcall fn_005e1de0(void* self, int unusedEdx);

extern "C" void __fastcall fn_005e1d30(char* self, int unusedEdx)
{
    fn_005e1de0(self - 0x24, unusedEdx);
}
