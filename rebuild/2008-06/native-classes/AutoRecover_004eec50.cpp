// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include "ViewNew/QuadVolumeFace.h"
#include "ViewNew/SphereMesh.h"

namespace boost {
    void call_once(void (*f)(), long& flag);
}

extern "C" {
    void fn_004d97b0();
    extern long g_flag_00972740;   // INFERRED: boost::once_flag
    extern char* g_inst_00972728;  // INFERRED: singleton registry pointer

    void __fastcall fn_00563090(void* self, int unusedEdx);   // GuidRegistryMutex::lock
    void __fastcall fn_005630e0(void* self, int unusedEdx);   // GuidRegistryMutex::unlock
    int __fastcall fn_004e8690(void* self, int unusedEdx, int a1, int a2);
    int __fastcall fn_004ea140(void* self, int unusedEdx, int a1);
    void __fastcall fn_00598fa0(void* self, int unusedEdx, void* p); // ReferenceCountedPointer::setPointer
    // INFERRED: the call site pushes one arg, uses no ecx and pops with add esp,4: cdecl operator-new-like
    void* fn_006a0920(unsigned int size);
}

// INFERRED: SphereMesh and NormalId live in namespace RBX
using namespace RBX;

namespace {
struct MutexLock {
    void* m;
    explicit MutexLock(void* mm) : m(mm) { fn_00563090(m, 0); }
    ~MutexLock() { fn_005630e0(m, 0); }
};

// INFERRED: cache key = size + face
struct MeshKey {
    float x, y, z;
    int face;
};
}

extern "C" SphereMesh* fn_004eec50(const G3D::Vector3* size, int decalFace)
{
    boost::call_once(fn_004d97b0, g_flag_00972740);
    char* inst = g_inst_00972728;
    MutexLock lock(inst + 0x10);

    MeshKey key;
    key.x = size->x;
    key.y = size->y;
    key.z = size->z;
    key.face = decalFace;

    void* map = inst + 0x1c;
    char* it = 0;
    fn_004e8690(map, 0, (int)&it, (int)&key);
    char* end = *(char**)((char*)map + 0x18);

    if (it != end) {
        return *(SphereMesh**)(it + 0x1c);
    }

    SphereMesh* mesh;
    void* mem = fn_006a0920(0x8c);
    if (mem) {
        mesh = new (mem) SphereMesh(*size, (NormalId)decalFace);
    } else {
        mesh = 0;
    }
    void* slot = (void*)fn_004ea140(map, 0, (int)&key);
    fn_00598fa0(slot, 0, mesh);
    return mesh;
}
