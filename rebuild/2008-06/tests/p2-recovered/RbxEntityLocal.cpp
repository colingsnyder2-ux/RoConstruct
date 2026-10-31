#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
namespace Ogre {
class RbxSubEntity : public SubEntity, public ShadowCaster {
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
RbxSubEntity::RbxSubEntity(Entity* parent)
    : SubEntity(parent, 0), lodIndex(0), castShadows(true) {
    shadow = 0;
    lodMeshes[0] = 0;
}
RbxSubEntity::RbxSubEntity(Entity* parent, SubMesh* mesh, unsigned int lod)
    : SubEntity(parent, 0), lodIndex(lod), castShadows(true) {
    lodMeshes[0] = 0;
    if (!lod) mSubMesh = mesh;
    else lodMeshes[lodIndex - 1] = mesh;
    shadow = 0;
}
RbxSubEntity::~RbxSubEntity() {
    for (int i = 0; i < (int)shadows.size(); ++i) delete shadows[i];
    shadows.clear();
}
const Vector3& RbxSubEntity::getPosition() const {
    static Vector3 position = transform.getTrans();
    return position;
}

class RbxEntity : public Entity {
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
};
RbxEntity::RbxEntity() {
    mInitialised = true;
    flags = 0;
    options[0] = true;
    options[2] = true;
    distance = 20.0f;
    limit = 888;
}
RbxEntity::~RbxEntity() {
    for (int i = 0; i < (int)Entity::getNumSubEntities(); ++i)
        delete dynamic_cast<RbxSubEntity*>(mSubEntityList[i]);
    mSubEntityList.clear();
}
SubEntity* RbxEntity::createSubEntity(SubMesh* mesh, unsigned int lod) {
    RbxSubEntity* entity = new RbxSubEntity(this, mesh, lod);
    if (mesh->isMatInitialised()) entity->setMaterialName(mesh->getMaterialName());
    mSubEntityList.push_back(entity);
    return entity;
}
void RbxEntity::setMesh(const MeshPtr& mesh) {
    mMesh = mesh;
}

bool RbxSubEntity::getCastShadows() const { return castShadows; }
const AxisAlignedBox& RbxSubEntity::getWorldBoundingBox(bool) const {
    static AxisAlignedBox box;
    return box;
}
const AxisAlignedBox& RbxSubEntity::getLightCapBounds() const {
    static AxisAlignedBox box;
    return box;
}
const AxisAlignedBox& RbxSubEntity::getDarkCapBounds(const Light&, Real) const {
    static AxisAlignedBox box;
    return box;
}
Ogre::ShadowCaster::ShadowRenderableListIterator RbxSubEntity::getShadowVolumeRenderableIterator(
    ShadowTechnique, const Light*, HardwareIndexBufferSharedPtr*, bool, Real, unsigned long) {
    static Ogre::ShadowCaster::ShadowRenderableList empty;
    return Ogre::ShadowCaster::ShadowRenderableListIterator(empty);
}
bool RbxSubEntity::hasEdgeList() { return false; }
EdgeData* RbxSubEntity::getEdgeList() { return 0; }
Real RbxSubEntity::getPointExtrusionDistance(const Light*) const { return 0; }
}
