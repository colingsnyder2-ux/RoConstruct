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
	class Extents;
}
#include <vector>
#include <G3D/Array.h>
#include "util/Vector3int32.h"

namespace RBX
{
	struct SpatialTreeNode;

	// Hash node, 0x24 bytes at level 0 (00659f90: `push 0x24` / free list +0x6c) and 0x28 above it (SpatialLevelNode,
	// `push 0x28` / free list +0x70). Offsets from the node insert 0065a220: primitive +0, bucket chain +4 (dtor 0065b1b0
	// loads [node+4]), the primitive's node list +8 / +0xc (doubly linked through Primitive +0x64), hash +0x10, grid
	// +0x14..+0x1c (compared field by field), level as a word at +0x20 (00659f90 `mov word ptr [esi+0x20], bp`).
	// Field names follow the donor SpatialNode (tools/rbxgs v8world/SpatialHash.h).
	struct SpatialNode
	{
		Primitive* primitive;                           // +0x00
		SpatialNode* nextHashLink;                      // +0x04
		SpatialNode* nextPrimitiveLink;                 // +0x08
		SpatialNode* prevPrimitiveLink;                 // +0x0c
		int hashId;                                     // +0x10
		Vector3int32 gridId;                            // +0x14
		unsigned short level;                           // +0x20
	};

	// Level > 0 node (0x28): +0x24 the tree node of its cell (00659f90 stores the result of 00659670 / 006596d0 there and
	// increments its +0x14; 0065a220 passes it to 00659a10 when the word +0x20 is non-zero).
	struct SpatialLevelNode : public SpatialNode
	{
		SpatialTreeNode* treeNode;                      // +0x24
	};

	// Tree node, 0x2c bytes (006596d0 `push 0x2c`, free list +0x74, chain +0x28 per bucket second head; dtor 0065b1b0
	// loads [node+0x28]): eight child hash ids as words (initialised to 0xffff), level word +0x10, child bit mask +0x12
	// (0065a220 `test bl, [eax+0x12]` then `mov word ptr [eax+ecx*2]`), reference count +0x14 (00659f90 `inc [eax+0x14]`),
	// hash +0x18, grid +0x1c..+0x24 (00659670 compares them), next +0x28. INFERRED: names.
	struct SpatialTreeNode
	{
		unsigned short children[8];                     // +0x00
		unsigned short level;                           // +0x10
		unsigned char childMask;                        // +0x12
		int refCount;                                   // +0x14
		int hashId;                                     // +0x18
		Vector3int32 gridId;                            // +0x1c
		SpatialTreeNode* next;                          // +0x28
	};

	struct SpatialBucket
	{
		SpatialNode* nodes;                             // +0
		SpatialTreeNode* treeNodes;                     // +4
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
		SpatialTreeNode* freeTreeNodes;                 // +0x74
		int nodesOut;                                   // +0x78
		int maxBucket;                                  // +0x7c
		G3D::Array<SpatialNode*> extraNodes;            // +0x80 INFERRED: G3D::Array shape (data +0x80, num +0x84, numAllocated +0x88; its destructor is alignedFree 00507d20 then zeroing, ctor stores num, numAllocated, data)

	public:
		SpatialHash(World* world, ContactManager* contactManager);   // 0065b4e0
		~SpatialHash();                                              // 0065b1b0
		// INFERRED: 0065abd0 passes Primitive::getFastFuzzyExtents (005e7a50) to 0065a950 (spatial node update, reads prim +0x64..+0x7c)
		void onPrimitiveExtentsChanged(Primitive* p, const Extents& e);   // 0065a950
		void onPrimitiveExtentsChanged(Primitive* p);                     // 0065abd0
		// Donor SpatialHash.h names (openrbx): ContactManager::onPrimitiveAdded 0060cc30 / onPrimitiveRemoved 0060cc40 load
		// spatialHash and tail-jump here (`ret 4` thiscall bodies; 0065a4e0 calls getFastFuzzyExtents 005e7a50 and the
		// node insert 0065a220).
		void onPrimitiveAdded(Primitive* p);                              // 0065a4e0
		void onPrimitiveRemoved(Primitive* p);                            // 0065aac0
		// 005e9170 World::getNumHashNodes / 005e9180 World::getMaxBucketSize read [[contactManager]+0x78] / +0x7c through
		// these (donor SpatialHash.h names; the 2008 offsets of nodesOut / maxBucket above).
		int getNodesOut() const
		{
			return nodesOut;
		}
		int getMaxBucket() const
		{
			return maxBucket;
		}
		// Donor SpatialHash::getHash with the 2008 per-level bucket count (0x10000 >> level): inline in 0065a220.
		static int getHash(int level, const Vector3int32& grid)
		{
			return (grid.x * 73856093 ^ grid.y * 19349663 ^ grid.z * 83492791) & (0xffff >> level);
		}
		// INFERRED names; signatures from the `ret 0xc` / `ret 8` and the pushes at the 0065a220 call sites.
		SpatialNode* newNode(int level, int hash, const Vector3int32& grid);              // 00659f90
		SpatialTreeNode* findTreeNode(int level, int hash, const Vector3int32& grid);     // 00659670
		SpatialTreeNode* newTreeNode(int level, int hash, const Vector3int32& grid);      // 006596d0
		void addTreePairs(SpatialTreeNode* tree, Primitive* p);                          // 00659a10
		// 0065a220 (registry func_0065a220; donor SpatialHash::addNode extended to the 2008 grid levels).
		void addNode(int level, Primitive* p, const Vector3int32& grid);

	public:
		static int gridSize;   // INFERRED (header-add): evidence: asm dword ptr [0x9625ac] loaded and shifted left by cl - byte-proved by 00659460
	};
}
