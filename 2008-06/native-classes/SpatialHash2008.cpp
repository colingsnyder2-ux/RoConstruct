// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::SpatialHash (inactive); evidence in native-headers/v8world/SpatialHash2008.h.
#include "v8world/SpatialHash2008.h"
#include "v8world/Primitive2008.h"
#include "v8world/ContactManager2008.h"
#include <string.h>
#include <algorithm>
#include <G3D/System.h>
#include <utility>

namespace RBX
{
	// 0065b4e0
	SpatialHash::SpatialHash(World* world, ContactManager* contactManager)
		: field0(0), world(world), contactManager(contactManager),
		  freeNodes(0), freeNodes2(0), freeTreeNodes(0), nodesOut(0), maxBucket(0)
	{
		for (int i = 0; i < spatialHashLevels; i++)
		{
			levels[i].resize(0x10000 >> i);
			memset(&levels[i][0], 0, levels[i].size() * sizeof(SpatialBucket));
		}
	}

	// 0065b1b0
	SpatialHash::~SpatialHash()
	{
		for (int i = 0; i < spatialHashLevels; i++)
		{
			if (levels[i].size())
			{
				for (unsigned int b = 0; b < (unsigned int)(0x10000 >> i); b++)
				{
					while (levels[i][b].nodes)
					{
						SpatialNode* node = levels[i][b].nodes;
						levels[i][b].nodes = levels[i][b].nodes->nextHashLink;
						delete node;
						nodesOut--;
					}
					while (levels[i][b].treeNodes)
					{
						SpatialTreeNode* node = levels[i][b].treeNodes;
						levels[i][b].treeNodes = levels[i][b].treeNodes->next;
						delete node;
					}
				}
			}
		}
		while (freeNodes)
		{
			SpatialNode* node = freeNodes;
			freeNodes = node->nextHashLink;
			delete node;
		}
		while (freeNodes2)
		{
			SpatialNode* node = freeNodes2;
			freeNodes2 = node->nextHashLink;
			delete node;
		}
		while (freeTreeNodes)
		{
			SpatialTreeNode* node = freeTreeNodes;
			freeTreeNodes = node->next;
			delete node;
		}
	}

	// 00659670 (registry func_00659670, `ret 0xc`; callers newNode 00659f90 and addNode 0065a220): walks the tree-node
	// chain of levels[level][hash] (.treeNodes +4, next +0x28) for the node whose grid (+0x1c..+0x24) equals grid.
	SpatialTreeNode* SpatialHash::findTreeNode(int level, int hash, const Vector3int32& grid)
	{
		SpatialTreeNode* node = levels[level][hash].treeNodes;
		while (node)
		{
			if (node->gridId == grid)
				return node;
			node = node->next;
		}
		return NULL;
	}

	// 0065a220 (registry func_0065a220, `ret 0xc`): donor SpatialHash::addNode for one grid level, then the same pair search
	// in each coarser level (grid >> 1 per level up to spatialHashLevels 009625a8), linking the cell into the tree nodes
	// (00659670 find / 006596d0 new; child bit x + 2y + 4z of the original grid at that depth) until a child is already
	// present; a level > 0 node then pairs against its tree (00659a10). onNewPair 0060d8b0 through contactManager +0x8,
	// Primitive::getContact 005e7d30, nodesOut +0x78, maxBucket +0x7c (std::max form).
	// PARKED (batch 29, 698 B vs 695 B): same stack frame, call order and control flow; the residue is register
	// allocation only (target keeps grid in edi / the node in ebp and the bucket pointer in ebx, so the child bit uses bl;
	// here grid is ebp and the bit goes through dl/cl). Rejected: `childMask & (1 << child)` inline (731 B), the
	// coarser grid as `Vector3int32(x >> 1, y >> 1, z >> 1)` (699 B, worse shift order), reading childMask into a local
	// first (no change). Kept: getHash written x, y, z (donor order) halves the diff against the z, y, x spelling.
	// Batch 37 rejected: getHash as the rbxgs donor two-statement form (`int result = ...; result &= mask;`, unchanged
	// 698 B), `childMask & (unsigned char)(1 << child)` inline in both uses (732 B), the openrbx insertNodeToPrimitive
	// helper inlined for the node stores (unchanged 698 B). The hash itself already matches (z, y, x products, same
	// xor association); the residue is the this / grid / node register permutation (target ebx / edi / ebp).
	void SpatialHash::addNode(int level, Primitive* p, const Vector3int32& grid)
	{
		int hash = getHash(level, grid);

		++nodesOut;
		SpatialNode* node = newNode(level, hash, grid);

		node->primitive = p;
		node->gridId = grid;
		node->hashId = hash;

		SpatialNode* oldNodes = p->spatialNodes;
		p->spatialNodes = node;
		node->nextPrimitiveLink = oldNodes;
		node->prevPrimitiveLink = NULL;
		if (oldNodes)
			oldNodes->prevPrimitiveLink = node;

		SpatialNode* linkedNode = levels[level][hash].nodes;
		node->nextHashLink = linkedNode;
		levels[level][hash].nodes = node;

		int numNodes = 1;
		Vector3int32 levelGrid = grid;
		int childHash = -1;
		bool linkTree = true;

		for (int i = level; i < spatialHashLevels; i++)
		{
			if (i > level)
			{
				levelGrid.x >>= 1;
				levelGrid.y >>= 1;
				levelGrid.z >>= 1;
				hash = getHash(i, levelGrid);
				linkedNode = levels[i][hash].nodes;
			}

			for (; linkedNode; linkedNode = linkedNode->nextHashLink)
			{
				++numNodes;

				Primitive* linkedP = linkedNode->primitive;
				if (linkedP != p && linkedNode->gridId == levelGrid)
				{
					if (!Primitive::getContact(p, linkedP))
						contactManager->onNewPair(p, linkedP);
				}
			}

			if (i > level && linkTree)
			{
				SpatialTreeNode* tree = findTreeNode(i, hash, levelGrid);
				if (!tree)
					tree = newTreeNode(i, hash, levelGrid);

				int shift = i - level - 1;
				int child = ((grid.x >> shift) & 1) + 2 * (((grid.y >> shift) & 1) + 2 * ((grid.z >> shift) & 1));
				unsigned char bit = (unsigned char)(1 << child);
				if (tree->childMask & bit)
				{
					linkTree = false;
				}
				else
				{
					tree->childMask |= bit;
					tree->children[child] = (unsigned short)childHash;
				}
			}
			childHash = hash;
		}

		if (node->level > 0)
			addTreePairs(static_cast<SpatialLevelNode*>(node)->treeNode, p);

		maxBucket = std::max(maxBucket, numNodes);
	}

	// 00659370 (placeholder sub_00659370, body in native-classes/Inferred_00659370.cpp): the int box shifted from one
	// grid level to another. Declared here exactly as that unit defines it.
	std::pair<Vector3int32, Vector3int32> __cdecl sub_00659370(int fromLevel, int toLevel, const std::pair<Vector3int32, Vector3int32>& source);
}

// 00659330 (cdecl int-box overlap, body in native-classes/DonorCtx_00659330.cpp, declared as it defines it).
bool __cdecl intersects(const RBX::Vector3int32* a, const RBX::Vector3int32* b);

namespace RBX
{
	// 006593d0 (registry placeholder func_006593d0; caller onPrimitiveExtentsChanged / the pair release path): both
	// primitives need a spatial node (+0x64); equal levels (+0x20) test the two old spatial boxes (+0x68: min, +0x74:
	// max) directly, otherwise the box of the lower-level primitive is shifted up to the higher level first. INFERRED:
	// the box view of oldSpatialMin / oldSpatialMax as one pair (the two members are contiguous).
	// PARKED (batch 46): 142 B, same instructions and control flow, register permutation only (target: me edi, other
	// eax, high esi; here me esi, other edx, high edi). Rejected: level reads inline in both compares (144 B), named
	// SpatialNode locals tested one by one (144 B).
	bool SpatialHash::shareCommonGrid(Primitive* me, Primitive* other)
	{
		if (!me->spatialNodes || !other->spatialNodes)
			return false;

		int meLevel = me->spatialNodes->level;
		int otherLevel = other->spatialNodes->level;

		if (meLevel == otherLevel)
			return intersects(&me->oldSpatialMin, &other->oldSpatialMin);

		Primitive* high = meLevel > otherLevel ? me : other;
		Primitive* low = high == me ? other : me;

		std::pair<Vector3int32, Vector3int32> lowBox = sub_00659370(low->spatialNodes->level, high->spatialNodes->level,
			*reinterpret_cast<const std::pair<Vector3int32, Vector3int32>*>(&low->oldSpatialMin));

		return intersects(&high->oldSpatialMin, &lowBox.first);
	}
}
