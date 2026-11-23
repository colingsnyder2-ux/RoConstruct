// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: unknown class; the function reads a byte-sized field at offset 0xac.
struct Fn0047edc0Self {
    char pad[0xac];
    unsigned char value;
};

extern "C" unsigned char __fastcall fn_0047edc0(Fn0047edc0Self* self, int unusedEdx)
{
    return self->value;
}
