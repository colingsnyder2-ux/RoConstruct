// 2008-06 native RBX::Edge rows (inactive) of the Edge unit 00659260..006592a9, against
// native-headers/AppUnit658/Edge.h. Verified by tests/record_native_app_unit658.py.
#include "AppUnit658/Edge.h"

namespace RBX
{
	// 00659260
	Edge::Edge(Primitive* prim0, Primitive* prim1)
		: edgeState(Sim::UNDEFINED),
		  prim0(prim0),
		  prim1(prim1),
		  index0(-1),
		  index1(-1),
		  inEdgeList(false)
	{
	}

	// 00659290
	void Edge::setPrimitive(int i, Primitive* p)
	{
		if (i == 0)
			prim0 = p;
		else
			prim1 = p;
	}
}

// SpatialHash rows 006597d0 / 00659830 / 00659890 (registry placeholders; assigned to this file by batch 47 from their
// address neighbourhood). They are RBX::SpatialHash members of the SpatialHash unit (native-classes/SpatialHash2008.cpp
// holds its other rows 00659370 / 006593d0 / 0065a220 ...), whose header v8world/SpatialHash2008.h does not declare them.
// GUARDED until that header carries the proposal lines
//     void releaseTreeNode(SpatialTreeNode* node);                     // 006597d0
//     void removeNodeFromHash(SpatialNode* remove);                    // 00659830
//     SpatialNode* findNode(Primitive* p, const Vector3int32& grid);   // 00659890
// (the owner can then move the bodies into SpatialHash2008.cpp). A scratch build of SpatialHash2008.cpp with those lines
// and these bodies is byte-identical at all three addresses (relocs masked).
#ifdef SPATIALHASH_HEADER_DECLARES_NODE_HELPERS
#include "v8world/SpatialHash2008.h"
#include "v8world/Primitive2008.h"

namespace RBX
{
	// 006597d0 (`ret 4`; callers 006599e2 (00659920 below) and 0065a1c9): unlinks a tree node from the second chain of
	// its bucket (levels[level +0x10][hashId +0x18].treeNodes, next +0x28) and pushes it on freeTreeNodes (+0x74).
	// INFERRED name (no donor counterpart: the 2007 SpatialHash has no tree levels).
	void SpatialHash::releaseTreeNode(SpatialTreeNode* node)
	{
		SpatialTreeNode** temp = &levels[node->level][node->hashId].treeNodes;
		while (*temp != node)
			temp = &(*temp)->next;
		*temp = node->next;
		node->next = freeTreeNodes;
		freeTreeNodes = node;
	}

	// 00659830 (`ret 4`; caller 0065a0af): donor SpatialHash::removeNodeFromHash on the node's own level (word +0x20).
	void SpatialHash::removeNodeFromHash(SpatialNode* remove)
	{
		SpatialNode** temp = &levels[remove->level][remove->hashId].nodes;
		while (*temp != remove)
			temp = &(*temp)->nextHashLink;
		*temp = remove->nextHashLink;
	}

	// 00659890 (`ret 8`; caller 0065a6a3): donor SpatialHash::findNode at the level of the primitive's first node
	// (spatialNodes +0x64, level +0x20); the 2008 loop also stops at the end of the chain (returns NULL).
	SpatialNode* SpatialHash::findNode(Primitive* p, const Vector3int32& grid)
	{
		int level = p->spatialNodes->level;
		int hash = getHash(level, grid);
		SpatialNode* result = levels[level][hash].nodes;
		while (result->primitive != p || result->gridId != grid)
		{
			result = result->nextHashLink;
			if (!result)
				break;
		}
		return result;
	}
}
#endif
