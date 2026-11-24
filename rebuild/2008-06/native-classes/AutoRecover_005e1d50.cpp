// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: thiscall thunk that adjusts this by -0x64 (secondary-base to primary-base) and tail-jumps.
extern "C" int __fastcall fn_005e1de0(void* self, int unusedEdx);

extern "C" int __fastcall fn_005e1d50(void* self, int unusedEdx)
{
    return fn_005e1de0((char*)self - 0x64, unusedEdx);
}
