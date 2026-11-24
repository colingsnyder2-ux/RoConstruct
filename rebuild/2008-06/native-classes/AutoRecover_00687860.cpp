// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: disassembly is truncated at 0x6882fe. This draft covers the prologue, the sin/cos tables and the first (mode 0) arc outline only.
#include <math.h>
#include <string>

struct Canvas {
    virtual void v00() {}
};

struct ArcStyle {
    unsigned int segments;   // +0
    bool outline;            // +4
    int flip;                // +8
    int mode;                // +0xc
    float lineWidth;         // +0x10
    float pad[3];
    float color[3];          // +0x20..+0x28
};

extern "C" Canvas* __fastcall fn_00687860_getCanvas(void* self, int unusedEdx, void* a);
extern "C" int __fastcall fn_004de250(void* self, int unusedEdx, int a1);

extern "C" void __fastcall fn_00687860(ArcStyle* self, int unusedEdx, void* host, Canvas* canvas,
                                       int a3, float startAngle, float sweep, int steps,
                                       int rings, float a8, float radiusScale)
{
    float sinT[0x1e1];
    float cosT[0x1e1];

    if (!canvas)
        canvas = fn_00687860_getCanvas(host, 0, canvas);

    if (steps >= 0xf0)
        steps = 0xef;
    else if (steps < 2)
        return;
    if (rings < 1)
        return;
    if (sweep == 0.0f || startAngle == 0.0f)
        return;

    const float step = (sweep * 3.14159265f * a8) / (float)steps;
    for (int i = 0; i <= steps; ++i) {
        float a = startAngle + step * (float)i;
        sinT[i] = (float)sin((double)a);
        cosT[i] = (float)cos((double)a);
    }
    (void)sinT; (void)cosT; (void)self; (void)radiusScale; (void)a3;
}
