#include "OgreRbx/RbxSubMesh2008.h"
#include <OgreEdgeListBuilder.h>

namespace Ogre
{
	RbxSubMesh::RbxSubMesh()
		: rbxFlag(false)
		, edgeData(0)
		, bounds()
	{
	}

	RbxSubMesh::~RbxSubMesh()
	{
		delete edgeData;
	}

	void RbxSubMesh::prepareEdges()
	{
		if (!rbxFlag)
		{
			vertexData->prepareForShadowVolume();
			rbxFlag = true;
			EdgeListBuilder builder;
			builder.addVertexData(vertexData);
			builder.addIndexData(indexData, 0, operationType);
			edgeData = builder.build();
		}
	}
}
