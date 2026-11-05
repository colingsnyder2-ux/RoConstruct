// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_try_91a54940186435af.cpp

// Candidate translation unit (score above; library headers required).
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
}

namespace Ogre {
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
    void setVisible(bool visible);
    void _updateRenderQueue(RenderQueue* queue);
    void removeSubEntity(RbxSubEntity* entity);
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
void RbxEntity::setVisible(bool visible) {
    for (int i = 0; i < (int)mSubEntityList.size(); ++i) mSubEntityList[i]->setVisible(visible);
}
void RbxEntity::_updateRenderQueue(RenderQueue* queue) {
    if (!mInitialised) return;
    if (mMeshLodIndex > 0 && mMesh->isLodManual()) {
        mLodEntityList[mMeshLodIndex - 1]->_updateRenderQueue(queue);
        return;
    }
    SubEntityList::iterator i, end;
    end = mSubEntityList.end();
    for (i = mSubEntityList.begin(); i != end; ++i) {
        if ((*i)->isVisible()) {
            if (mRenderQueueIDSet) queue->addRenderable(*i, mRenderQueueID);
            else queue->addRenderable(*i);
        }
    }
}
void RbxEntity::removeSubEntity(RbxSubEntity* entity) {
    SubEntityList::iterator i = std::find(mSubEntityList.begin(), mSubEntityList.end(), entity);
    if (i != mSubEntityList.end()) mSubEntityList.erase(i);
    delete entity;
}
}
