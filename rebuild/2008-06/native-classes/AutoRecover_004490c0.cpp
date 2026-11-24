// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: object layout; only the two floats at +0x14c (lower bound) and +0x150 (value) are used.
struct ClampedFloatObject {
    char  pad[0x14c];
    float minValue;   // +0x14c
    float value;      // +0x150
};

// INFERRED: global float upper bound at 0x8163a4
extern "C" float g_float_008163a4;
// INFERRED: property descriptor at 0x96d49c, passed to the change notifier
extern "C" char g_desc_0096d49c[];

// INFERRED: tail-called thiscall helper (property-changed raise) taking a descriptor pointer
extern "C" void __fastcall fn_0040db00(ClampedFloatObject* self, int unusedEdx, const void* desc);

extern "C" void __fastcall fn_004490c0(ClampedFloatObject* self, int unusedEdx, float v)
{
    float upper = g_float_008163a4;
    const float* p = (v > self->minValue) ? &v : &self->minValue;
    if (!(upper > *p))
        p = &upper;
    float result = *p;
    if (self->value != result) {
        self->value = result;
        fn_0040db00(self, 0, g_desc_0096d49c);
    }
}
