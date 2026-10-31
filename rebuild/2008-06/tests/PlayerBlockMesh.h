#pragma once
#include <G3D/Array.h>
#include <G3D/ReferenceCount.h>
#include <G3D/Vector2.h>
#include <G3D/Vector3.h>
#include "QuadVolume.h"
#include "v8datamodel/BrickColor.h"
#include "PlayerMeshBackend.h"

// Typed integration of the touched native Level prefix; no donor Mesh/GL state.
// BlockMesh owns levels through the original G3D reference-counting contract.
namespace PlayerBlockMesh {
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
class BlockMesh : public G3D::ReferenceCountedObject {
    G3D::Array<LevelRef> levels;
    void populate(const G3D::Vector3&,RBX::View::RenderSurfaceTypes,RBX::BrickColor);
public:
    BlockMesh(const G3D::Vector3&,RBX::View::RenderSurfaceTypes,RBX::BrickColor);
    Level& level0() { return *levels[0]; }
};
typedef G3D::ReferenceCountedPointer<BlockMesh> MeshRef;
unsigned activeReferences();
unsigned liveLevels();
unsigned producerCalls();
}
