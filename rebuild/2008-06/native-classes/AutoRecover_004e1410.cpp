// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: partial recovery. The disassembly was truncated at 0x4e1f64, so the tail of the function is missing.
// INFERRED: all types are local stand-ins because no header excerpt was available.
#include <stdlib.h>
#include <math.h>

struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
struct Rect2 { float x0, y0, x1, y1; };
struct IndexArray { unsigned* data; int num; int alloc; };
struct MeshData { char pad[0xc]; IndexArray indices; };

extern "C" void fn_005ec200(Vec3* out, const Vec3* uvw);
extern "C" unsigned fn_00548000(const Vec3* pos, const Vec3* normal, const Vec2* uv, bool flag);
extern "C" void fn_004dc6a0(IndexArray* arr, const unsigned* a, const unsigned* b, const unsigned* c, const unsigned* d);

// INFERRED: static jitter state used when the 0x97275c flag is clear
static float s_jitter[4];

extern "C" void fn_004e1410(const Vec3* uvw, float size, unsigned faceBits, float pad, MeshData** mesh, unsigned* outVerts)
{
    unsigned face = (faceBits >> 12) & 7;

    Vec3 obj;
    fn_005ec200(&obj, uvw);

    float hx = size - fabsf(obj.x);
    float hy = size - fabsf(obj.y);
    float hz = size - fabsf(obj.z);
    (void)hx; (void)hy; (void)hz; (void)face; (void)pad;

    // INFERRED: build one quad from four allocVertex calls and append its indices
    Vec3 p = { 0, 0, 0 };
    Vec3 n = { 0, 0, 1 };
    Vec2 uv = { 0, 0 };
    unsigned v0 = fn_00548000(&p, &n, &uv, true);
    unsigned v1 = fn_00548000(&p, &n, &uv, true);
    unsigned v2 = fn_00548000(&p, &n, &uv, true);
    unsigned v3 = fn_00548000(&p, &n, &uv, true);

    fn_004dc6a0(&(*mesh)->indices, &v0, &v1, &v2, &v3);

    outVerts[0] = v0;
    outVerts[1] = v1;
    outVerts[2] = v2;
    outVerts[3] = v3;
}
