// INFERRED: method/global names and constructor argument types, evidenced by original calls.
// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /I{headers}/brickcache-profile /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// ViewNewBrickCacheRecovery2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 614ed767 | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#include "ViewNewBrickBuild2008/BrickMeshCache2008.h"
#include <G3D/g3dmath.h>
#include <algorithm>
namespace RBX { namespace ViewNew {
// INFERRED: original global accesses at 009413c0 / 0097275c / 00972758.
extern bool useBevels;
extern bool buildingBevel;
extern float currentBevel;
G3D::ReferenceCountedPointer<RenderBase::Mesh> BrickMesh::create(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes, BrickColor color) {
 Lookup lookup = {size, surfaceTypes, color};
 boost::call_once(initCache, cacheFlag);
 Cache* c = cache;
 boost::recursive_mutex::scoped_lock lock(c->mutex);
 Variations& variation = c->meshes[lookup];
 size_t index = variation.count == 4 ? G3D::iRandom(0, 3) : std::min(3, G3D::iRandom(0, 8));
 G3D::ReferenceCountedPointer<RenderBase::Mesh> thisMesh = variation.meshes[index];
 if (thisMesh.isNull()) {
  buildingBevel = false;
  if (useBevels) {
   currentBevel = 0.065f;
   thisMesh = new BrickMesh(size, surfaceTypes, color, 0, 0, 0, 0.0f);
   currentBevel = 0.0f;
   buildingBevel = true;
   dynamic_cast<BrickMesh*>(thisMesh.getPointer())->buildBevel(size, surfaceTypes, color);
   buildingBevel = false;
  } else {
   currentBevel = 0.0f;
   thisMesh = new BrickMesh(size, surfaceTypes, color, 0, 0, 0, 0.0f);
  }
  variation.meshes[index] = thisMesh;
  variation.count++;
  if (++c->count % 100 == 0) {
   G3D::ReferenceCountedPointer<RenderBase::Mesh> keep = variation.meshes[index];
   releaseUnused();
  }
 }
 return thisMesh;
}
// INFERRED: helper name from donor; original uses seven-argument factory at 004e54e0.
G3D::ReferenceCountedPointer<RenderBase::Mesh> createSpecialBrick(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes, BrickColor color, int a, int b, int c, float scale) {
 G3D::ReferenceCountedPointer<RenderBase::Mesh> result;
 buildingBevel = false;
 if (useBevels) {
  currentBevel = 0.065f;
  result = new BrickMesh(size, surfaceTypes, color, a, b, c, scale);
  currentBevel = 0.0f;
  buildingBevel = true;
  dynamic_cast<BrickMesh*>(result.getPointer())->buildBevel(size, surfaceTypes, color, a, b, c, scale);
  buildingBevel = false;
 } else {
  currentBevel = 0.0f;
  result = new BrickMesh(size, surfaceTypes, color, a, b, c, scale);
 }
 return result;
}
}}
