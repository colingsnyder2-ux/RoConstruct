// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: draft only. Types and the control flow of the face-quad builder are guessed from the disassembly.
#include <stdlib.h>

struct Vector2 { float x, y; };
struct Vector3 { float x, y, z; };
struct Rect2D { float x0, y0, x1, y1; };
struct IntArray { unsigned* data; int num; int cap; };   // G3D::Array<unsigned>
struct MeshData { int pad[3]; IntArray indices; };       // INFERRED: array lives at +0xc

extern "C" Vector3* __cdecl fn_005ec1a0(Vector3* out, const Vector3* in);
extern "C" unsigned __cdecl fn_00548000(const Vector3* pos, const Vector3* normal, const Vector2* uv, bool flag);
extern "C" Vector2* __fastcall fn_005185d0(Rect2D* self, int unusedEdx, Vector2* ret);
extern "C" void __fastcall fn_004dc6a0(IntArray* self, int unusedEdx, const unsigned* a, const unsigned* b, const unsigned* c, const unsigned* d);

static float s_jitter[4];
static bool s_jitterInit;

static inline float absf(float v) { return v < 0 ? -v : v; }

extern "C" void __cdecl fn_004de360(const Vector3* size, float depth, int face, float step,
                                    MeshData** mesh, unsigned* outVerts)
{
    Vector3 obj;
    fn_005ec1a0(&obj, size);
    float ax = absf(obj.x), ay = absf(obj.y), az = absf(obj.z);
    float rx = depth - ax, ry = depth - ay, rz = depth - az;
    (void)rx; (void)ry; (void)rz; (void)step;

    face &= 7;
    Vector3 uvw = { 0, 0, 0 };
    Vector3 nrm = { 0, 0, 1 };
    Vector2 uv = { 0, 0 };
    Rect2D rect = { 0, 0, 1, 1 };
    Vector2 origin;
    fn_005185d0(&rect, 0, &origin);

    if (!s_jitterInit) {
        s_jitterInit = true;
        s_jitter[0] = (float)rand() * (1.0f / 32768.0f);
        s_jitter[1] = (float)rand() * (1.0f / 32768.0f);
    }

    Vector3 p0, p1, p2, p3;
    fn_005ec1a0(&p0, &uvw);
    unsigned v0 = fn_00548000(&p0, &nrm, &uv, true);
    fn_005ec1a0(&p1, &uvw);
    unsigned v1 = fn_00548000(&p1, &nrm, &uv, true);
    fn_005ec1a0(&p2, &uvw);
    unsigned v2 = fn_00548000(&p2, &nrm, &uv, true);
    fn_005ec1a0(&p3, &uvw);
    unsigned v3 = fn_00548000(&p3, &nrm, &uv, true);

    fn_004dc6a0(&(*mesh)->indices, 0, &v0, &v1, &v2, &v3);
    outVerts[0] = v0;
    outVerts[1] = v1;
    outVerts[2] = v2;
    outVerts[3] = v3;
}
