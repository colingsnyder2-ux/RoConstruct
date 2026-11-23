// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a this-adjusting thunk (a secondary-base entry point) that
// subtracts 0xA4 from ecx and tail-jumps to the real method at 0x5e1de0.
// The real method is a __thiscall member, declared here as __fastcall with a dummy edx.
extern "C" int __fastcall fn_005e1de0(void* self, int unusedEdx);

extern "C" int __fastcall fn_005e1cf0(void* self, int unusedEdx)
{
    return fn_005e1de0(static_cast<char*>(self) - 0xa4, unusedEdx);
}
