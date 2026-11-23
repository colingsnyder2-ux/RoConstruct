// =============================================================================
// RenderStats.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/renderlib/include/renderlib/RenderStats.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <G3D/Stopwatch.h>

class RenderStats
{
public:
	G3D::Stopwatch render2D;
	G3D::Stopwatch swapBuffer;
	G3D::Stopwatch sort;
	G3D::Stopwatch cpuRenderTotal;
	mutable G3D::Stopwatch cpuShadow;
	G3D::Stopwatch computeProxyArrays;
	int majorStateChanges;
	int majorGLStateChanges;
	int minorStateChanges;
	int minorGLStateChanges;
	int diffuseProxyCount;
	int pushPopCount;
	int totalTriangles;
	int markShadowsTriangles;
	int shadowedLightTriangles;
	int unshadowedTriangles;

public:
	static int chunkCount;
	static int aggregatedChunkCount;
	static int aggregateChunkCount;

public:
	RenderStats();
};
