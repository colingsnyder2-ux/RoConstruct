// INFERRED: inline accessors from 004f0390 and 004f0605; Mesh member access from 004f0511.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/partsurface-profile /I{headers}/part-embedded /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// ViewNewPartSurfaceUpdate2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src ae5dec7c | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#include "ViewNew/PartChunk.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/SpecialShape.h"
#include "v8datamodel/Decal.h"
#include "ViewNew/SphereMesh.h"
#include "ViewNew/PBBMesh.h"
#include "ViewNew/CylinderMesh.h"
#include "ViewNew/HeadMesh.h"
#include "ViewNew/TorsoMesh.h"
#include "ViewNew/WedgeMesh.h"
#include <cmath>
namespace RBX { namespace ViewNew {
static inline float maxf(float a, float b) { return a > b ? a : b; }
void Decal::updateMesh() {
 if (!partInstance) return;
 G3D::Vector3 size = partInstance->getPartSizeXml();
 if (specialShape) { const G3D::Vector3& scale = specialShape->getScale(); size.x = scale.x * size.x; size.y = scale.y * size.y; size.z = scale.z * size.z; }
 if (!specialShape) {
  switch (partInstance->getPartType()) {
   case 0: mesh = SphereMesh::createDecal(size, decal->getFace()); break;
   case 1: mesh = PBBMesh::createDecal(size, decal->getFace()); break;
   case 2: mesh = CylinderAlongXMesh::createDecal(size, decal->getFace()); break;
  }
 } else {
  switch (specialShape->getMeshType()) {
   case 2: mesh = WedgeMesh::createDecal(size, decal->getFace()); break;
   case 0: mesh = HeadMesh::createDecal(size, decal->getFace()); break;
   case 1: mesh = TorsoMesh::createDecal(size, decal->getFace()); break;
   case 3: mesh = SphereMesh::createDecal(size, decal->getFace()); break;
   case 4: mesh = CylinderAlongXMesh::createDecal(size, decal->getFace()); break;
   case 6: mesh = PBBMesh::createDecal(size, decal->getFace()); break;
  }
 }
 float s2 = (float)sqrt(2.0);
 float ax = fabs(size.x), ay = fabs(size.y), az = fabs(size.z);
 float d = s2 * maxf(maxf(ax, ay), az);
 radius = d * 0.5f;
 if (mesh.getPointer()) mesh->meshKind = 4;
}
void Texture::updateMesh() {
 if (!partInstance) return;
 G3D::Vector3 size = partInstance->getPartSizeXml();
 if (specialShape) { const G3D::Vector3& scale = specialShape->getScale(); size.x = scale.x * size.x; size.y = scale.y * size.y; size.z = scale.z * size.z; }
 if (!specialShape) {
  switch (partInstance->getPartType()) {
   case 0: mesh = SphereMesh::createTexture(size, decal->getFace(), decal->getStudsPerTile()); break;
   case 1: mesh = PBBMesh::createTexture(size, decal->getFace(), decal->getStudsPerTile()); break;
   case 2: mesh = CylinderAlongXMesh::createTexture(size, decal->getFace(), decal->getStudsPerTile()); break;
  }
 } else {
  switch (specialShape->getMeshType()) {
   case 2: mesh = WedgeMesh::createTexture(size, decal->getFace(), decal->getStudsPerTile()); break;
   case 0: mesh = HeadMesh::createTexture(size, decal->getFace(), decal->getStudsPerTile()); break;
   case 1: mesh = TorsoMesh::createTexture(size, decal->getFace(), decal->getStudsPerTile()); break;
   case 3: mesh = SphereMesh::createTexture(size, decal->getFace(), decal->getStudsPerTile()); break;
   case 4: mesh = CylinderAlongXMesh::createTexture(size, decal->getFace(), decal->getStudsPerTile()); break;
   case 6: mesh = PBBMesh::createTexture(size, decal->getFace(), decal->getStudsPerTile()); break;
  }
 }
 float s2 = (float)sqrt(2.0);
 float ax = fabs(size.x), ay = fabs(size.y), az = fabs(size.z);
 float d = s2 * maxf(maxf(ax, ay), az);
 radius = d * 0.5f;
}

}}
