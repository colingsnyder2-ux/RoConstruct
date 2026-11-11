// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
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
}
