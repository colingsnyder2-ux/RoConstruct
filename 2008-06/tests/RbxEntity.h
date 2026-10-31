#pragma once
#include <Ogre.h>

namespace Ogre
{
class RbxSubEntity : public SubEntity, public ShadowCaster
{
public:
    Matrix4 transform;
    SubMesh* lodMeshes[1];
    unsigned int lodIndex;
    unsigned int unknown138;
    bool castShadows;
    ShadowRenderable* shadow;
    std::vector<ShadowRenderable*> shadows;
    RbxSubEntity(Entity* parent);
    RbxSubEntity(Entity* parent, SubMesh* mesh, unsigned int lod);
    ~RbxSubEntity();
    bool getCastShadows() const;
    const AxisAlignedBox& getWorldBoundingBox(bool derive = false) const;
    const AxisAlignedBox& getLightCapBounds() const;
    const AxisAlignedBox& getDarkCapBounds(const Light&, Real) const;
    ShadowRenderableListIterator getShadowVolumeRenderableIterator(
        ShadowTechnique, const Light*, HardwareIndexBufferSharedPtr*, bool, Real, unsigned long = 0);
    bool hasEdgeList();
    EdgeData* getEdgeList();
    Real getPointExtrusionDistance(const Light*) const;
    const Vector3& getPosition() const;
};

class RbxEntity : public Entity
{
public:
    unsigned int flags;
    unsigned char options[3];
    AxisAlignedBox bounds;
    float distance;
    unsigned int limit;
    std::vector<SubEntity*> addedEntities;
    RbxEntity();
    ~RbxEntity();
    SubEntity* createSubEntity(SubMesh* mesh, unsigned int lod);
    void setMesh(const MeshPtr& mesh);
    friend void RbxEntitySetMesh(RbxEntity*, const MeshPtr&);
};
}
