// constructor is declared by brickcache-profile/ViewNew/BrickMesh.h (INFERRED there from the create calls 004e5574 /
#include "ViewNewBrickBuild2008/BrickMeshCache2008.h"

namespace RBX
{
	extern bool shadowsEnabled;   // 0096de64 (INFERRED name, pbb-surface-profile/RenderLib/ViewBase2008.h)
	// INFERRED: 00942ec4 is the render-mode int; createMaterial 00551730 builds RenderNew materials when it is 0.
	extern int renderMode;

	namespace ViewNew
	{
		// INFERRED: original global float 00972758 (same name as ViewNewBrickCacheRecovery2008.cpp).
		extern float currentBevel;

		BrickMesh::BrickMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes, BrickColor color, int a, int b,
		                     int c, float scale)
		{
			meshKind = 1;

			if (a && b && c)
				buildBevel(size, surfaceTypes, color, a, b, c, scale);
			else
				buildBevel(size, surfaceTypes, color);

			if (shadowsEnabled && renderMode == 0)
			{
				G3D::Vector3 halfSize = size * 0.5f;
				buildShadowBox(G3D::Vector3(halfSize.x - currentBevel, halfSize.y - currentBevel, halfSize.z - currentBevel),
				               shadowVertices, shadowIndices);
			}
		}
	}
}

// INFERRED: method/global names and constructor argument types, evidenced by original calls.
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
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
