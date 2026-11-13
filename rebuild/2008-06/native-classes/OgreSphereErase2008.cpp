// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#undef OGRE_NONCLIENT_BUILD
#include "OgreRbxNode/RbxSceneNode2008.h"
namespace Ogre {
// INFERRED: name and pointer type; original 00682150 erases from the sphere map.
bool eraseSphere(const void* key) {
 if (!RbxSceneNode::spheres) return false;
 RbxSceneNode::SphereMap::iterator i = RbxSceneNode::spheres->find(key);
 if (i != RbxSceneNode::spheres->end()) {
  RbxSceneNode::spheres->erase(i);
  return true;
 }
 return false;
}
}
