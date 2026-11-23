// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: this is a cache lookup (find-or-create a PBBMesh keyed by Vector3 + NormalId) in a global registry map guarded by a mutex.
// INFERRED: the target takes (const Vector3*, NormalId) and returns a PBBMesh*. All names and layouts below are guesses from the disassembly.

#include <stddef.h>
#include <new>

namespace G3D { class Vector3; }

namespace boost {
    void call_once(void (*)(), long&);
}

namespace RBX {
    class GuidRegistryMutex {
    public:
        void lock();
        void unlock();
    };
    namespace ViewNew {
        class PBBMesh {
        public:
            PBBMesh(const G3D::Vector3& v, int normalId);
        };
    }
}

// INFERRED: unknown globals and callees, declared with the fn_ naming convention.
extern "C" void fn_004d9750(void);
extern long g_once_flag_0097273c;
extern char* g_registry_00972724;

extern "C" int __fastcall fn_004e8690(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_004ea140(void* self, int unusedEdx, int a1);
// The caller pops its own stack argument and ecx is not set, so this is a plain cdecl allocator.
extern "C" void* fn_006a0920(size_t size);
// ReferenceCountedPointer<...>::setPointer, thiscall
extern "C" void __fastcall fn_00598fa0(void* self, int unusedEdx, void* p);

namespace {
    struct MeshKey {
        float x, y, z;
        int normalId;
    };
    struct MapNode {
        char pad[0x1c];
        void* value;
    };
    struct MapIter {
        void* container;
        MapNode* node;
    };
    struct MapHead {
        void* proxy;     // [+0x00]
        char pad[0x14];
        MapNode* head;   // [+0x18]
    };
    struct LockGuard {
        RBX::GuidRegistryMutex* m;
        explicit LockGuard(RBX::GuidRegistryMutex* mm) : m(mm) { m->lock(); }
        ~LockGuard() { m->unlock(); }
    };
}

extern "C" void* fn_004edd50(const float* v, int normalId)
{
    boost::call_once(fn_004d9750, g_once_flag_0097273c);

    char* reg = g_registry_00972724;
    LockGuard guard((RBX::GuidRegistryMutex*)(reg + 0x10));

    MeshKey key;
    key.x = v[0];
    key.y = v[1];
    key.z = v[2];
    key.normalId = normalId;

    MapHead* map = (MapHead*)(reg + 0x1c);
    MapIter it;
    fn_004e8690(map, 0, (int)&it, (int)&key);

    if (it.node != map->head) {
        return it.node->value;
    }

    RBX::ViewNew::PBBMesh* mesh;
    void* mem = fn_006a0920(0x8c);
    if (mem) {
        mesh = new (mem) RBX::ViewNew::PBBMesh(*(const G3D::Vector3*)v, normalId);
    } else {
        mesh = 0;
    }

    int slot = fn_004ea140(map, 0, (int)&key);
    fn_00598fa0((void*)slot, 0, mesh);
    return mesh;
}
