// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: static cache lookup (map find-or-insert keyed by Vector3+NormalId) creating TorsoMesh
namespace boost { void __cdecl call_once(void (__cdecl *)(), long&); }
namespace RBX {
struct GuidRegistryMutex { void lock(); void unlock(); };
namespace ViewNew { struct TorsoMesh; }
}
namespace G3D { struct Vector3 { float x, y, z; }; }

extern "C" void __cdecl fn_004d9870();
extern "C" long g_00972748;
extern "C" char* g_00972730;
extern "C" int __fastcall fn_004e8690(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_006a0920(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004ea140(void* self, int unusedEdx, int a1);
extern "C" void* __cdecl operator_new_006a0920(unsigned);
extern "C" RBX::ViewNew::TorsoMesh* __fastcall fn_004fa700(void* self, int unusedEdx, const G3D::Vector3* v, int normalId);
extern "C" void __fastcall fn_00598fa0(void* self, int unusedEdx, void* p);

struct MapNode { MapNode* left; MapNode* parent; MapNode* right; float key[4]; void* pad; void* value; };

extern "C" void* __cdecl fn_004ee750(const G3D::Vector3* v, int normalId)
{
    boost::call_once(fn_004d9870, g_00972748);
    char* reg = g_00972730;
    RBX::GuidRegistryMutex* mtx = (RBX::GuidRegistryMutex*)(reg + 0x10);
    mtx->lock();
    G3D::Vector3 key = *v;
    char* map = reg + 0x1c;
    int it = 0;
    int dummyKey[1];
    (void)dummyKey;
    fn_004e8690(map, 0, (int)&it, (int)&key);
    void* result;
    MapNode* head = *(MapNode**)map;
    MapNode* found = (MapNode*)it;
    if (found == *(MapNode**)(map + 0x18)) {
        void* mem = (void*)(unsigned)fn_006a0920(0, 0, 0x8c);
        RBX::ViewNew::TorsoMesh* mesh = 0;
        if (mem)
            mesh = fn_004fa700(mem, 0, v, normalId);
        int slot = fn_004ea140(map, 0, (int)&key);
        fn_00598fa0((void*)slot, 0, mesh);
        result = mesh;
    } else {
        result = ((MapNode*)found)->value;
    }
    (void)head;
    mtx->unlock();
    return result;
}
