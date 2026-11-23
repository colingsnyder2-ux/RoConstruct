// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: local declarations stand in for headers; the layout is guessed from the disassembly.
#include <stddef.h>
#include <new>

namespace G3D { class Vector3 { public: float x, y, z; }; }
namespace RBX {
class GuidRegistryMutex { public: void lock(); void unlock(); };
namespace ViewNew {
class CylinderAlongXMesh {
public:
    CylinderAlongXMesh(const G3D::Vector3& v, int normalId);
};
}
}

extern "C" int __fastcall fn_004e8690(void* self, int unusedEdx, int a1, int a2);
extern "C" void* __fastcall fn_006a0920(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004ea140(void* self, int unusedEdx, int a1);

namespace boost { void call_once(void (*f)(), long& flag); }

struct Registry {
    char pad[0x10];
    RBX::GuidRegistryMutex mutex;   // +0x10
    char pad2[0x0b];
    char map[0x20];                 // +0x1c
};

extern Registry* g_registry;        // 0x97272c
extern long g_registryOnce;         // 0x972744
extern void registryInit();         // 0x4d9810
extern void __fastcall setPointer(int* slot, int unusedEdx, void* p); // 0x598fa0

struct Guard {
    RBX::GuidRegistryMutex* m;
    explicit Guard(RBX::GuidRegistryMutex* mm) : m(mm) { m->lock(); }
    ~Guard() { m->unlock(); }
};

extern "C" RBX::ViewNew::CylinderAlongXMesh* fn_004ef150(const G3D::Vector3* v, int normalId)
{
    boost::call_once(registryInit, g_registryOnce);
    Registry* r = g_registry;
    Guard lock(&r->mutex);

    G3D::Vector3 key = *v;
    int iter[2];
    fn_004e8690(r->map, 0, (int)&iter[0], (int)&key);

    if (iter[1] == 0) {
        void* mem = fn_006a0920(0, 0, 0x8c);
        RBX::ViewNew::CylinderAlongXMesh* m = mem ? new (mem) RBX::ViewNew::CylinderAlongXMesh(*v, normalId) : 0;
        int slot = fn_004ea140(r->map, 0, (int)&key);
        setPointer((int*)slot, 0, m);
        return m;
    }
    return *(RBX::ViewNew::CylinderAlongXMesh**)(iter[1] + 0x1c);
}
