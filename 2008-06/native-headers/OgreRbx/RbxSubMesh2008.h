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
		friend class RbxSubEntity;

		bool rbxFlag;                 // +0xc4
		EdgeData* edgeData;           // +0xc8
		AxisAlignedBox bounds;        // +0xcc
		Real radius;                  // +0xec; 0067c130 allocates 0xf0 and stores bounds half-size length here

	public:
		RbxSubMesh();                 // 00678470
		~RbxSubMesh();                // 006824e0
		void prepareEdges();          // 00682430; exact caller 00685a40 proves decorated identity
	};
	typedef char RbxSubMesh2008Size[(sizeof(RbxSubMesh) == 0xf0) ? 1 : -1];
}
