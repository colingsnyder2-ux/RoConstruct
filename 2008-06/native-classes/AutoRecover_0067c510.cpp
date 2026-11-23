// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: owner class unknown (no header excerpt); file-local layout places the stored field at +0x274.
struct Func0067c510Self {
    char pad[0x274];
    int value;
};

extern "C" void __fastcall fn_0067c510(Func0067c510Self* self, int unusedEdx, int arg)
{
    self->value = arg;
}
