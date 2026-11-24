// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: best-effort draft, not compiled or diffed. Types, field names and the
// constants K1..K5 are guesses from the disassembly.
struct Vec3f { float x, y, z; };
struct ColourValue { float r, g, b, a; };

struct LightArg {
    Vec3f dir;            // +0x00
    char pad[0x40];
    char useAlt;          // +0x4c
    Vec3f colA;           // +0x50
    Vec3f colB;           // +0x5c
};

struct IBillboardSet {
    virtual void v0();
};

// INFERRED: Ogre::Billboard::setColour imported from rgmain
extern "C" void __fastcall fn_setColour(void* self, int unusedEdx, const ColourValue* c);

extern const float K_scale;   // 0x819b48
extern const float K_bias;    // 0x81e704
extern const float K_mul;     // 0x827490
extern const float K_amb;     // 0x826cb4
extern const double K_d0;     // 0x84ae00
extern const double K_d1;     // 0x826fd0
extern const double K_d2;     // 0x84e560

struct LightOwner {
    char pad0[0x34];
    void** billboards;    // +0x34 (vtable slot 0xf8: get billboard by index)
    char pad1[4];
    void** billboards2;   // +0x3c
    void** sink;          // +0x40 (vtable slot 0x68: take 3 floats)
    char pad2[0x7c - 0x44];
    float pad3;
    char pad4[0xbc - 0x80];
    Vec3f lastColour;     // +0xbc
    char pad5[0x84 - 0xc8 + 0x44];
    // INFERRED: flag at +0x84 written separately below
};

extern "C" void __fastcall fn_0067f550(LightOwner* self, int unusedEdx, int unusedArg, LightArg* a)
{
    const Vec3f* c = a->useAlt ? &a->colA : &a->colB;
    float r = c->x, g = c->y, b = c->z;
    float vx = a->dir.x * K_scale;
    float vy = a->dir.y * K_scale;
    float vz = a->dir.z * K_scale;

    if (!(0.0f <= r)) {
        float t = (r + K_bias) * K_mul;
        float m = (r < t) ? t : r;
        vx *= m; vy *= m; vz *= m;
    }
    (void)g; (void)b; (void)K_amb; (void)K_d0; (void)K_d1; (void)K_d2;
    // INFERRED: remaining body (billboard colour updates through vtable +0xf8,
    // flag store at +0x84) not reconstructed.
    self->lastColour.x = vx;
    self->lastColour.y = vy;
    self->lastColour.z = vz;
}
