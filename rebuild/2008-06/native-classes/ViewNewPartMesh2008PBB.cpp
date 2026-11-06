// 2008-06 native RBX::ViewNew::PBBMesh surface constructor 004f4cb0 (inactive). It reads the shadows flag 0096de64,
// the donor's ViewBase::getShadowsEnabled() function-local static, which RenderLib/ViewBase2008.h does not declare yet:
// the body is built only with NATIVE_VIEWNEW_BRICK_BUILD_PENDING (tests/record_native_viewnew_brick_build.py generates
// the ViewBase2008.h copy with that declaration under out/).
#include "ViewNew/PBBMesh.h"
#include "ViewNewBrickBuild2008/BrickMeshCache2008.h"
#ifdef NATIVE_VIEWNEW_BRICK_BUILD_PENDING
#include "RenderLib/ViewBase2008.h"

namespace RBX
{
	namespace ViewNew
	{
		PBBMesh::PBBMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes)
		{
			{
				G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level = new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS);
				levels.push_back(level);

				PBBBuilder builder(level, size, surfaceTypes);
				builder.build(LevelBuilder::Surface);
			}

			if (ViewBase::getShadowsEnabled())
				buildShadowBox(size * 0.5f, shadowVertices, shadowIndices);
		}
	}
}
#endif
