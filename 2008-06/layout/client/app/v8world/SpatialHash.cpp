#include "v8world/SpatialHash2008.h"
#include "v8world/Primitive2008.h"
#include "v8world/ContactManager2008.h"
#include <string.h>
#include <algorithm>
#include <G3D/System.h>

namespace RBX
{
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
}

namespace RBX
{
	void SpatialHash::onPrimitiveExtentsChanged(Primitive* p)
	{
		onPrimitiveExtentsChanged(p, p->getFastFuzzyExtents());
	}
}
