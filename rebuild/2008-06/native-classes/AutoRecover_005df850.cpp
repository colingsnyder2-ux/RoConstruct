// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a this-adjustor thunk (secondary base subobject at +0x44).
// It subtracts 0x44 from ecx and tail-jumps to the primary implementation.
extern "C" int __fastcall fn_005e1470(void* self, int unusedEdx);

extern "C" int __fastcall fn_005df850(char* self, int unusedEdx)
{
    return fn_005e1470(self - 0x44, unusedEdx);
}
