#include "v8world/SpatialHash2008.h"
#include <string.h>
#include <G3D/System.h>

namespace RBX
{
	SpatialHash::SpatialHash(World* world, ContactManager* contactManager)
		: field0(0), world(world), contactManager(contactManager),
		  freeNodes(0), freeNodes2(0), freePrimitiveNodes(0), nodesOut(0), maxBucket(0)
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
					while (levels[i][b].primitives)
					{
						SpatialPrimitiveNode* node = levels[i][b].primitives;
						levels[i][b].primitives = levels[i][b].primitives->nextPrimitiveLink;
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
		while (freePrimitiveNodes)
		{
			SpatialPrimitiveNode* node = freePrimitiveNodes;
			freePrimitiveNodes = node->nextPrimitiveLink;
			delete node;
		}
	}
}
