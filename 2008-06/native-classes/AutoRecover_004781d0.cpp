// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: unknown class; the function is a plain getter for the dword at offset 0x74.
struct Fn_004781d0_Class {
    char pad[0x74];
    int value;
};

extern "C" int __fastcall fn_004781d0(Fn_004781d0_Class* self, int unusedEdx)
{
    return self->value;
}
