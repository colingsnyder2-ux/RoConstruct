// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: This is a best-effort reconstruction. The disassembly was truncated
// near its end, and no native headers were provided, so the types below are
// minimal local stand-ins. It does not match the original machine code
// instruction for instruction.
#include <stdlib.h>
#include <math.h>
#include <vector>

struct Vector2 { float x, y; };
struct Vector3 { float x, y, z; };
struct Rect2D  { float x0, y0, x1, y1; };

struct UIntArray;   // G3D::Array<unsigned int>

// Callees use the fixed fn_<addr> naming convention because no headers were provided.
extern "C" Vector3* fn_005ec1e0(Vector3* ret, const Vector3* in);                  // RBX::uvwToObject<2>
extern "C" Vector2* __fastcall fn_005185d0(const Rect2D* self, int, Vector2* ret); // Rect2D::x0y0
extern "C" unsigned fn_00548000(const Vector3* pos, const Vector3* nrm,
                                const Vector2* uv, bool flag);                      // Mesh::allocVertex
extern "C" void __fastcall fn_004dc6a0(UIntArray* self, int, const unsigned* a,
                                       const unsigned* b, const unsigned* c,
                                       const unsigned* d);                          // Array<uint>::append

struct MeshTarget { int pad[3]; UIntArray* indices; };  // INFERRED: array lives at +0xC of *arg

// Tuning constants (values live in .rdata in the original).
// INFERRED: exact values unknown.
static const float kHalf     = 0.5f;
static const float kRandScale = 2.0f / 32767.0f;
static const float kRandBias  = 1.0f;
static const float kRandThr   = 1.0f / 32767.0f;
static const float kStep      = 1.0f;

// Statics from the original (0x97275c, 0x97280c..0x972810, 0x972804..0x972808, 0x9727ec).
static bool  s_randInit = false;
static float s_jx0, s_jy0, s_jx1, s_jy1;
static std::vector<unsigned> s_verts;

extern "C" void fn_004e07e0(const Vector3* uvw, float size, unsigned flags,
                            float bias, MeshTarget** target, unsigned* outQuad)
{
    unsigned face = (flags >> 9) & 7;

    Vector3 obj;
    fn_005ec1e0(&obj, uvw);

    Rect2D r;
    r.x0 = (float)fabs((double)obj.x) - size;
    r.y0 = (float)fabs((double)obj.y) - size;
    r.x1 = (float)fabs((double)obj.z);
    r.y1 = 0.0f;

    float ox = 0.0f, oy = 0.0f, oz = 0.0f;
    switch (face) {
    case 0: {
        Vector2 o;
        fn_005185d0(&r, 0, &o);
        ox = o.x * kHalf;
        oy = o.y * kHalf;
        break;
    }
    case 1: ox = kHalf; oy = kHalf; break;
    case 2: ox = kHalf; oy = kHalf; oz = kHalf; break;
    case 3: ox = kHalf; oy = kHalf; oz = kHalf; break;
    case 4: ox = kHalf; oy = kHalf; oz = kHalf; break;
    default: break;
    }

    float base = oz + bias * kStep;
    (void)base;

    float jx, jy, kx, ky;
    if (!s_randInit) {
        jx = (float)rand() * kRandScale - kRandBias;
        jy = (float)rand() * kRandScale - kRandBias;
        kx = (float)rand() * kRandThr > 0.0f ? -jx : jx;
        ky = (float)rand() * kRandThr > 0.0f ? -jy : jy;
        s_jx0 = jx; s_jy0 = jy; s_jx1 = kx; s_jy1 = ky;
        s_randInit = true;
    } else {
        jx = s_jx0; jy = s_jy0; kx = s_jx1; ky = s_jy1;
    }

    if (face == 0) {
        // Single quad: four vertices, append the indices.
        Vector3 p, n;
        Vector2 uv;
        unsigned v[4];

        uv.x = jx; uv.y = jy;
        fn_005ec1e0(&n, &obj);
        p.x = -r.x0; p.y = -r.y0; p.z = oy;
        fn_005ec1e0(&p, &p);
        v[0] = fn_00548000(&p, &n, &uv, true);

        uv.x = kx; uv.y = jy;
        fn_005ec1e0(&n, &obj);
        v[1] = fn_00548000(&p, &n, &uv, true);

        uv.x = kx; uv.y = ky;
        v[2] = fn_00548000(&p, &n, &uv, true);

        uv.x = jx; uv.y = ky;
        v[3] = fn_00548000(&p, &n, &uv, true);

        unsigned extra = 0;
        fn_004dc6a0((*target)->indices, 0, &v[0], &v[1], &v[2], &extra);

        outQuad[0] = v[0];
        outQuad[1] = v[1];
        outQuad[2] = v[2];
        outQuad[3] = extra;
        return;
    }

    // Tiled quads for the other faces.
    // INFERRED: grid walk over [x0..x1] x [y0..y1] with a vertex cache vector.
    r.x0 = -r.x0 * kHalf;
    r.y0 = -r.y0 * kHalf;
    Vector2 o;
    fn_005185d0(&r, 0, &o);
    float du = r.x0 / o.x;
    float dv = r.y0 / o.y;

    s_verts.clear();

    int row = 0;
    for (float y = ox; y < r.y1; y += kStep, ++row) {
        for (float x = oy; x < r.x1; x += kStep) {
            Vector3 p, n, q;
            Vector2 uv;
            unsigned a, b, c, d;

            uv.x = du + x; uv.y = dv;
            q.x = x; q.y = y; q.z = 1.0f;
            fn_005ec1e0(&n, &q);
            fn_005ec1e0(&p, &q);
            a = fn_00548000(&p, &n, &uv, true);
            b = fn_00548000(&p, &n, &uv, true);
            c = fn_00548000(&p, &n, &uv, true);
            d = fn_00548000(&p, &n, &uv, true);

            s_verts.push_back(a);
            s_verts.push_back(b);
            s_verts.push_back(c);
            s_verts.push_back(d);

            fn_004dc6a0((*target)->indices, 0, &a, &b, &c, &d);
        }
    }

    // INFERRED: the disassembly is cut off here; the remainder (writing the
    // result quad to outQuad from the last cached vertices) is assumed.
    if (s_verts.size() >= 4) {
        outQuad[0] = s_verts[s_verts.size() - 4];
        outQuad[1] = s_verts[s_verts.size() - 3];
        outQuad[2] = s_verts[s_verts.size() - 2];
        outQuad[3] = s_verts[s_verts.size() - 1];
    }
}
