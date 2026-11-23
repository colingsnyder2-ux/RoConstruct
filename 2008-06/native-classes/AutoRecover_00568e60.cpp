// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" int __fastcall fn_00568d40(void* self, int unusedEdx);

// INFERRED: this-adjusting thunk (secondary base at +0x84 to the primary object), which tail-jumps to fn_00568d40. Evidence: "sub ecx, 0x84; jmp 0x568d40" is the whole body.
extern "C" int __fastcall fn_00568e60(void* self, int unusedEdx)
{
    return fn_00568d40(static_cast<char*>(self) - 0x84, unusedEdx);
}
