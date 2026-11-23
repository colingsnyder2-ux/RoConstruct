// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: opaque types; callees are rgmain imports / fn_ externs, member layout from disassembly only.
struct Sub;
struct Mesh;
struct Vec3 { float x, y, z; };
struct MeshPtr { void* rep; Mesh* mesh; };

extern "C" MeshPtr* __fastcall fn_006719f0(void* map, int unusedEdx, void* key, const MeshPtr* src);
extern "C" MeshPtr* __fastcall fn_MeshPtrAssign(MeshPtr* self, int unusedEdx);
extern "C" float __fastcall fn_getBoundingSphereRadius(Mesh* m);
extern "C" const void* __fastcall fn_getBounds(Mesh* m, int unusedEdx, void* ret);
extern "C" Vec3* __fastcall fn_getCenter(const void* box, int unusedEdx, void* ret);
extern "C" unsigned short __fastcall fn_getNumSubMeshes(Mesh* m);
extern "C" Sub* __fastcall fn_getSubMesh(Mesh* m, int unusedEdx, unsigned short i);

typedef void (__thiscall *SinkFn)(void*, Sub*, float*);

struct MeshHolder {
    char pad0[0x34];
    void** sink;      // +0x34, object whose vtable slot 0x1c4 takes (Sub*, float*)
    char pad1[0x78 - 0x38];
    char meshMap[1];  // +0x78 std::map<std::string, Ogre::MeshPtr>
};

extern "C" void __fastcall fn_00671b60(MeshHolder* self, int unusedEdx, void* key, const MeshPtr* src)
{
    fn_MeshPtrAssign(fn_006719f0(self->meshMap, 0, key, src), 0);
    Mesh* mesh = src->mesh;
    float data[4];
    char boxTmp[16];
    data[0] = fn_getBoundingSphereRadius(mesh);
    Vec3* c = fn_getCenter(fn_getBounds(mesh, 0, boxTmp), 0, boxTmp);
    data[1] = c->x;
    data[2] = c->y;
    data[3] = c->z;
    for (int i = 0; i < (int)fn_getNumSubMeshes(src->mesh); ++i) {
        void* obj = self->sink;
        SinkFn f = *(SinkFn*)((char*)*(void**)obj + 0x1c4);
        f(obj, fn_getSubMesh(src->mesh, 0, (unsigned short)i), data);
    }
}
