// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: unknown class; a simple getter returning a byte member at offset 0xad.
struct Fn_0047edf0_Class {
    char pad[0xad];
    unsigned char value;
};

extern "C" unsigned char __fastcall fn_0047edf0(Fn_0047edf0_Class* self, int unusedEdx)
{
    return self->value;
}
