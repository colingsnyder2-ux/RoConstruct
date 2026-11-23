// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: best-effort draft. Class and header layouts are unknown, so everything is declared locally with extern "C" fn_ names.
// Fix for the earlier C2148: the pad array after the vector had a negative size. The vectors at 0x2a4 and 0x2b0 are one std::vector<unsigned char> (first at 0x2b0, last at 0x2b4), so there is now a single member and no trailing pad.
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>

struct Obj;
struct Vec3 { float x, y, z; };

// INFERRED: 0x278 flag selects the visibility query, 0x27a flag selects the "mark selected" output.
struct Self {
    void** vtbl;
    char pad0[0xe0];
    Obj** itemsBegin;                       // 0xe4
    Obj** itemsEnd;                         // 0xe8
    char pad1[0x274 - 0xec];
    void* history;                          // 0x274 FrameHistory*
    bool flag278;
    char pad2;
    bool flag27a;
    char pad3[0x29c - 0x27b];
    float ratio;                            // 0x29c
    int minCount;                           // 0x2a0
    std::vector<unsigned char> state;       // 0x2a4 (first at 0x2b0, last at 0x2b4)
};

struct Frame { float a, b, c; };

extern "C" int fn_006a0920(int a1);
extern "C" int __fastcall fn_0065b430(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int __fastcall fn_0065aee0(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5);
extern "C" int __fastcall fn_006740e0(void* self, int unusedEdx, int a1);
extern "C" Frame* __fastcall fn_00678630(void* self, int unusedEdx, int ago);
extern "C" float __fastcall fn_00679990(void* self, int unusedEdx, int n);
extern "C" void __fastcall fn_006785f0(void* self, int unusedEdx, const void* frame);

extern bool g_enabled;  // 0x962f64
extern float g_k0;      // 0x962f6c
extern float g_k1;      // 0x962f70

extern "C" void __fastcall fn_0067daf0(Self* self, int unusedEdx, void* arg1)
{
    std::vector<double> dists;
    bool enabled = g_enabled && self->history;
    size_t n = self->itemsEnd - self->itemsBegin;

    if (enabled) {
        dists.resize(n);
    }
    if (n) {
        self->state.resize(n, 0);
        memset(&self->state[0], 0, self->state.size());
    }
    // INFERRED: per-item visibility pass; decompiled control flow incomplete.
    for (size_t i = 0; i < n; ++i) {
        self->state[i] = 2;
    }
    if (enabled) {
        int count = (int)dists.size();
        std::sort(dists.begin(), dists.end());
        for (int i = 0; i < count; ++i) {
            self->state[i] = 3;
        }
    }
}
