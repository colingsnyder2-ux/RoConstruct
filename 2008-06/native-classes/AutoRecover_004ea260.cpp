// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout of the object and of the two-dword local are guesses from the disassembly.
struct Pair8 {
    int a;
    int b;
};

struct Result8 {
    const void* tag;  // [esi+0]
    int pad;          // [esi+4]
    Pair8 value;      // [esi+8]
};

// INFERRED: unknown global whose address is stored at [self] (was constant 0x826f64).
extern "C" char g_00826f64[];

// StringConverter<CoordinateFrame>::convertToValue; the single stack arg is cleaned up by the caller.
// INFERRED: the signature and return type are guesses.
extern "C" bool fn_0060a2f0(Pair8* p);

extern "C" Result8* __fastcall fn_004ea260(Result8* self, int unusedEdx, int arg1, int arg2, int arg3)
{
    Pair8 local;
    local.a = arg1;
    local.b = arg2;
    self->tag = 0;
    if (!fn_0060a2f0(&local)) {
        Pair8* dst = &self->value;
        if (dst) {
            dst->a = local.a;
            dst->b = local.b;
        }
        self->tag = g_00826f64;
        return self;
    }
    self->tag = 0;
    return self;
}
