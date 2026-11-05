// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_try_b0a3250dc05458b4.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <OgreSubEntity.h>
#include <OgreSubMesh.h>
#include <OgreMatrix4.h>
namespace Ogre {
class RbxSubEntity : public SubEntity {
public:
    __declspec(align(16)) Matrix4 transform;
    SubMesh* lodMeshes[1];
    unsigned int lodIndex;
    SubMesh* getSubMesh(unsigned int lod);
    SubMesh* getCurrentSubMesh();
    void getRenderOperation(RenderOperation& operation);
    const Vector3& getPosition() const;
};
SubMesh* RbxSubEntity::getSubMesh(unsigned int lod) {
    if (!lod) return mSubMesh;
    return lodMeshes[lod - 1];
}
SubMesh* RbxSubEntity::getCurrentSubMesh() {
    int lod = 0;
    while (!lodMeshes[lod]) {
        if (--lod < 0) return mSubMesh;
    }
    return lodMeshes[lod] ? lodMeshes[lod] : mSubMesh;
}
void RbxSubEntity::getRenderOperation(RenderOperation& operation) {
    getSubMesh(lodIndex)->_getRenderOperation(operation, 0);
}
const Vector3& RbxSubEntity::getPosition() const {
    static Vector3 position(transform[0][3], transform[1][3], transform[2][3]);
    return position;
}
}
