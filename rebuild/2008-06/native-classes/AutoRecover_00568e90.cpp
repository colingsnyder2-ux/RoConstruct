// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a this-adjusting thunk (e.g. a secondary-base entry point).
// It subtracts 0x44 from ecx and tail-jumps to fn_00568d40. The callee's
// signature is unknown, so it is declared as a __thiscall member helper
// with no extra arguments.
extern "C" int __fastcall fn_00568d40(void* self, int unusedEdx);

extern "C" int __fastcall fn_00568e90(void* self, int unusedEdx)
{
    return fn_00568d40((char*)self - 0x44, unusedEdx);
}
