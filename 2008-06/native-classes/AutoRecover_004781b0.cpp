// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: class unknown; getter returns dword at +0x7c
struct Fn004781b0Obj {
    char pad[0x7c];
    int value;
};

extern "C" int __fastcall fn_004781b0(Fn004781b0Obj* self, int unusedEdx)
{
    return self->value;
}
