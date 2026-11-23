// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: this is a this-adjusting thunk. Subtract 0x84 from ecx, then tail-jump to 0x5e1de0.
extern "C" int __fastcall fn_005e1de0(void* self, int unusedEdx);

extern "C" int __fastcall fn_005e1ce0(char* self, int unusedEdx)
{
    return fn_005e1de0(self - 0x84, unusedEdx);
}
