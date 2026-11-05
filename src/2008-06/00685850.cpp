// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_try_7d4794109b155f59.cpp

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
