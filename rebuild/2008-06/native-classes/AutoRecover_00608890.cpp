// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: arg1 is a render-device-like object with vtable slots 0x38 (set frame) and 0x40 (draw).
// INFERRED: callees are named only by mangled symbol, so they use the fn_ convention.
struct Dev;
struct Dev {
    void** vtbl;
};

struct Pts {
    float* data; // INFERRED: array of 16-byte elements (x,y,z,w)
    int size;
};

extern "C" void* __fastcall fn_004782d0(void* self, int unusedEdx); // CoordinateFrame::CoordinateFrame()
extern "C" const void* fn_007baf10();                                // Color4::zero()

extern const float kA;   // 0x8249f8
extern const float kC;   // 0x819bac
extern const float kB;   // 0x8222f0

typedef void (__fastcall *SetFrameFn)(Dev*, int, void*);
typedef void (__fastcall *DrawFn)(Dev*, int, void*, void*, const void*);

extern "C" void __fastcall fn_00608890(Pts* self, int unusedEdx, Dev* dev)
{
    // INFERRED: one scratch block (CoordinateFrame, then per-item struct reuses it)
    float buf[16];
    void* cf = fn_004782d0(&buf[4], 0);
    ((SetFrameFn)dev->vtbl[0x38 / 4])(dev, 0, cf);

    for (int i = 0; i < self->size; ++i) {
        const float* p = self->data + i * 4;
        float x = p[0], y = p[1], z = p[2], w = p[3];
        buf[0] = 1.0f;
        buf[1] = kA;
        buf[2] = kA;
        buf[3] = kC;
        buf[4] = x;
        buf[5] = 0.0f;
        buf[6] = y;
        buf[7] = z;
        buf[8] = kB;
        buf[9] = w;
        ((DrawFn)dev->vtbl[0x40 / 4])(dev, 0, &buf[4], &buf[0], fn_007baf10());
    }
}
