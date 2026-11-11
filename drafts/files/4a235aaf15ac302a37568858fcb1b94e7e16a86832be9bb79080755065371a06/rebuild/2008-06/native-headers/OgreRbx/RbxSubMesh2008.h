#pragma once
// Ogre::RbxSubMesh: exe-local SubMesh extension.
// Original evidence: 00678470 calls imported SubMesh(), clears +0xc4/+0xc8,
// then constructs AxisAlignedBox at +0xcc. 006824e0 destroys EdgeData* +0xc8,
// AxisAlignedBox +0xcc, then imported ~SubMesh(). Base size is therefore 0xc4.
#include <OgreSubMesh.h>
#include <OgreAxisAlignedBox.h>

namespace Ogre
{
	class EdgeData;

	class RbxSubMesh : public SubMesh
	{
		bool rbxFlag;                 // +0xc4
		EdgeData* edgeData;           // +0xc8
		AxisAlignedBox bounds;        // +0xcc

	public:
		RbxSubMesh();                 // 00678470
		~RbxSubMesh();                // 006824e0
	};
}
