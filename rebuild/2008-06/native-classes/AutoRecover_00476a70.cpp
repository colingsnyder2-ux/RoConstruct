// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: class layout unknown; only touched fields declared via offsets.
struct GLState {
    char pad0[0x70];
    int counterA;          // 0x70
    char pad1[0x04];
    int counterB;          // 0x78
    char pad2[0x45c - 0x7c];
    float color[3];        // 0x45c..0x464
};

// INFERRED: global GL material cache (ambient-ish vec4) at 0x96f024
extern float g_materialCache[4];

extern "C" void __stdcall glMaterialfv(unsigned int face, unsigned int pname, const float* params);

extern "C" void __fastcall fn_00476a70(GLState* self, int unusedEdx, const float* v)
{
    self->counterB++;
    if (v[0] != self->color[0] || v[1] != self->color[1] || v[2] != self->color[2]) {
        self->color[0] = v[0];
        self->color[1] = v[1];
        self->color[2] = v[2];
        g_materialCache[0] = v[0];
        g_materialCache[1] = v[1];
        g_materialCache[2] = v[2];
        g_materialCache[3] = 1.0f;
        glMaterialfv(0x408, 0x1202, g_materialCache);
        self->counterA++;
    }
}
