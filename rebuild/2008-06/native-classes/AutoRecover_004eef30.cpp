// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers were visible, so everything is declared locally.
// This is a best-effort reconstruction, not a byte-exact match.

#include <windows.h>
#include <new>

namespace G3D {
    struct Vector3;
    class System {
    public:
        static void* alignedMalloc(unsigned size, unsigned alignment);
        static void  memset(void* p, unsigned char v, unsigned n);
    };
}

namespace boost {
    void call_once(void (*f)(), long& flag);
}

namespace RBX {
    class GuidRegistryMutex {
    public:
        void lock();
        void unlock();
    };
    namespace ViewNew {
        class CylinderAlongXMesh {
        public:
            enum RenderSurfaceTypes { DummySurface = 0 };
            CylinderAlongXMesh(const G3D::Vector3& v, RenderSurfaceTypes t);
        };
    }
}

extern "C" int __fastcall fn_004e96f0(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);
extern "C" int __fastcall fn_004e5cd0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004e7630(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_004e5d30(void* self, int unusedEdx, int a1);
extern "C" int fn_006a0920(int a1);
extern "C" int fn_004ed2c0(void);

// INFERRED: file-local globals/helpers standing in for the original addresses
static long g_onceFlag;
static void initRegistry() {}

struct MeshNode {            // hash chain node
    unsigned key0;
    unsigned key1;
    char     value[0x10];   // value starts at +8
    MeshNode* next;         // +0x18
};

struct MeshRegistry {
    char pad0[8];
    MeshNode** buckets;      // +8
    unsigned   bucketCount;  // +0xc
    RBX::GuidRegistryMutex mutex; // +0x10
    char pad1[0x4c];
    int insertCount;         // +0x5c
};

static MeshRegistry* g_registry;   // INFERRED: global at 0x97272c

static MeshNode* findNode(MeshRegistry* r, unsigned key)
{
    MeshNode* n = r->buckets[key % r->bucketCount];
    while (n) {
        if (n->key0 == key && n->key1 == key)
            return n;
        n = n->next;
    }
    return 0;
}

extern "C" void* fn_004eef30(const G3D::Vector3* vec, unsigned surfaceType)
{
    boost::call_once(initRegistry, g_onceFlag);
    MeshRegistry* reg = g_registry;
    reg->mutex.lock();

    void* result = 0;

    MeshNode* node = findNode(reg, surfaceType);
    if (!node) {
        // INFERRED: build a temporary 10-bucket table and insert it into the registry
        void* tmp = G3D::System::alignedMalloc(0x28, 0x10);
        G3D::System::memset(tmp, 0, 0x28);
        fn_004e96f0(reg, 0, (int)&surfaceType, (int)&tmp);
        fn_004d7e30(&tmp, 0);
        node = findNode(reg, surfaceType);
    }

    void* table = node->value;
    if (!fn_004e5cd0(table, 0, (int)vec)) {
        int dummy = 0;
        fn_004e7630(table, 0, (int)vec, (int)&dummy);
    }

    int* slot = (int*)fn_004e5d30(table, 0, (int)vec);
    result = (void*)*slot;
    if (!result) {
        void* mem = (void*)fn_006a0920(0x8c);
        RBX::ViewNew::CylinderAlongXMesh* mesh = 0;
        if (mem)
            mesh = new (mem) RBX::ViewNew::CylinderAlongXMesh(
                *vec, (RBX::ViewNew::CylinderAlongXMesh::RenderSurfaceTypes)surfaceType);
        // INFERRED: ReferenceCountedPointer::setPointer
        *slot = (int)mesh;
        result = mesh;

        if (++reg->insertCount % 100 == 0) {
            // INFERRED: hold a reference across the purge call
            int* held = (int*)*slot;
            if (held)
                InterlockedIncrement((LONG*)(held + 1));
            fn_004ed2c0();
            if (held && InterlockedDecrement((LONG*)(held + 1)) == 0) {
                // INFERRED: zeroWeakPointers then virtual deleting destructor
                typedef void (__thiscall *Dtor)(void*, int);
                void** vt = *(void***)held;
                ((Dtor)vt[0])(held, 1);
            }
        }
    }

    reg->mutex.unlock();
    return result;
}
