// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the supplied disassembly is truncated at 004e06fd and no headers were shown.
// This is an approximate reconstruction, not a verified match. The types are local stand-ins
// and the callees are declared with the fn_<addr> convention.
#include <cstdlib>
#include <cmath>
#include <vector>

namespace {

struct Vector2 { float x, y; };
struct Vector3 { float x, y, z; };
struct Rect2D  { float x0, y0, x1, y1; };

// INFERRED: Array<unsigned> is embedded at offset 0xc of the mesh; only the address is needed here.
struct Mesh { char pad[0xc]; char indexArray[1]; };

}

// RBX::uvwToObject<1>(const Vector3&) -> Vector3 (hidden return pointer, cdecl)
extern "C" Vector3* fn_006784d0(Vector3* ret, const Vector3* in);
// G3D::Rect2D::x0y0() const (thiscall, hidden return pointer)
extern "C" Vector2* __fastcall fn_005185d0(Rect2D* self, int unusedEdx, Vector2* ret);
// RBX::RenderBase::Mesh::allocVertex(const Vector3& pos, const Vector3& normal, const Vector2& uv, bool)
extern "C" unsigned fn_00548000(const Vector3* pos, const Vector3* normal, const Vector2* uv, bool flag);
// G3D::Array<unsigned>::append(a, b, c, d) (thiscall)
extern "C" void __fastcall fn_004dc6a0(void* self, int unusedEdx, const unsigned* a, const unsigned* b, const unsigned* c, const unsigned* d);

// INFERRED: static state of the random jitter, initialised on first use
static bool   s_jitterInit = false;
static float  s_jit[4];
static std::vector<unsigned> s_cache;  // INFERRED: static vector at 0x9727c0 holding generated vertex ids

static float frand01()
{
    return (float)rand() * (1.0f / 32768.0f);
}

extern "C" void fn_004dfbb0(const Vector3* uvw, float inset, int info, float zOffset, Mesh** meshPtr, unsigned* outIdx)
{
    int side = (info >> 6) & 7;

    Vector3 obj;
    fn_006784d0(&obj, uvw);

    Rect2D r;
    float dx = fabsf(obj.x) - inset;
    float dy = fabsf(obj.y) - inset;
    float dz = fabsf(obj.z) - inset;
    r.x0 = dx; r.y0 = dy; r.x1 = dz; r.y1 = 0.0f;

    float offU = 0.0f, offV = 0.0f, offW = 0.0f;
    float scaleU = 0.0f, scaleV = 0.0f;
    // INFERRED: per-side texture offsets chosen from constants in .rdata (values unknown)
    switch (side) {
    case 0: {
        Vector2 o;
        fn_005185d0(&r, 0, &o);
        offU = o.x * 1.0f; offV = o.x * o.y;
        scaleU = 1.0f; scaleV = 1.0f;
        break;
    }
    case 1: offU = 1.0f; offV = 1.0f; break;
    case 2: offU = 1.0f; offV = 1.0f; offW = 1.0f; break;
    case 3: offU = 1.0f; offV = 1.0f; offW = 1.0f; break;
    case 4: offU = 1.0f; offV = 1.0f; offW = 1.0f; break;
    default: break;
    }
    float z = zOffset * 1.0f + dz;

    // INFERRED: random jitter, generated once and cached in statics
    if (!s_jitterInit) {
        s_jitterInit = true;
        float a = frand01() * 2.0f - 1.0f;
        float b = frand01() * 2.0f - 1.0f;
        s_jit[0] = (frand01() > 0.0f) ? a : -a;
        s_jit[1] = (frand01() > 0.0f) ? b : -b;
        s_jit[2] = a;
        s_jit[3] = b;
    }

    void* indices = (*meshPtr)->indexArray;
    unsigned v0, v1, v2, v3;

    if (side == 0) {
        // single quad
        Vector3 p, n, o;
        Vector2 uv;
        Vector3 t;

        t.x = s_jit[0]; t.y = s_jit[1]; t.z = 1.0f;
        fn_006784d0(&o, &t);
        p.x = -r.x1; p.y = -r.y0; p.z = offU + z * 0.0f;
        fn_006784d0(&n, &p);
        uv.x = s_jit[2]; uv.y = s_jit[3];
        v0 = fn_00548000(&o, &n, &uv, true);

        t.x = offU; t.y = -offV; t.z = z;
        fn_006784d0(&o, &t);
        fn_006784d0(&n, &t);
        v1 = fn_00548000(&o, &n, &uv, true);

        t.x = r.x1; t.y = r.y0; t.z = z;
        fn_006784d0(&o, &t);
        fn_006784d0(&n, &t);
        v2 = fn_00548000(&o, &n, &uv, true);

        t.x = -offU; t.y = offV; t.z = z;
        fn_006784d0(&o, &t);
        fn_006784d0(&n, &t);
        v3 = fn_00548000(&o, &n, &uv, true);

        unsigned a = v0, b = v1, c = v2, d = v3;
        fn_004dc6a0(indices, 0, &a, &b, &c, &d);
        outIdx[0] = v0; outIdx[1] = v1; outIdx[2] = v2; outIdx[3] = v3;
        return;
    }

    // INFERRED: non-zero sides emit a grid of quads; ids go through the static cache vector
    s_cache.erase(s_cache.begin(), s_cache.end());
    float fx = r.x0, fy = r.y0;
    int cells = 0;
    while (fx < r.x1) {
        float nx = fx + 1.0f;
        if (nx > r.x1) nx = r.x1;
        float ny = fy;
        while (ny < r.y1) {
            float my = ny + 1.0f;
            if (my > r.y1) my = r.y1;
            Vector3 p, n, o;
            Vector2 uv;
            unsigned q[4];
            float xs[4] = { fx, nx, nx, fx };
            float ys[4] = { ny, ny, my, my };
            for (int i = 0; i < 4; ++i) {
                p.x = xs[i]; p.y = ys[i]; p.z = z;
                fn_006784d0(&o, &p);
                n.x = 0; n.y = 0; n.z = 1.0f;
                fn_006784d0(&n, &n);
                uv.x = xs[i]; uv.y = ys[i];
                q[i] = fn_00548000(&o, &n, &uv, true);
                s_cache.push_back(q[i]);
            }
            fn_004dc6a0(indices, 0, &q[0], &q[1], &q[2], &q[3]);
            ny = my;
            ++cells;
        }
        fx = nx;
    }
    // INFERRED: the remainder of the function is cut off in the listing
    (void)offW; (void)scaleU; (void)scaleV; (void)cells;
}
