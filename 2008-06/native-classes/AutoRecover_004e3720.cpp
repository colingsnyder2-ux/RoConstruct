// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: partial draft. The disassembly was truncated, so only the first part is modelled.
// The argument types and the tail after 0x4e415f are guesses. Not compiled or diffed.
#include "ViewNewBrickBuild2008/BrickMeshCache2008.h"

extern "C" int fn_006a0920(int a1, int a2, int a3, int a4, int a5, int a6);
extern "C" void __cdecl fn_004de360(const Vector3* size, float depth, int face, float step, MeshData** mesh, unsigned* outVerts);
extern "C" void fn_004def80(const V3* size, float extent, unsigned flags, float offset, MeshHolder** mesh, unsigned* outIndices);
extern "C" void fn_004dfbb0(const Vector3* uvw, float inset, int info, float zOffset, Mesh** meshPtr, unsigned* outIdx);
extern "C" void fn_004e07e0(const Vector3* uvw, float size, unsigned flags, float bias, MeshTarget** target, unsigned* outQuad);
extern "C" void fn_004e1410(const Vec3* uvw, float size, unsigned faceBits, float pad, MeshData** mesh, unsigned* outVerts);
extern "C" void __cdecl fn_004e2040(const Vec3* uvw, float extent, unsigned packed, float scale, char** mesh, unsigned* out);

// INFERRED: object layout and argument meaning from the disassembly.
// The six ints at this+0 .. this+0x14 are vertex indices, and this+0xc is the level array.
extern "C" void __fastcall fn_004e3720(void* self, int unusedEdx, float* size, int a2, int a3,
                                       int a4, int a5, float scale, int a7)
{
    (void)self; (void)unusedEdx; (void)size; (void)a2; (void)a3;
    (void)a4; (void)a5; (void)scale; (void)a7;
    // Body not recoverable from the truncated disassembly.
}
