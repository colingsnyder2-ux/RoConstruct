// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5-dll roc_espeon_subentitydistance81be14ca97c968f3.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include "OgreSubEntity.h"
#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreCamera.h"
#include "OgreMatrix4.h"
namespace Ogre {
class RbxSceneNode:public SceneNode {};
class RbxSubEntity:public SubEntity {
 unsigned fieldEC;
 Matrix4 transform;
 public: Real getSquaredViewDepth(const Camera* cam) const;
};
Real RbxSubEntity::getSquaredViewDepth(const Camera* cam) const {
 if(mCachedCamera==cam)return mCachedCameraDist;
 RbxSceneNode* node=dynamic_cast<RbxSceneNode*>(mParentEntity->getParentNode());
 Vector3 position=transform.getTrans();
 return (position-cam->getDerivedPosition()).squaredLength();
}
}
