// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: partial draft. The disassembly was truncated, so the tail of the function is missing.
// INFERRED: no native headers were shown, so the types are file-local stand-ins.
#include <stdlib.h>
#include <math.h>

struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
struct Rect2D { Vec2 lo, hi; };
struct UIntArray;

extern "C" Vec3* __cdecl fn_005ec220(Vec3* out, const Vec3* uvw);
extern "C" unsigned __cdecl fn_00548000(const Vec3* pos, const Vec3* normal, const Vec2* uv, bool flag);
extern "C" void __fastcall fn_004dc6a0(UIntArray* self, int unusedEdx, const unsigned* a, const unsigned* b, const unsigned* c, const unsigned* d);

struct MeshOut { UIntArray* indexArrayBase() { return 0; } };

// INFERRED: arg layout from [ebp+8..0x1c]: uvw, extent, packed face bits, scale, mesh**, out[4]
extern "C" void __cdecl fn_004e2040(const Vec3* uvw, float extent, unsigned packed,
                                    float scale, char** mesh, unsigned* out)
{
    unsigned face = (packed >> 15) & 7;
    Vec3 o;
    fn_005ec220(&o, uvw);
    float ax = fabsf(o.x), ay = fabsf(o.y), az = fabsf(o.z);
    float hx = extent - az;
    float hy = extent - ay;
    float hz = extent - ax;
    (void)hx; (void)hy; (void)hz; (void)face; (void)scale;

    Vec3 n = { 0, 0, 1 };
    Vec3 p = { 0, 0, 0 };
    Vec2 uv = { 0, 0 };
    unsigned v0 = fn_00548000(&p, &n, &uv, true);
    unsigned v1 = fn_00548000(&p, &n, &uv, true);
    unsigned v2 = fn_00548000(&p, &n, &uv, true);
    unsigned v3 = fn_00548000(&p, &n, &uv, true);
    fn_004dc6a0((UIntArray*)(*mesh + 0xc), 0, &v0, &v1, &v2, &v3);
    out[0] = v0; out[1] = v1; out[2] = v2; out[3] = v3;
}
