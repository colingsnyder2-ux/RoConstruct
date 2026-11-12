#pragma once
// >>> native-status (generated) -- do not edit >>>
// BrickMesh | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 1c975ca4 | roc native-status --write
// 2008-06 native RBX::ViewNew::BrickMesh (inactive; only what the ViewNew units here use).
//   vtable 00826e7c .?AVBrickMesh@ViewNew@RBX@@ -> RenderBase::Mesh -> ReferenceCountedObject (mdisp 0; no MeshFactory
//   base); one slot (??_G 004e54c0). ctor 004e53c0 (meshKind 1; ret 0x1c) and the cache in 004e54e0 / 004e5300 are not
//   recovered here (their helpers 004e2c80 / 004e3720 / 004e3570 and globals 0096de64 / 00942ec4 / 00972758 are
//   unnamed).
//   normalPerturbation  const float 0.05f at 00826e3c, read by the BrickMesh unit (004de50e..) and by the PBB
//                       perturbation ctor 004f2030 (fld [00826e3c]).
//   Static cache (pass 2; definitions and bodies in native-headers/ViewNewBrickBuild2008/BrickMeshCache2008.h):
//   cache 00972754 (new 0x30 in initCache 004e5360), once flag 00972870 (call_once 00557330), flushCache 004e5670
//   (called by the ViewG3D / ViewRbxGfx dtors 004dc2c0 / 004db58c), releaseUnused 004e5710. Cache, cache, cacheFlag,
//   initCache and releaseUnused are descriptive names (no symbols); flushCache follows the donor BrickMesh.h.
#include "ViewNew/RenderBaseMesh.h"
#include <boost/thread/once.hpp>
#include "ViewNew/QuadVolume.h"
#include "v8datamodel/BrickColor.h"

namespace RBX
{
	namespace ViewNew
	{
		class BrickMesh : public RenderBase::Mesh
		{
		public:
			static const float normalPerturbation;    // 00826e3c
			static const float bevel;                 // 00826e38 (0.0f; read only by the PBB Face / Side strips)

			struct Cache;
		private:
			static Cache* cache;                      // 00972754
			static boost::once_flag cacheFlag;        // 00972870
			static void initCache();                  // 004e5360
			static void releaseUnused();              // 004e5710
		public:
			static void flushCache();
			// INFERRED: constructor and build methods from 004e53c0 / 004e5a40 calls.
			BrickMesh(const G3D::Vector3&, RenderSurfaceTypes, BrickColor, int, int, int, float);
			void buildBevel(const G3D::Vector3&, RenderSurfaceTypes, BrickColor);
			// INFERRED: 004e55ce passes seven arguments to 004e3720.
			void buildBevel(const G3D::Vector3&, RenderSurfaceTypes, BrickColor, int, int, int, float);
			static G3D::ReferenceCountedPointer<RenderBase::Mesh> create(const G3D::Vector3&, RenderSurfaceTypes, BrickColor);                 // 004e5670
		};
	}
}
