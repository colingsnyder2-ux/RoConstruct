// Layout probes for the inactive native RBX::ViewNew meshes / builders and RenderBase::Mesh (2008-06).
// Each probe compiles to `mov eax, imm32; ret`; tests/record_native_viewnew.py compares the immediates with the
// sizes and offsets read from the original (allocation sizes, constructor stores, field accesses).
#include "ViewNew/BevelMesh.h"
#include "ViewNew/SphereMesh.h"
#include "ViewNew/CylinderMesh.h"
#include "ViewNew/HeadMesh.h"
#include <stddef.h>

using namespace RBX;
using namespace RBX::ViewNew;

struct NativeViewNewLayout
{
	static int meshSize() { return sizeof(RenderBase::Mesh); }
	static int meshLevels() { return offsetof(RenderBase::Mesh, levels); }
	static int meshShadowSurface() { return offsetof(RenderBase::Mesh, shadowSurface); }
	static int meshDebugBoundingRadius() { return offsetof(RenderBase::Mesh, debugBoundingRadius); }
	static int meshShadowIndices() { return offsetof(RenderBase::Mesh, shadowIndices); }
	static int meshShadowVertices() { return offsetof(RenderBase::Mesh, shadowVertices); }
	static int meshSubMesh() { return offsetof(RenderBase::Mesh, subMesh); }
	static int meshKind() { return offsetof(RenderBase::Mesh, meshKind); }
	static int shadowSurfaceSize() { return sizeof(RenderBase::Mesh::ShadowSurface); }
	static int levelSize() { return sizeof(RenderBase::Mesh::Level); }
	static int levelIndexArray() { return offsetof(RenderBase::Mesh::Level, indexArray); }
	static int levelPrimitive() { return offsetof(RenderBase::Mesh::Level, primitive); }
	static int levelDirty() { return offsetof(RenderBase::Mesh::Level, dirty); }
	static int levelVertexStart() { return offsetof(RenderBase::Mesh::Level, vertexStart); }
	static int levelSubMesh() { return offsetof(RenderBase::Mesh::Level, subMesh); }
	static int levelBuilderSize() { return sizeof(LevelBuilder); }
	static int levelBuilderHalfSize() { return offsetof(LevelBuilder, halfSize); }
	static int levelBuilderSurfaceTypes() { return offsetof(LevelBuilder, surfaceTypes); }
	static int levelBuilderLevel() { return offsetof(LevelBuilder, level); }
	static int levelBuilderTextureScale() { return offsetof(LevelBuilder, textureScale); }
	static int bevelBuilderSize() { return sizeof(BevelMesh::Builder); }
	static int bevelBuilderBevel() { return offsetof(BevelMesh::Builder, bevel); }
	static int sphereBuilderSize() { return sizeof(SphereBuilder); }
	static int sphereBuilderElements() { return offsetof(SphereBuilder, elements); }
	static int cylinderBuilderSize() { return sizeof(CylinderBuilder); }
	static int cylinderBuilderElements() { return offsetof(CylinderBuilder, elements); }
	static int headBuilderSize() { return sizeof(HeadBuilder); }
	static int headBuilderBevel() { return offsetof(HeadBuilder, bevel); }
	static int headBuilderElements() { return offsetof(HeadBuilder, elements); }
	static int sphereMeshSize() { return sizeof(SphereMesh); }
	static int cylinderMeshSize() { return sizeof(CylinderAlongXMesh); }
	static int headMeshSize() { return sizeof(HeadMesh); }
	static int bevelMeshSize() { return sizeof(BevelMesh); }
};

#define PROBE(name) int native##name() { return NativeViewNewLayout::name(); }
PROBE(meshSize) PROBE(meshLevels) PROBE(meshShadowSurface) PROBE(meshDebugBoundingRadius) PROBE(meshShadowIndices)
PROBE(meshShadowVertices) PROBE(meshSubMesh) PROBE(meshKind) PROBE(shadowSurfaceSize)
PROBE(levelSize) PROBE(levelIndexArray) PROBE(levelPrimitive) PROBE(levelDirty) PROBE(levelVertexStart) PROBE(levelSubMesh)
PROBE(levelBuilderSize) PROBE(levelBuilderHalfSize) PROBE(levelBuilderSurfaceTypes) PROBE(levelBuilderLevel)
PROBE(levelBuilderTextureScale) PROBE(bevelBuilderSize) PROBE(bevelBuilderBevel) PROBE(sphereBuilderSize)
PROBE(sphereBuilderElements) PROBE(cylinderBuilderSize) PROBE(cylinderBuilderElements) PROBE(headBuilderSize)
PROBE(headBuilderBevel) PROBE(headBuilderElements) PROBE(sphereMeshSize) PROBE(cylinderMeshSize) PROBE(headMeshSize)
PROBE(bevelMeshSize)
