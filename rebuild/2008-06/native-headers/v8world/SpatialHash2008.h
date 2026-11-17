#pragma once
// 2008-06 native RBX::SpatialHash (inactive). Non-colliding path: the donor v8world/SpatialHash.h describes a different
// (2009-era) layout and is included by the donor World.h / ContactManager.h. A unit must not include both.
// Layout read from the 2008-06 binary (ctor 0065b4e0, dtor 0065b1b0, level resize helper 0065b430):
//   +0x00 int (zeroed by the ctor, never read by the two bodies)
//   +0x04 world, +0x08 contactManager (ctor arguments)
//   +0x0c four std::vector<Bucket> (eh-vector ctor 004293d0 / dtor 0067fb10 shape, 0x18 each) = one per grid level.
//         ctor: for level i < levelCount (global 009625a8): resize(0x10000 >> i) then memset to zero.
//   +0x6c / +0x70 / +0x74 / +0x78 / +0x7c: free node lists (next at +4, +4, +0x28) and the live node count / max
//   +0x80 G3D::Array (data/num/numAllocated, released with G3D::System::alignedFree 00507d20 and cleared).
//   Bucket (8 bytes): heads of two singly linked chains (first through node +4, second through node +0x28).
namespace RBX
{
	class Primitive;
	class World;
	class ContactManager;
}
#include <vector>
#include <G3D/Array.h>

namespace RBX
{
	// INFERRED: next-link at +4 (dtor 0065b1b0 loads [node+4]); the other fields follow the donor SpatialNode.
	struct SpatialNode
	{
		Primitive* primitive;
		SpatialNode* nextHashLink;
	};

	// INFERRED: next-link at +0x28 (dtor 0065b1b0 loads [node+0x28]); the preceding fields are unread by the recovered bodies.
	struct SpatialPrimitiveNode
	{
		Primitive* primitive;
		float extents[6];                               // INFERRED: 0x18 bytes of float data between +4 and +0x1c
		int gridMin[3];                                 // INFERRED
		SpatialPrimitiveNode* nextPrimitiveLink;        // +0x28
	};

	struct SpatialBucket
	{
		SpatialNode* nodes;                             // +0
		SpatialPrimitiveNode* primitives;               // +4
	};

	extern int spatialHashLevels;                       // 009625a8 INFERRED name

	class SpatialHash
	{
	private:
		int field0;                                     // +0x00 INFERRED: zeroed by the ctor, unread
		World* world;                                   // +0x04
		ContactManager* contactManager;                 // +0x08
		std::vector<SpatialBucket> levels[4];           // +0x0c
		SpatialNode* freeNodes;                         // +0x6c
		SpatialNode* freeNodes2;                        // +0x70 INFERRED: second SpatialNode-shaped free list (next at +4)
		SpatialPrimitiveNode* freePrimitiveNodes;       // +0x74
		int nodesOut;                                   // +0x78
		int maxBucket;                                  // +0x7c
		G3D::Array<SpatialNode*> extraNodes;            // +0x80 INFERRED: G3D::Array shape (data +0x80, num +0x84, numAllocated +0x88; its destructor is alignedFree 00507d20 then zeroing, ctor stores num, numAllocated, data)

	public:
		SpatialHash(World* world, ContactManager* contactManager);   // 0065b4e0
		~SpatialHash();                                              // 0065b1b0
	};
}
