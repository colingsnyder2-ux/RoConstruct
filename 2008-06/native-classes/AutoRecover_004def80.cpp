// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: partial draft. The disassembly was truncated after 0x4dfacd, so the tail is not recovered.
// INFERRED: all callees are declared as fn_ externs, because no native headers were provided.
#include <stdlib.h>
#include <math.h>

struct V3 { float x, y, z; };
struct V2 { float x, y; };
struct UIntArray { char pad[0xc]; };
struct MeshHolder { UIntArray* arr; };

extern "C" V3* __cdecl fn_005ec1c0(V3* out, const V3* in);
extern "C" unsigned __cdecl fn_00548000(const V3* pos, const V3* normal, const V2* uv, bool flag);
extern "C" V2* __fastcall fn_005185d0(void* rect, int unusedEdx, V2* out);
extern "C" void __fastcall fn_004dc6a0(void* arr, int unusedEdx, const unsigned* a,
                                       const unsigned* b, const unsigned* c, const unsigned* d);

static float g_lastA, g_lastB, g_lastC, g_lastD;
static bool g_haveRand;

extern "C" void fn_004def80(const V3* size, float extent, unsigned flags, float offset,
                            MeshHolder** mesh, unsigned* outIndices)
{
    unsigned face = (flags >> 3) & 7;
    V3 obj;
    fn_005ec1c0(&obj, size);

    float ax = fabsf(obj.x), ay = fabsf(obj.y), az = fabsf(obj.z);
    float hx = extent - az, hy = extent - ay, hz = extent - ax;
    (void)hx; (void)hy; (void)hz; (void)face;

    float r0 = (float)rand();
    float r1 = (float)rand();
    g_lastA = r0; g_lastB = r1;
    g_lastC = r0; g_lastD = r1;

    // INFERRED: quad emit path (face 0), remaining face/ring path unrecovered.
    V3 p[4], n = { 0, 0, 1 };
    V2 uv = { 0, 0 };
    V3 t;
    unsigned idx[4];
    for (int i = 0; i < 4; ++i) {
        fn_005ec1c0(&t, &p[i]);
        idx[i] = fn_00548000(&t, &n, &uv, true);
    }
    fn_004dc6a0((char*)(*mesh) + 0xc, 0, &idx[0], &idx[1], &idx[2], &idx[3]);
    outIndices[0] = idx[0];
    outIndices[1] = idx[1];
    outIndices[2] = idx[2];
    outIndices[3] = idx[3];
}
