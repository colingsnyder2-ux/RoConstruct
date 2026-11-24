// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: adjustor thunk, this -= 0x84 then tail jump to 0x5e1470; callee signature assumed (this only).
extern "C" void __fastcall fn_005e1470(void* self, int unusedEdx);

extern "C" void __fastcall fn_005e1420(void* self, int unusedEdx)
{
    fn_005e1470((char*)self - 0x84, unusedEdx);
}
