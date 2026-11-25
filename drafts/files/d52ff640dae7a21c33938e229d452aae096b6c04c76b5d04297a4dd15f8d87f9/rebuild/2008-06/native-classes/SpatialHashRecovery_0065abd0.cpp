// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::SpatialHash 0065abd0 (inactive); forwards the primitive's fast fuzzy extents to 0065a950.
#include "v8world/SpatialHash2008.h"
#include "v8world/Primitive2008.h"

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
}
