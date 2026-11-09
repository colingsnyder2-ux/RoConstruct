// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5-dll roc_ogre_resume_0dfdb9b464d9c5b7.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
namespace Ogre {
class RbxSubMesh : public SubMesh { public: bool prepared; EdgeData* edges; AxisAlignedBox bounds; Real radius; };
class RbxSubEntity : public SubEntity, public ShadowCaster {
public:
    Matrix4 transform;
    SubMesh* lodMeshes[1];
    unsigned int lodIndex;
    unsigned int unknown138;
    bool castShadows;
    SubMesh* shadow;
    std::vector<ShadowRenderable*> shadows;
    RbxSubEntity(Entity* parent);
    RbxSubEntity(Entity* parent, SubMesh* mesh, unsigned int lod);
    ~RbxSubEntity();
    SubMesh* getCurrentSubMesh() const;
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
    const Quaternion& getOrientation() const;
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
const Quaternion& RbxSubEntity::getOrientation() const {
    LogManager::getSingleton().logMessage("RBX perf warning!");
    static Quaternion orientation = transform.extractQuaternion();
    return orientation;
}
SubMesh* RbxSubEntity::getCurrentSubMesh() const {
    for (int lod = 0; lod >= 0; --lod)
        if (lodMeshes[lod]) return lodMeshes[lod] ? lodMeshes[lod] : mSubMesh;
    return mSubMesh;
}
const AxisAlignedBox& RbxSubEntity::getDarkCapBounds(const Light& light, Real distance) const {
    static AxisAlignedBox box;
    box = getLightCapBounds();
    extrudeBounds(box, light.getAs4DVector(), distance);
    return box;
}
const AxisAlignedBox& RbxSubEntity::getWorldBoundingBox(bool derive) const {
    static AxisAlignedBox box;
    RbxSubMesh* mesh = static_cast<RbxSubMesh*>(shadow ? shadow : getCurrentSubMesh());
    Vector3 position = transform.getTrans();
    Real radius = mesh->radius * 1.7f;
    box.setExtents(position + Vector3(-radius, -radius, -radius), position + Vector3(radius, radius, radius));
    return box;
}

}
