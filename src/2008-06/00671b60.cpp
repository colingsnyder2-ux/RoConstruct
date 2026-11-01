// from server: 100% by king_originala
// from server: 94% by king_originala
// roc 2008-06 00671b60  unit: RBX::AdornRbxGfx  size: 178 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00671b60
//
// 00671b60  83ec1c               sub esp, 0x1c
// 00671b63  8b442420             mov eax, dword ptr [esp + 0x20]
// 00671b67  53                   push ebx
// 00671b68  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00671b6c  55                   push ebp
// 00671b6d  56                   push esi
// 00671b6e  57                   push edi
// 00671b6f  8be9                 mov ebp, ecx
// 00671b71  53                   push ebx
// 00671b72  50                   push eax
// 00671b73  8d4d78               lea ecx, [ebp + 0x78]
// 00671b76  e875feffff           call 0x6719f0
// 00671b7b  8bc8                 mov ecx, eax
// 00671b7d  ff15a04c8000         call dword ptr [0x804ca0]
// 00671b83  8b7304               mov esi, dword ptr [ebx + 4]
// 00671b86  8bce                 mov ecx, esi
// 00671b88  ff1554428000         call dword ptr [0x804254]
// 00671b8e  d95c2434             fstp dword ptr [esp + 0x34]
// 00671b92  8d4c2410             lea ecx, [esp + 0x10]
// 00671b96  51                   push ecx
// 00671b97  8bce                 mov ecx, esi
// 00671b99  ff1558428000         call dword ptr [0x804258]
// 00671b9f  8bc8                 mov ecx, eax
// 00671ba1  ff155c428000         call dword ptr [0x80425c]
// 00671ba7  d9442434             fld dword ptr [esp + 0x34]
// 00671bab  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00671bae  d95c241c             fstp dword ptr [esp + 0x1c]
// 00671bb2  d900                 fld dword ptr [eax]
// 00671bb4  33ff                 xor edi, edi
// 00671bb6  d95c2420             fstp dword ptr [esp + 0x20]
// 00671bba  d94004               fld dword ptr [eax + 4]
// 00671bbd  d95c2424             fstp dword ptr [esp + 0x24]
// 00671bc1  d94008               fld dword ptr [eax + 8]
// 00671bc4  d95c2428             fstp dword ptr [esp + 0x28]
// 00671bc8  ff15b84c8000         call dword ptr [0x804cb8]
// 00671bce  33d2                 xor edx, edx
// 00671bd0  663bd0               cmp dx, ax
// 00671bd3  7333                 jae 0x671c08
// 00671bd5  8b4534               mov eax, dword ptr [ebp + 0x34]
// 00671bd8  8b30                 mov esi, dword ptr [eax]
// 00671bda  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00671bdd  8d54241c             lea edx, [esp + 0x1c]
// 00671be1  52                   push edx
// 00671be2  57                   push edi
// 00671be3  81c6c4010000         add esi, 0x1c4
// 00671be9  ff15bc4c8000         call dword ptr [0x804cbc]
// 00671bef  8b4d34               mov ecx, dword ptr [ebp + 0x34]
// 00671bf2  50                   push eax
// 00671bf3  8b06                 mov eax, dword ptr [esi]
// 00671bf5  ffd0                 call eax
// 00671bf7  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00671bfa  47                   inc edi
// 00671bfb  ff15b84c8000         call dword ptr [0x804cb8]
// 00671c01  0fb7c8               movzx ecx, ax
// 00671c04  3bf9                 cmp edi, ecx
// 00671c06  7ccd                 jl 0x671bd5
// 00671c08  5f                   pop edi
// 00671c09  5e                   pop esi
// 00671c0a  5d                   pop ebp
// 00671c0b  5b                   pop ebx
// 00671c0c  83c41c               add esp, 0x1c
// 00671c0f  c20800               ret 8

struct Vector3 {
    float x, y, z;
};

struct Sphere {
    float radius;
    Vector3 center;
};

struct Box;
struct Mesh;
struct SubMesh;
struct Handle;
struct Renderer;

typedef void (__thiscall *DrawFn)(Renderer*, SubMesh*);

struct RenderTable {
    char padding[0x1c4];
    DrawFn draw;
};

struct Renderer {
    RenderTable* table;
};

struct MeshPtr {
    void* first;
    Mesh* mesh;
};

struct Cache {
    Handle* prepare(void*, const MeshPtr&);
};

extern void (__thiscall *finish)(Handle*);
extern float (__thiscall *getRadius)(Mesh*);
extern const Box& (__thiscall *getBounds)(Mesh*);
extern Vector3* (__thiscall *getCenter)(const Box*, Vector3*);
extern unsigned short (__thiscall *getCount)(Mesh*);
extern SubMesh* (__thiscall *getSubMesh)(Mesh*, unsigned short, const Sphere&);

struct S {
    char padding0[0x34];
    Renderer* renderer;
    char padding1[0x40];
    Cache cache;

    void f(void*, const MeshPtr&);
};

void S::f(void* key, const MeshPtr& meshPtr) {
    finish(cache.prepare(key, meshPtr));

    Mesh* mesh = meshPtr.mesh;
    float radius = getRadius(mesh);
    Vector3 temporary;
    const Vector3& center = *getCenter(&getBounds(mesh), &temporary);

    Sphere sphere;
    sphere.radius = radius;
    sphere.center.x = center.x;
    sphere.center.y = center.y;
    sphere.center.z = center.z;

    for (int i = 0; i < getCount(meshPtr.mesh); ++i) {
        DrawFn* draw = &renderer->table->draw;
        Mesh* current=meshPtr.mesh;
        SubMesh* subMesh = getSubMesh(current, (unsigned short)i, sphere);
        (*draw)(renderer, subMesh);
    }
}
