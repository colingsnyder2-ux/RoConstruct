// from server: 35% by atomic.potato
struct MeshPtr {
    void* p;
    MeshPtr& operator=(const MeshPtr&);
};

struct Vector3 {
    float x, y, z;
};

struct AxisAlignedBox {
    Vector3 getCenter() const;
};

struct SubMesh;

struct Mesh {
    float getBoundingSphereRadius() const;
    const AxisAlignedBox& getBounds() const;
    unsigned short getNumSubMeshes() const;
    SubMesh* getSubMesh(unsigned short) const;
};

struct AdornRbxGfx {
    char pad[0x6c];
    MeshPtr meshPtr;
    void f(int, int);
};

extern "C" void __stdcall sub_924E00();
extern "C" void __cdecl sub_9460B0(void*);

void AdornRbxGfx::f(int a, int b) {
    sub_924E00();
    MeshPtr* mp = (MeshPtr*)&meshPtr;
    Mesh* mesh = (Mesh*)mp->p;
    float r = mesh->getBoundingSphereRadius();
    Vector3 c = mesh->getBounds().getCenter();
    unsigned short n = mesh->getNumSubMeshes();
    for (unsigned short i = 0; i < n; i++) {
        sub_9460B0(mesh->getSubMesh(i));
    }
}
