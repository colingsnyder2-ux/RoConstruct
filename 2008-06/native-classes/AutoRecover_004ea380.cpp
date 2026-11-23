// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the layout of this class is unknown. It is a vtable-like pointer at +0
// and an 8-byte payload at +8. The payload is initialised from the first two stack
// arguments and passed by pointer to the converter.

struct Pair8 {
    int a;
    int b;
};

struct ConvResult {
    void* vtbl;   // +0
    int   pad;    // +4
    Pair8 value;  // +8
};

// INFERRED: unknown global at 0x00826f7c (probably a static vtable / type descriptor
// whose address is stored in the object on success).
extern "C" int g_00826f7c[];

// StringConverter<G3D::CoordinateFrame>::convertToValue, called cdecl with one pointer argument.
extern "C" bool fn_0060a2f0(Pair8* io);

extern "C" ConvResult* __fastcall fn_004ea380(ConvResult* self, int unusedEdx, int arg1, int arg2, int arg3)
{
    Pair8 local;
    local.a = arg1;
    local.b = arg2;
    self->vtbl = 0;
    if (!fn_0060a2f0(&local)) {
        ConvResult* p = self;
        if (&p->value) {
            p->value.a = local.a;
            p->value.b = local.b;
        }
        self->vtbl = g_00826f7c;
        return self;
    }
    self->vtbl = 0;
    return self;
}
