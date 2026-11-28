// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

#pragma float_control(precise, off)

// INFERRED: Field layout from the access at offset 0x154.
struct Explosion {
    char padding[0x154];
    float blastRadius;
};

// INFERRED: Property descriptor, limit, and notification helper.
extern char g_0097bfd4;
extern float g_008163a4;
extern "C" void __fastcall fn_0040db00(Explosion* self, int unusedEdx, const void* property);

extern "C" void __fastcall fn_0062b5c0(Explosion* self, int unusedEdx, float radius)
{
    // INFERRED: Candidate source; byte-exact codegen is unverified.
    float newRadius = radius > 0.0f
        ? (g_008163a4 < radius ? g_008163a4 : radius)
        : 0.0f;
    if (self->blastRadius != newRadius) {
        self->blastRadius = newRadius;
        fn_0040db00(self, unusedEdx, &g_0097bfd4);
    }
}
