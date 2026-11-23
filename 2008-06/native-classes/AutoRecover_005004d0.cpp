// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native headers were visible, so all types and callees are declared locally.
// INFERRED: this is a Mesh-derived constructor that builds one Level via a LevelBuilder.
// INFERRED: the exact LevelBuilder layout and the mapToUvw_Legacy signature are guesses.
#include <windows.h>

struct Vec3 { float x, y, z; };
struct Vec2 { float x, y; };

struct MeshSelf;

extern "C" {
    // INFERRED: vtable of the derived mesh class (unknown global)
    extern void* g_008271b8[];

    int  fn_006a0920(int a1);                                          // operator new
    void __fastcall fn_00548570(void* self, int unusedEdx);            // Mesh::Mesh()
    void* __fastcall fn_004dd2e0(void* self, int unusedEdx, int prim); // Level::Level(Primitive)
    void __fastcall fn_004dcbb0(void* arr, int unusedEdx, void* rcpLevel); // Array<RCP<Level>>::append
    void __fastcall fn_0045ad90(void* self, int unusedEdx);            // zeroWeakPointers
    void __fastcall fn_00598fa0(void* slot, int unusedEdx, void* p);   // RCP::setPointer
    int  __fastcall fn_004fdaf0(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
    // INFERRED: 3 visible args (hidden return, vector, face).
    Vec3* fn_005ec9d0(Vec3* out, const Vec3* v, int face);
    Vec2* __fastcall fn_005185d0(void* self, int unusedEdx);           // x0y0 (returns pointer to data)
    void __fastcall fn_00500ca0(void* builder, int unusedEdx, int face, int purpose); // buildFace
}

static inline int fbits(float f)
{
    union { float f; int i; } u;
    u.f = f;
    return u.i;
}

struct RcObj
{
    void** vtbl;
    volatile LONG refCount;
};

static void releaseRc(RcObj* p)
{
    if (p) {
        if (InterlockedDecrement(&p->refCount) == 0) {
            fn_0045ad90(p, 0);
            ((void (__thiscall*)(void*, int))p->vtbl[0])(p, 1);
        }
    }
}

extern "C" MeshSelf* __fastcall fn_005004d0(MeshSelf* self, int unusedEdx, const Vec3* size, int face, const Vec2* scale)
{
    fn_00548570(self, 0);
    // INFERRED: derived-class vtable assignment
    *(void***)self = g_008271b8;

    const float* pz = &size->z;
    const float* pm = (size->x > *pz) ? pz : &size->x;
    // INFERRED: bevel factor constant (global float in original)
    float bevel = *pm * 0.1f;

    RcObj* level = 0;
    void* mem = (void*)fn_006a0920(0x28);
    if (mem)
        level = (RcObj*)fn_004dd2e0(mem, 0, 5);

    RcObj* held = 0;
    if (level) {
        held = level;
        InterlockedIncrement(&level->refCount);
    }
    fn_004dcbb0((char*)self + 0xc, 0, &held);
    releaseRc(held);

    void* slot = 0;
    fn_00598fa0(&slot, 0, level);

    char builder[0x40];
    fn_004fdaf0(builder, 0, (int)slot, fbits(size->x), fbits(size->y), fbits(size->z), 0, 9, fbits(bevel));

    Vec3 uvw;
    Vec3* r = fn_005ec9d0(&uvw, size, face);
    Vec2* xy = fn_005185d0(r, 0);
    // INFERRED: scale constant (global float in original)
    const float k = 1.0f;
    float a = xy->x * k;
    float b = k * xy->y;
    *(float*)(builder + 0x18) = a / scale->x;
    *(float*)(builder + 0x1c) = b / scale->y;

    fn_00500ca0(builder, 0, face, 1);

    releaseRc(*(RcObj**)(builder + 0xc));
    return self;
}
