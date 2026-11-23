// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: class unknown; plain getter of dword at +0x70.
struct Fn004781c0Obj {
    char pad[0x70];
    int field70;
};

extern "C" int __fastcall fn_004781c0(Fn004781c0Obj* self, int unusedEdx)
{
    return self->field70;
}
