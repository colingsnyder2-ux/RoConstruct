// 2008-06 PBBMesh surface constructor; shadow accessor profile inferred from 004f4cb0.
// native-flags: /O2 /GS- /EHsc /MD /fp:fast /I{headers}/pbb-surface-profile /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// ViewNewPartMesh2008PBB | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 1315627a | roc native-status --write
#include "ViewNew/PBBMesh.h"
#include "ViewNewBrickBuild2008/BrickMeshCache2008.h"
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
