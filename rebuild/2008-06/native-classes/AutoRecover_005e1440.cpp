// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: thiscall adjustor thunk; this -= 0x10, then tail jump to fn_005e1470 (stack args forwarded unchanged).
extern "C" int __fastcall fn_005e1470(void* self, int unusedEdx);

extern "C" int __fastcall fn_005e1440(void* self, int unusedEdx)
{
    return fn_005e1470((char*)self - 0x10, unusedEdx);
}
