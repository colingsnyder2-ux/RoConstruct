#pragma once
#include <G3D/Array.h>
#include <G3D/ReferenceCount.h>
#include <G3D/Vector2.h>
#include <G3D/Vector3.h>
#include "QuadVolume.h"
#include "v8datamodel/BrickColor.h"
#include "PlayerMeshBackend.h"
#include <G3D/MeshAlg.h>
#include <vector>

// Typed integration of the touched native Level prefix; no donor Mesh/GL state.
// BlockMesh owns levels through the original G3D reference-counting contract.
namespace RBX { class MeshId;class ContentProvider; }
namespace PlayerBlockMesh {
class Mesh;
typedef G3D::ReferenceCountedPointer<Mesh> MeshRef;
class Level : public G3D::ReferenceCountedObject {
public:
    G3D::Array<unsigned> indexArray;
    G3D::RenderDevice::Primitive primitive;
    bool dirty;
    int sharedIndex;
    Ogre::RbxSubMesh* backend;
    explicit Level(G3D::RenderDevice::Primitive p);
    ~Level();
    void upload(bool indices32,Ogre::AxisAlignedBox& bounds);
};
typedef G3D::ReferenceCountedPointer<Level> LevelRef;
struct ShadowSurface {
    G3D::Array<G3D::MeshAlg::Edge> edges;
    G3D::Array<G3D::Vector3> faceNormals;
    G3D::Array<G3D::MeshAlg::Face> faces;
    G3D::Array<G3D::Vector3> geometry;
    LevelRef dropShadow;
};
// 00548570/00548a90: genuine G3D/STL members, no opaque padding.
class Mesh : public G3D::ReferenceCountedObject {
public:
    G3D::Array<LevelRef> levels;
    ShadowSurface shadow;
    float debugBoundingRadius;
    std::vector<short> shadowIndices;
    std::vector<G3D::Vector3> shadowVertices;
    Ogre::RbxSubMesh* shadowBackend;
    int geometryKind;
    Mesh();
    ~Mesh();
    Level& level0() { return *levels[0]; }
};
class BlockMesh : public Mesh {
    void populate(const G3D::Vector3&,RBX::View::RenderSurfaceTypes,RBX::BrickColor);
public:
    BlockMesh(const G3D::Vector3&,RBX::View::RenderSurfaceTypes,RBX::BrickColor);
    static MeshRef create(const G3D::Vector3&,RBX::View::RenderSurfaceTypes,RBX::BrickColor);
};
// Genuine static factory base accounts for native sphere allocation0x8c.
template<class T,size_t variations> class MeshFactory {
public:
    static T* create(const G3D::Vector3&,RBX::View::RenderSurfaceTypes);
    static void flushUnused();
    static unsigned cachedMeshes();
};
class SphereMesh : public Mesh, public MeshFactory<SphereMesh,1> {
public:
    SphereMesh(const G3D::Vector3&,RBX::View::RenderSurfaceTypes);
};
class FileMesh : public Mesh {
public:
    bool loadFromMeshFile(RBX::ContentProvider*,const G3D::Vector3&,RBX::MeshId);
    static MeshRef create(RBX::ContentProvider*,const G3D::Vector3&,RBX::MeshId);
};
template<> SphereMesh* MeshFactory<SphereMesh,1>::create(const G3D::Vector3&,RBX::View::RenderSurfaceTypes);
template<> void MeshFactory<SphereMesh,1>::flushUnused();
template<> unsigned MeshFactory<SphereMesh,1>::cachedMeshes();
void flushUnused();
unsigned cachedMeshes();
unsigned activeReferences();
unsigned liveLevels();
unsigned producerCalls();
}
