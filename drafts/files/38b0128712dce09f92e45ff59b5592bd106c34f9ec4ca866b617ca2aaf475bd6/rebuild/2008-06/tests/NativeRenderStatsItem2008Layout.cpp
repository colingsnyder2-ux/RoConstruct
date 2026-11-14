// Layout probes for CRobloxWnd::RenderStatsItem (2008-06, inactive); each returns a size or offset as mov eax, imm32.
// The class is nested in CRobloxWnd, so these compile only in the NATIVE_RENDERSTATSITEM_PENDING build (generated
// CRobloxView.h / stats/Stats.h copies, tests/record_native_render_stats_item2008.py); RenderStats offsets compile
// against the donor RenderLib/RenderStats.h in both builds.
#include "RenderStatsItem2008/RenderStatsItem2008.h"
#include <stddef.h>

int nativeRenderStatsSize() { return sizeof(RenderStats); }                       // 0x238 (RenderScene2008.h)
int nativeRenderStatsSwapBuffer() { return offsetof(RenderStats, swapBuffer); }   // 0x58  "SwapBuffer"
int nativeRenderStatsSort() { return offsetof(RenderStats, sort); }               // 0xb0  "Sort"
int nativeRenderStatsCpuTotal() { return offsetof(RenderStats, cpuRenderTotal); } // 0x108 "3D CPU Total"
int nativeRenderStatsCpuShadow() { return offsetof(RenderStats, cpuShadow); }     // 0x160 "CPU Shadow"
int nativeRenderStatsProxyArrays() { return offsetof(RenderStats, computeProxyArrays); } // 0x1b8
int nativeRenderStatsMajor() { return offsetof(RenderStats, majorStateChanges); } // 0x210 (update "%d/%d")
int nativeRenderStatsMinorGL() { return offsetof(RenderStats, minorGLStateChanges); } // 0x21c
int nativeRenderStatsProxyCount() { return offsetof(RenderStats, diffuseProxyCount); } // 0x220 "Proxy count"
int nativeRenderStatsTriangles() { return offsetof(RenderStats, totalTriangles); }      // 0x228 "Total Triangles"
int nativeRenderStatsUnshadowed() { return offsetof(RenderStats, unshadowedTriangles); } // 0x234

#ifdef NATIVE_RENDERSTATSITEM_PENDING
struct NativeRenderStatsItem2008Layout
{
	static int size() { return sizeof(CRobloxWnd::RenderStatsItem); }
	static int aggregation() { return offsetof(CRobloxWnd::RenderStatsItem, aggregation); }
	static int textureMemory() { return offsetof(CRobloxWnd::RenderStatsItem, textureMemory); }
	static int minorChanges() { return offsetof(CRobloxWnd::RenderStatsItem, minorChanges); }
	static int renderStats() { return offsetof(CRobloxWnd::RenderStatsItem, renderStats); }
};

int nativeRenderStatsItemSize() { return NativeRenderStatsItem2008Layout::size(); }                   // 0x178 (0045f730)
int nativeRenderStatsItemAggregation() { return NativeRenderStatsItem2008Layout::aggregation(); }     // 0x158
int nativeRenderStatsItemTexture() { return NativeRenderStatsItem2008Layout::textureMemory(); }       // 0x15c
int nativeRenderStatsItemMinor() { return NativeRenderStatsItem2008Layout::minorChanges(); }          // 0x16c
int nativeRenderStatsItemRenderStats() { return NativeRenderStatsItem2008Layout::renderStats(); }     // 0x170
#endif
