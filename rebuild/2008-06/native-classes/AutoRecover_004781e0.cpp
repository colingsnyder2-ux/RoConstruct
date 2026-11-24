// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: unnamed getter of the dword at offset 0x78; class unknown, use opaque struct.
struct Fn004781e0Self {
    char pad[0x78];
    int value;
};

extern "C" int __fastcall fn_004781e0(Fn004781e0Self* self, int unusedEdx)
{
    return self->value;
}
