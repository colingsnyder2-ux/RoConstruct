// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers used; signatures reconstructed from the disassembly only. Unverified draft, not compiled.
// The compact vertex loops below do not reproduce the unrolled index pattern of the original exactly.

struct Vec3 { float x, y, z; };
struct BrickColorArg { int number; };

extern "C" void* fn_006a0920(int size);                                   // operator new
extern "C" void* __fastcall fn_004dd2e0(void* self, int unusedEdx, int primitive); // Level::Level(Primitive)
extern "C" void __fastcall fn_004dcbb0(void* arr, int unusedEdx, void* ptrRef);    // Array<RCP<Level>>::append
extern "C" unsigned __fastcall fn_005b5c90(BrickColorArg* self, int unusedEdx);    // BrickColor::getClosestPaletteIndex
extern "C" void __cdecl fn_004de360(const Vector3* size, float depth, int face, float step, MeshData** mesh, unsigned* outVerts);
extern "C" void fn_004def80(const V3* size, float extent, unsigned flags, float offset, MeshHolder** mesh, unsigned* outIndices);
extern "C" void fn_004dfbb0(const Vector3* uvw, float inset, int info, float zOffset, Mesh** meshPtr, unsigned* outIdx);
extern "C" void fn_004e07e0(const Vector3* uvw, float size, unsigned flags, float bias, MeshTarget** target, unsigned* outQuad);
extern "C" void fn_004e1410(const Vec3* uvw, float size, unsigned faceBits, float pad, MeshData** mesh, unsigned* outVerts);
extern "C" void __cdecl fn_004e2040(const Vec3* uvw, float extent, unsigned packed, float scale, char** mesh, unsigned* out);
extern "C" void __fastcall fn_004dc6a0(void* arr, int unusedEdx, const unsigned* a, const unsigned* b, const unsigned* c, const unsigned* d);
extern "C" unsigned fn_00548000(const Vec3* pos, const Vec3* normal, const float* uv, bool flag);
extern "C" unsigned fn_00547fc0(unsigned idx, int refDelta);

extern Vec3* g_cubeNormals;   // INFERRED: [0x9738fc]
extern Vec3* g_cubePositions; // INFERRED: [0x9738f0]
extern float g_scaleConst;    // [0x819bac]
extern float g_one;           // [0x972758]
extern float g_uvBase;        // [0x9413c8]
extern float g_uvScale;       // [0x826e44]
extern float g_uvOffset;      // [0x9413c4]

extern "C" void __fastcall fn_004e2c80(char* self, int unusedEdx, const Vec3* size, int arg2, BrickColorArg color)
{
    char* level = (char*)fn_006a0920(0x28);
    if (level)
        fn_004dd2e0(level, 0, 5);

    // intrusive refcount at +4 (InterlockedIncrement)
    char* levelRef = level;
    fn_004dcbb0(self + 0xc, 0, &levelRef);

    float scaled[3];
    scaled[0] = size->x * g_scaleConst;
    scaled[1] = size->y * g_scaleConst;
    scaled[2] = size->z * g_scaleConst;

    unsigned palette = fn_005b5c90(&color, 0);
    float paletteF = (float)palette;

    int faces[24];
    fn_004de360(scaled, 0, 0, 0, 0, 0, 0, 0);
    fn_004def80(scaled, 0, 0, 0, 0, 0, 0, 0);
    fn_004dfbb0(scaled, 0, 0, 0, 0, 0, 0, 0);
    fn_004e07e0(scaled, 0, 0, 0, 0, 0, 0, 0);
    fn_004e1410(scaled, 0, 0, 0, 0, 0, 0, 0);
    fn_004e2040(scaled, 0, 0, 0, 0, 0, 0, 0);

    if (paletteF != g_one) {
        float uv[2];
        uv[1] = g_uvBase;
        uv[0] = paletteF * g_uvScale + g_uvOffset;
        for (int i = 0; i < 24; ++i)
            faces[i] = (int)fn_00548000(&g_cubePositions[faces[i]], &g_cubeNormals[faces[i]], uv, true);

        for (int i = 0; i < 24; i += 4)
            fn_004dc6a0(levelRef + 0xc, 0, (unsigned*)&faces[i], (unsigned*)&faces[i + 1],
                        (unsigned*)&faces[i + 2], (unsigned*)&faces[i + 3]);

        for (int i = 0; i < 24; ++i)
            fn_00547fc0(faces[i], -1);
    }

    // release levelRef: InterlockedDecrement; destroy on zero (compiler-generated smart pointer dtor)
}
