// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
struct Vec2 { int a, b; };
struct Holder { void* state; int pad; Vec2 value; };

// INFERRED: vtable-like global at 0x826df8 stored into state
extern "C" char g_00826df8[];

// INFERRED: StringConverter<CoordinateFrame>::convertToValue, cdecl, one stack arg
extern "C" char fn_0060a2f0(Vec2* out);

extern "C" Holder* __fastcall fn_004dba40(Holder* self, int unusedEdx, int a1, int a2, int a3)
{
    Vec2 v;
    v.a = a1;
    v.b = a2;
    self->state = 0;
    if (!fn_0060a2f0(&v)) {
        Vec2* p = &self->value;
        if (p) *p = v;
        self->state = g_00826df8;
        return self;
    }
    self->state = 0;
    return self;
}
