// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::SpatialHash 0065abd0 (inactive); forwards the primitive's fast fuzzy extents to 0065a950.
#include "v8world/SpatialHash2008.h"
#include "v8world/Primitive2008.h"
#include "v8world/Contact2008.h"
#include "v8world/ContactManager2008.h"

namespace RBX
{
	// 0065abd0
	void SpatialHash::onPrimitiveExtentsChanged(Primitive* p)
	{
		onPrimitiveExtentsChanged(p, p->getFastFuzzyExtents());
	}

#ifdef SPATIALHASH_HEADER_DECLARES_GRID_QUERIES
	// GUARDED: v8world/SpatialHash2008.h (not owned here) does not declare these three members. Header proposal, after
	// shareCommonGrid:
	//   void getPrimitivesInGrid(int level, const Vector3int32& grid, G3D::Array<Primitive*>& found);   // 0065a6f0
	//   void getPrimitivesInGrid(const Vector3int32& grid, G3D::Array<Primitive*>& found);              // 0065a7d0
	//   void onPrimitivesExtentsChanged(const G3D::Array<Primitive*>& primitives);                     // 0065abf0

	// 0065a6f0 (registry placeholder func_0065a6f0; thiscall `ret 0xc`; callers 0065a809 and the extents query 0065ad64).
	// Donor SpatialHash::getPrimitivesInGrid with the 2008 grid level: getHash(level, grid) (0xffff >> level mask), the
	// level's bucket vector at +0xc + level * 0x18 (checked operator[], _invalid_parameter_noinfo), then the hash chain
	// (+4) collecting node->primitive for nodes whose gridId (+0x14) equals grid (inline G3D::Array::append, out-of-line
	// resize 00599a70 / aliasing append 0059a190).
	void SpatialHash::getPrimitivesInGrid(int level, const Vector3int32& grid, G3D::Array<Primitive*>& found)
	{
		int hash = getHash(level, grid);
		SpatialNode* node = levels[level][hash].nodes;
		while (node)
		{
			if (node->gridId == grid)
				found.append(node->primitive);
			node = node->nextHashLink;
		}
	}

	// 0065a7d0 (registry placeholder func_0065a7d0; `ret 8`; caller ContactManager 0060d397): the grid copied to a
	// local, one 0065a6f0 call per grid level (levelCount 009625a8), each grid component shifted right by one per level.
	// INFERRED: overload name from the donor getPrimitivesInGrid(grid, found) signature.
	void SpatialHash::getPrimitivesInGrid(const Vector3int32& grid, G3D::Array<Primitive*>& found)
	{
		Vector3int32 levelGrid = grid;
		for (int level = 0; level < spatialHashLevels; ++level)
		{
			getPrimitivesInGrid(level, levelGrid, found);
			levelGrid.x >>= 1;
			levelGrid.y >>= 1;
			levelGrid.z >>= 1;
		}
	}

	// 0065abf0 (registry placeholder func_0065abf0; `ret 4`; only caller ContactManager 0060cc62, `mov ecx, [ecx]` then a
	// tail jump, beside the 0060cc50 -> 0065abd0 forwarder): for each primitive of the array, 0065a950 with the
	// primitive's cached fuzzyExtents (+0x80, read directly; SpatialHash is a friend of Primitive).
	// INFERRED: the name (no symbol evidence).
	void SpatialHash::onPrimitivesExtentsChanged(const G3D::Array<Primitive*>& primitives)
	{
		for (int i = 0; i < primitives.size(); ++i)
		{
			Primitive* p = primitives[i];
			onPrimitiveExtentsChanged(p, p->fuzzyExtents);
		}
	}
#endif

#ifdef SPATIALHASH_HEADER_DECLARES_RELEASE_UNSHARED
	// 0065a870 (registry placeholder func_0065a870; thiscall `ret 4`; callers 0065a950 at 0065aa79 / 0065aaa1). GUARDED:
	// needs `void releaseUnsharedContacts(Primitive* p);` in v8world/SpatialHash2008.h, its +0x80 G3D::Array typed
	// G3D::Array<Primitive*> (this body appends contact partners to it and passes them to the pair release), and
	// `void onReleasePair(Primitive* p0, Primitive* p1);` (0060cc00) in v8world/ContactManager2008.h.
	// Body: the +0x80 array cleared (resize(0) 00599a70), each contact of p (getFirstContact 005e7bd0 / getNextContact
	// 005e7be0) whose other primitive (+0xc / +0x10) no longer shares a grid cell with p (shareCommonGrid 006593d0) is
	// collected, then contactManager (+8)->onReleasePair(p, other) 0060cc00 for each. INFERRED: the name.
	void SpatialHash::releaseUnsharedContacts(Primitive* p)
	{
		extraNodes.clear();
		Contact* contact = p->getFirstContact();
		while (contact)
		{
			Primitive* other = contact->otherPrimitive(p);
			contact = p->getNextContact(contact);
			if (!shareCommonGrid(p, other))
				extraNodes.append(other);
		}
		for (int i = 0; i < extraNodes.size(); ++i)
			contactManager->onReleasePair(p, extraNodes[i]);
	}
#endif

#ifdef SPATIALHASH_HEADER_DECLARES_DESTROY_NODE
	// 0065a080 (registry placeholder func_0065a080; thiscall `ret 4`; callers 0065a6ad and onPrimitiveRemoved 0065aad6).
	// Donor SpatialHash::destroyNode in its 2008 grid-level form: unlink from the primitive's node list (+8 / +0xc,
	// head Primitive +0x64), removeNodeFromHash 00659830, then look for another node in the same cell at this level and
	// above (grid shifted right per level, getHash(level, grid)); a level-0 hit only counts, a hit above level 0 stops
	// the search. A level > 0 node drops its tree node's reference (+0x14) and, when the tree node is unreferenced and
	// childless (+0x12), destroys it (006597d0) and clears it from its parents (00659920); an unshared level-0 cell is
	// cleared from its parents too. The node goes back on the level-0 (+0x6c) or level > 0 (+0x70) free list and
	// nodesOut (+0x78) drops. GUARDED: needs the header declarations of destroyNode and the three helpers
	// (removeNodeFromHash 00659830, destroyTreeNode 006597d0, removeTreeChild 00659920). INFERRED: helper names.
	void SpatialHash::destroyNode(SpatialNode* destroy)
	{
		SpatialNode* nextPrimitiveLink = destroy->nextPrimitiveLink;
		SpatialNode* prevPrimitiveLink = destroy->prevPrimitiveLink;
		if (nextPrimitiveLink)
			nextPrimitiveLink->prevPrimitiveLink = prevPrimitiveLink;
		if (prevPrimitiveLink)
			prevPrimitiveLink->nextPrimitiveLink = nextPrimitiveLink;
		else
			destroy->primitive->spatialNodes = nextPrimitiveLink;

		removeNodeFromHash(destroy);

		int hash = destroy->hashId;
		Vector3int32 grid = destroy->gridId;
		int startLevel = destroy->level;
		int sharedCount = 0;
		bool sharedAbove = false;
		for (int level = startLevel; level < spatialHashLevels && !sharedAbove; ++level)
		{
			if (level > startLevel)
			{
				grid.x >>= 1;
				grid.y >>= 1;
				grid.z >>= 1;
				hash = getHash(level, grid);
			}
			for (SpatialNode* node = levels[level][hash].nodes; node; node = node->nextHashLink)
			{
				if (node->gridId == grid)
				{
					if (level != 0)
					{
						sharedAbove = true;
						break;
					}
					++sharedCount;
				}
			}
		}

		if (destroy->level > 0)
		{
			SpatialTreeNode* tree = static_cast<SpatialLevelNode*>(destroy)->treeNode;
			if (--tree->refCount == 0 && tree->childMask == 0)
			{
				destroyTreeNode(tree);
				removeTreeChild(tree->level, tree->gridId);
			}
		}
		else if (sharedCount == 0)
		{
			removeTreeChild(0, destroy->gridId);
		}

		if (destroy->level == 0)
		{
			destroy->nextHashLink = freeNodes;
			--nodesOut;
			freeNodes = destroy;
		}
		else
		{
			destroy->nextHashLink = freeNodes2;
			--nodesOut;
			freeNodes2 = destroy;
		}
	}
#endif
}
