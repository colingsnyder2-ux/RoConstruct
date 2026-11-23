// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a this-adjustor thunk (ecx -= 0x170, then jump to the real
// member function). The callee's real signature is unknown, so ecx and edx are
// forwarded unchanged and the return value is treated as int.
extern "C" int __fastcall fn_00568d40(void* self, int unusedEdx);

extern "C" int __fastcall fn_00568e80(void* self, int unusedEdx)
{
    return fn_00568d40((char*)self - 0x170, unusedEdx);
}
