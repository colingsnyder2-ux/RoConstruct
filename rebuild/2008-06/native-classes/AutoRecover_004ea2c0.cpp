// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

struct Pair8 { int a; int b; };

// INFERRED: StringConverter<T>::convertToValue(string const&, T&); string arrives in ecx (arg2), out pointer on stack.
extern "C" bool fn_0060a2f0(Pair8* out);

// INFERRED: unknown global whose address is stored at offset 0 (vtable/tag).
extern "C" int g_00826f6c;

struct Obj004ea2c0 {
    void* vtbl_or_tag;
    int pad4;
    Pair8 value;
};

extern "C" Obj004ea2c0* __fastcall fn_004ea2c0(Obj004ea2c0* self, int unusedEdx, int arg1, int arg2, int arg3)
{
    Pair8 v;
    v.a = arg1;
    v.b = arg2;
    self->vtbl_or_tag = 0;
    if (!fn_0060a2f0(&v)) {
        self->value = v;
        self->vtbl_or_tag = &g_00826f6c;
        return self;
    }
    self->vtbl_or_tag = 0;
    return self;
}
