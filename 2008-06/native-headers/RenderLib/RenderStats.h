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
// 2008-06 native header port of rbxgs Rendering/RenderLib/include/RenderLib/RenderStats.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
