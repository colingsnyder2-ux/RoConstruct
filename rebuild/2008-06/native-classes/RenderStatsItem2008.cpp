// 2008-06 native CRobloxWnd::RenderStatsItem unit (inactive): the render statistics item that CRobloxWnd
// (0045f7b0) parents under the Stats service, and the Stats::TypedStatsItem<G3D::Stopwatch> / <int> template
// instances its constructor binds (original COMDATs 0045c250..0045f730 in the CRobloxWnd unit). Evidence in
// native-headers/RenderStatsItem2008/RenderStatsItem2008.h. Verified by tests/record_native_render_stats_item2008.py.
#include "RenderStatsItem2008/RenderStatsItem2008.h"
#include <GLG3D/Texture.h>
#include <GLG3D/VARArea.h>
#include <GLG3D/DXCaps.h>

#ifndef NATIVE_RENDERSTATSITEM_PENDING
// Without the proposed Item::createBoundChildItem<T> the bound-item instances are requested explicitly; in the
// pending build they are implicit instances of createBoundChildItem<G3D::Stopwatch> / <int>.
namespace RBX
{
	namespace Stats
	{
		template class TypedStatsItem<G3D::Stopwatch>; // vtable 0081a08c, ctor 0045ecc0, update 0045ee30
		template class TypedStatsItem<int>;            // vtable 0081a154, ctor 0045eef0, update 0045eff0
	}
	template boost::shared_ptr<Stats::TypedStatsItem<G3D::Stopwatch> >
		Creatable<Instance>::create<Stats::TypedStatsItem<G3D::Stopwatch>, const G3D::Stopwatch*>(const G3D::Stopwatch*); // 0045f020
	template boost::shared_ptr<Stats::TypedStatsItem<int> >
		Creatable<Instance>::create<Stats::TypedStatsItem<int>, const int*>(const int*);                                     // 0045f0a0
}
#else

CRobloxWnd::RenderStatsItem::RenderStatsItem(RenderStats* renderStats)
	: renderStats(renderStats)
{
	createBoundChildItem("2D CPU Render", renderStats->render2D);
	Item* cpu = createBoundChildItem("3D CPU Total", renderStats->cpuRenderTotal);
	cpu->createBoundChildItem("CPU Shadow", renderStats->cpuShadow);
	cpu->createBoundChildItem("computeProxyArrays", renderStats->computeProxyArrays);
	cpu->createBoundChildItem("Sort", renderStats->sort);
	cpu->createBoundChildItem("Proxy count", renderStats->diffuseProxyCount);
	Item* triangles = cpu->createBoundChildItem("Total Triangles", renderStats->totalTriangles);
	triangles->createBoundChildItem("Ambient + Unshadowed", renderStats->unshadowedTriangles);
	triangles->createBoundChildItem("Mark Shadows", renderStats->markShadowsTriangles);
	triangles->createBoundChildItem("Shadowed Light", renderStats->shadowedLightTriangles);
	createBoundChildItem("SwapBuffer", renderStats->swapBuffer);

	aggregation = createChildItem("Aggregation");
	aggregation->createBoundChildItem("Total Chunks", RenderStats::chunkCount);
	aggregation->createBoundChildItem("Aggregated Chunks", RenderStats::aggregatedChunkCount);
	aggregation->createBoundChildItem("AggregateChunks", RenderStats::aggregateChunkCount);

	Item* memory = createChildItem("Memory");
	textureMemory = memory->createChildItem("Tex");
	varMemory = memory->createChildItem("VAR");
	videoMemory = memory->createChildItem("Video");

	Item* changes = createChildItem("State Changes");
	majorChanges = changes->createChildItem("Major");
	minorChanges = changes->createChildItem("Minor");
}

void CRobloxWnd::RenderStatsItem::update()
{
	int chunks = RenderStats::chunkCount;
	if (chunks == 0)
	{
		aggregation->setValue(0, "n/a");
	}
	else if (RenderStats::aggregateChunkCount == 0)
	{
		aggregation->formatValue(0, "%.0f%%, %.2g", 0.0, 1.0);
	}
	else
	{
		float before = chunks;
		float after = RenderStats::aggregateChunkCount - RenderStats::aggregatedChunkCount + chunks;
		float ratio = (before - after) / (before - 1.0f);
		aggregation->formatValue(ratio, "%.0f%%, %.2g", 100.0f * ratio, before / after);
	}

	majorChanges->formatValue(renderStats->majorGLStateChanges, "%d/%d", renderStats->majorGLStateChanges, renderStats->majorStateChanges);
	minorChanges->formatValue(renderStats->minorGLStateChanges, "%d/%d", renderStats->minorGLStateChanges, renderStats->minorStateChanges);

	textureMemory->formatMem(G3D::Texture::sizeOfAllTexturesInMemory());
	varMemory->formatMem(G3D::VARArea::sizeOfAllVARAreasInMemory());
	videoMemory->formatMem(G3D::DXCaps::videoMemorySize());
}

// Creatable<Instance>::create<RenderStatsItem> 0045f730: in the original an implicit instance of the call in
// CRobloxWnd 0045faf8 (maintainer-owned unit), requested explicitly here.
template boost::shared_ptr<CRobloxWnd::RenderStatsItem>
	RBX::Creatable<RBX::Instance>::create<CRobloxWnd::RenderStatsItem, RenderStats*>(RenderStats*);

#endif
