#pragma once
// 2008-06 native CRobloxWnd::RenderStatsItem (inactive). A non-colliding header: CRobloxWnd itself belongs to
// native-headers/CRobloxView.h (maintainer-owned) and is only included, never edited.
//   RTTI       vtable 0081a32c .?AVRenderStatsItem@CRobloxWnd@@ (a class nested in CRobloxWnd) -> Stats::Item
//              (22 bases, mdisp 0; no Service/IRenderable). Its 17 Instance-vtable slots are Item's except slot 16
//              update 0045f570; the nine secondary vtables 0081a31c..0081a2ac hold only Item's ??_E thunks
//              (005ca170, 0045f720, 005c9b90, 005bcd70, 005ca180, 005ca190, 0045ecb0, 005a6610), so the class has
//              no destructor of its own (raw Item* / RenderStats* members, Item's dtor 0045ba10 / ??_G 005ca1a0).
//   size       0x178: Creatable<Instance>::create<RenderStatsItem> 0045f730 allocates 0x178 and calls the ctor;
//              last field +0x170 (4 bytes), rounded up to Item's 8-byte (double val) alignment.
//   ctor       0045f340: Item() 0045ebe0, the ten vtable stores, renderStats = argument (+0x170), then bound child
//              items through Item::createBoundChildItem<G3D::Stopwatch> 0045f120 ("2D CPU Render" +0x0, "3D CPU
//              Total" +0x108 with children "CPU Shadow" +0x160, "computeProxyArrays" +0x1b8, "Sort" +0xb0) and
//              createBoundChildItem<int> 0045f230 ("Proxy count" +0x220, "Total Triangles" +0x228 with children
//              "Ambient + Unshadowed" +0x234, "Mark Shadows" +0x22c, "Shadowed Light" +0x230), "SwapBuffer" +0x58;
//              plain children (Item::createChildItem 005c9c70) stored at +0x158 .. +0x16c; "Aggregation" binds
//              RenderStats::chunkCount / aggregatedChunkCount / aggregateChunkCount (0097288c / 00972890 / 00972894).
//              Those offsets are the donor RenderLib/RenderStats.h members (6 G3D::Stopwatch of 0x58, then ints).
//   argument   the only construction site 0045faf8 (CRobloxWnd, 0045f7b0) passes the result of the view's virtual
//              getRenderStats() (slot 7, [vtbl+0x1c], ViewBase2008.h: RenderStats&) through create<>(Parameter1 p1)
//              by value, and create pushes that value unchanged: a RenderStats pointer.
//   update     0045f570: aggregation ratio from the three chunk counters ("n/a", "%.0f%%, %.2g"), Major/Minor
//              state changes "%d/%d" (+0x214/+0x210, +0x21c/+0x218), Tex/VAR/Video formatMem of
//              G3D::Texture::_sizeOfAllTexturesInMemory 0096ef44, VARArea::_sizeOfAllVARAreasInMemory 0096efd0
//              and DXCaps::videoMemorySize 00476470.
// The class is nested in CRobloxWnd, so it needs `class RenderStatsItem;` inside CRobloxWnd (proposal for the
// CRobloxView.h owner) and Item::createBoundChildItem<T> (proposal for the stats/Stats.h owner). Until both exist,
// the class is compiled only with NATIVE_RENDERSTATSITEM_PENDING against generated copies of those headers
// (tests/record_native_render_stats_item2008.py); without it the unit only instantiates the TypedStatsItem
// <G3D::Stopwatch> / <int> members the ctor binds.
#ifdef NATIVE_RENDERSTATSITEM_PENDING
#include "CRobloxView.h" // first: MFC must precede <windows.h>
#endif
#include "stats/Stats.h"
#include "RenderLib/RenderStats.h"

#ifdef NATIVE_RENDERSTATSITEM_PENDING

struct NativeRenderStatsItem2008Layout;

class CRobloxWnd::RenderStatsItem : public RBX::Stats::Item
{
	friend struct ::NativeRenderStatsItem2008Layout; // tests/NativeRenderStatsItem2008Layout.cpp offset asserts

	Item* aggregation;      // +0x158 "Aggregation"
	Item* textureMemory;    // +0x15c "Memory"/"Tex"
	Item* varMemory;        // +0x160 "Memory"/"VAR"
	Item* videoMemory;      // +0x164 "Memory"/"Video"
	Item* majorChanges;     // +0x168 "State Changes"/"Major"
	Item* minorChanges;     // +0x16c "State Changes"/"Minor"
	RenderStats* renderStats; // +0x170

public:
	RenderStatsItem(RenderStats* renderStats); // 0045f340

protected:
	virtual void update(); // slot 16, 0045f570
};
#endif
