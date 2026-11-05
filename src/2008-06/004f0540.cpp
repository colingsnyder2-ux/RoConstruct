// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_meshcomponentscale3f635359db2a846f.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector3.h>
#include <G3D/ReferenceCount.h>
#include <G3D/g3dmath.h>
#include "RenderLib/Mesh.h"
#include <math.h>

namespace RBX {
namespace ViewNew {

typedef RBX::Render::Mesh Mesh;

class SurfaceTypes {
public:
    unsigned int data;
};

Mesh* createHead(const G3D::Vector3& size, SurfaceTypes surfaces, const void* extra);
Mesh* createTorso(const G3D::Vector3& size, SurfaceTypes surfaces, const void* extra);
Mesh* createWedge(const G3D::Vector3& size, SurfaceTypes surfaces, const void* extra);
Mesh* createBall(const G3D::Vector3& size, SurfaceTypes surfaces, const void* extra);
Mesh* createCylinder(const G3D::Vector3& size, SurfaceTypes surfaces, const void* extra);
Mesh* createBrick(const G3D::Vector3& size, SurfaceTypes surfaces, const void* extra);

class PartInstance {
public:
    char pad[0x1dc];
    int shape;
    const G3D::Vector3& getPartSizeUi() const;
};

class SpecialShape {
public:
    char pad[0x130];
    int meshType;
    G3D::Vector3 scale;
};

class Appearance {
public:
    char pad[0x140];
    SurfaceTypes surfaces;
    SurfaceTypes getSurfaces() const { return surfaces; }
    char pad2[0x16c - 0x144];
    int extra;
};

class PartView {
public:
    char pad[0x1c];
    float radius;
    char pad2[0xbc - 0x20];
    PartInstance* part;
    char pad3[0xcc - 0xc0];
    G3D::ReferenceCountedPointer<Mesh> mesh;
    char pad4[0xd4 - 0xd0];
    SpecialShape* specialShape;
    Appearance* appearance;
    void updateMesh();
};

void PartView::updateMesh()
{
    if (!part)
        return;
    G3D::Vector3 size = part->getPartSizeUi();
    if (specialShape)
        { size.x = specialShape->scale.x * size.x; size.y = specialShape->scale.y * size.y; size.z = specialShape->scale.z * size.z; }
    if (!specialShape)
    {
        switch (part->shape)
        {
        case 0: mesh = createBall(size, appearance->getSurfaces(), &appearance->extra); break;
        case 1: mesh = createBrick(size, appearance->getSurfaces(), &appearance->extra); break;
        case 2: mesh = createCylinder(size, appearance->getSurfaces(), &appearance->extra); break;
        }
    }
    else
    {
        switch (specialShape->meshType)
        {
        case 0: mesh = createHead(size, appearance->getSurfaces(), &appearance->extra); break;
        case 1: mesh = createTorso(size, appearance->getSurfaces(), &appearance->extra); break;
        case 2: mesh = createWedge(size, appearance->getSurfaces(), &appearance->extra); break;
        case 3: mesh = createBall(size, appearance->getSurfaces(), &appearance->extra); break;
        case 4: mesh = createCylinder(size, appearance->getSurfaces(), &appearance->extra); break;
        case 6: mesh = createBrick(size, appearance->getSurfaces(), &appearance->extra); break;
        }
    }
    double root = sqrt(2.0);
    float ax = fabs(size.x);
    float ay = fabs(size.y);
    float az = fabs(size.z);
    float m = ax > ay ? ax : ay;
    if (m > az) radius = (float)root * m * 0.5f;
    else radius = (float)root * az * 0.5f;
}

}
}
