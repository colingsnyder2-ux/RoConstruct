#pragma once
#include <vector>
#include "util/Extents.h"
#include "util/Vector3int32.h"

namespace RBX
{
	class Primitive;
	class World;
	class ContactManager;

	class SpatialNode
	{
	public:
		Primitive* primitive;
		SpatialNode* nextHashLink;
		SpatialNode* nextPrimitiveLink;
		SpatialNode* prevPrimitiveLink;
		int hashId;
		Vector3int32 gridId;

	public:
		SpatialNode()
			: gridId()
		{
		}
	};

	class SpatialHash
	{
	private:
		World* world;
		ContactManager* contactManager;
		std::vector<SpatialNode*> nodes;
		SpatialNode* extraNodes;
		int nodesOut;
		int maxBucket;
	  
	private:
		SpatialNode* newNode();
		void returnNode(SpatialNode*);
		bool shareCommonGrid(Primitive* me, Primitive* other);
		bool hashHasPrimitive(Primitive*, int, const Vector3int32&);
		SpatialNode* findNode(Primitive* p, const Vector3int32& grid);
		void removeNodeFromHash(SpatialNode* remove);
		void insertNodeToPrimitive(SpatialNode*, Primitive*, const Vector3int32&, int);
		void removeNodeFromPrimitive(SpatialNode*);
		void addNode(Primitive* p, const Vector3int32& grid);
		void destroyNode(SpatialNode* destroy);
		void changeMinMax(Primitive* p, const Extents& change, const Extents& oldBox, const Extents& newBox);
		void primitiveExtentsChanged(Primitive* p);
		unsigned int numNodes(unsigned int) const;
	public:
		//SpatialHash(const SpatialHash&);
		SpatialHash(World*, ContactManager*);
		~SpatialHash();
	public:
		void onPrimitiveAdded(Primitive* p);
		void onPrimitiveRemoved(Primitive* p);
		void onPrimitiveExtentsChanged(Primitive* p);
		void onAllPrimitivesMoved();
		void getPrimitivesInGrid(const Vector3int32& grid, G3D::Array<Primitive*>& found);
		bool getNextGrid(Vector3int32&, const G3D::Ray&, float);
		void getPrimitivesTouchingExtents(const Extents& extents, const Primitive* ignore, G3D::Array<Primitive*>& answer);
		int getNodesOut() const
		{
			return nodesOut;
		}

		int getMaxBucket() const
		{
			return maxBucket;
		}
		void doStats() const;
		//SpatialHash& operator=(const SpatialHash&);
	  
	private:
		static float hashGridSize();
		static float hashGridRecip();
		static size_t numBuckets();
		static size_t numBits();
		static int getHash(const Vector3int32& grid);
		static Extents computeMinMax(const Extents&);
		static void computeMinMax(const Extents& extents, Vector3int32& min, Vector3int32& max);
		static void computeMinMax(const Primitive*, Vector3int32&, Vector3int32&);
	public:
		static Vector3int32 realToHashGrid(const G3D::Vector3& realPoint);
		static G3D::Vector3 hashGridToReal(const G3D::Vector3&);
		static Extents hashGridToRealExtents(const G3D::Vector3& hashGrid);
	};
}
