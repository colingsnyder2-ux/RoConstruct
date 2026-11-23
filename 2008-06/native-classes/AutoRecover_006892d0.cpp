// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: partial draft. The disassembly was truncated at 0x689e8x, so only the
// prologue, the sin/cos table setup and the first switch case are recovered.
#include <string>

struct Painter {
    virtual void v00(); // INFERRED: slots up to 0xdc unnamed
    int pad[0];
};

struct ShapeParams {
    int mode;     // 0x00
    char flag4;   // 0x04
    int flag8;    // 0x08
    int kind;     // 0x0c
    float f10;    // 0x10
    float pad14[3];
    float ox, oy, oz; // 0x20,0x24,0x28
};

extern "C" int fn_006a0920(int a1);

extern "C" void fn_006892d0(ShapeParams* self, int unusedEdx, void* ctx, void* dev,
                            float scale, int cols, int rows, int a5, int a6, int a7, int a8)
{
    // INFERRED: names guessed. Full body is not recoverable from the truncated listing.
    static const float PI_ = 3.14159265f; // INFERRED: really Ogre::Math::PI via import
    float sinX[0xf0], cosX[0xf0], sinY[0xf0], cosY[0xf0];
    float sinX2[0xf0], cosX2[0xf0];
    float sinY2[0xf0], cosY2[0xf0];
    if (cols >= 0xf0) cols = 0xef;
    if (rows >= 0xf0) rows = 0xef;
    if (cols < 2 || rows < 1 || scale == 0.0f)
        return;
    bool wide = (self->mode == 0);
    bool b2f = false;
    if (self->mode == 1) {
        b2f = (self->kind != 0);
        if (self->kind == 1)
            wide = true;
    }
    for (int i = 0; i < cols; ++i) {
        float a = (float)i * PI_ * scale / (float)rows;
        sinX[i] = 0; cosX[i] = 0;
        (void)a;
    }
    (void)sinY; (void)cosY; (void)sinX2; (void)cosX2; (void)sinY2; (void)cosY2;
    (void)wide; (void)b2f; (void)ctx; (void)dev;
    (void)a5; (void)a6; (void)a7; (void)a8;
}
