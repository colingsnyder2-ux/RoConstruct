// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: unknown class; the function returns the byte at offset 0x61 of this.
struct Fn_005526b0_Obj {
    char pad[0x61];
    unsigned char value;
};

extern "C" unsigned char __fastcall fn_005526b0(Fn_005526b0_Obj* self, int unusedEdx)
{
    return self->value;
}
