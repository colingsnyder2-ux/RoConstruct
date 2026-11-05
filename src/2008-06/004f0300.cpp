// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_65a96466f2b1396b.cpp

// Candidate translation unit (score above; library headers required).
#include <algorithm>
#include <math.h>
#include <G3D/ReferenceCount.h>
#include <G3D/Vector3.h>
#include <G3D/g3dmath.h>
namespace RBX {
class PartInstance {
public:
    char pad[0x1dc];
    int partType;
    char pad2[0x2c4 - 0x1e0];
    struct Prim { int a; G3D::Vector3 size; }* prim;
    const G3D::Vector3& getPartSizeXml() const;
    int getPartType() const { return partType; }
};
class SpecialShape {
public:
    char pad[0x130];
    int meshType;
    G3D::Vector3 scale;
};
class Decal {
public:
    char pad[0x140];
    int face;
    int getFace() const { return face; }
};
namespace Render {
class Mesh : public G3D::ReferenceCountedObject {
public:
    char pad[0x84 - sizeof(G3D::ReferenceCountedObject)];
    int lod;
};
}
namespace View {
static inline float maxf(float a, float b) { return a > b ? a : b; }
template<int N> Render::Mesh* createDecalMesh(const G3D::Vector3& size, int face);
class Decal {
public:
    virtual ~Decal();
    char pad0[0x18];
    float radius;
    char pad1[0xbc - 0x20];
    PartInstance* partInstance;
    void* partInstanceCount;
    char pad2[0xcc - 0xc4];
    G3D::ReferenceCountedPointer<Render::Mesh> mesh;
    void* view;
    SpecialShape* specialShape;
    RBX::Decal* decal;
    virtual void updateMesh();
};
void Decal::updateMesh()
{
    if (!partInstance)
        return;
    G3D::Vector3 size = partInstance->getPartSizeXml();
    if (specialShape)
        size *= specialShape->scale;
    if (!specialShape)
    {
        switch (partInstance->getPartType())
        {
        case 0: mesh = createDecalMesh<0>(size, decal->getFace()); break;
        case 1: mesh = createDecalMesh<1>(size, decal->getFace()); break;
        case 2: mesh = createDecalMesh<2>(size, decal->getFace()); break;
        }
    }
    else
    {
        switch (specialShape->meshType)
        {
        case 0: mesh = createDecalMesh<3>(size, decal->getFace()); break;
        case 1: mesh = createDecalMesh<4>(size, decal->getFace()); break;
        case 2: mesh = createDecalMesh<5>(size, decal->getFace()); break;
        case 3: mesh = createDecalMesh<0>(size, decal->getFace()); break;
        case 4: mesh = createDecalMesh<2>(size, decal->getFace()); break;
        case 6: mesh = createDecalMesh<1>(size, decal->getFace()); break;
        }
    }
float s2 = (float)sqrt(2.0);
    float ax = fabs(size.x);
    float ay = fabs(size.y);
    float az = fabs(size.z);
    float d = s2 * maxf(maxf(ax, ay), az);
    radius = d * 0.5f;
    if (mesh.getPointer())
        mesh->lod = 4;
}
}}
