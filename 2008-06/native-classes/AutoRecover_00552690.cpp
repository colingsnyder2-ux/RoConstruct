// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: class unknown; getter returns byte at offset 0x60.
struct Obj60 {
    char pad[0x60];
    unsigned char value;
};

extern "C" unsigned char __fastcall fn_00552690(Obj60* self, int unusedEdx)
{
    return self->value;
}
