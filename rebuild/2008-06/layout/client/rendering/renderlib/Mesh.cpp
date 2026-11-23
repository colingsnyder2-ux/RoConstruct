// =============================================================================
// Mesh.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/renderlib/Mesh.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "ViewNew/RenderBaseMesh.h"

namespace RBX { namespace RenderBase {
Mesh::VertexList Mesh::vertexRefCounts;
Mesh::VertexList Mesh::freeList;
G3D::MeshAlg::Geometry Mesh::visibleGeometry;
G3D::Array<G3D::Vector2> Mesh::texCoordArray;
G3D::Array<G3D::Vector3> Mesh::tangentArray;
bool Mesh::varDirty = true; // Original 00942ebc: geometry-upload dirty flag.
// INFERRED name: original 009738a1 marks the G3D vertex arrays dirty.
bool g3dVarDirty;
static int vertexRefCount;
unsigned int Mesh::allocVertex(const G3D::Vector3& vertex, const G3D::Vector3& normal, const G3D::Vector2& tex, bool share)
{
	if (!g3dVarDirty) g3dVarDirty = true;
	varDirty = true;
	unsigned int index;
	if (freeList.length() == 0) {
		index = visibleGeometry.vertexArray.size();
		// INFERRED disabled assertions: original release code retains the no-op loops.
		debugAssert(index == (unsigned)visibleGeometry.normalArray.size());
		visibleGeometry.vertexArray.append(vertex);
		debugAssert(index == (unsigned)visibleGeometry.normalArray.size());
		visibleGeometry.normalArray.append(normal);
		debugAssert(index == (unsigned)texCoordArray.size());
		texCoordArray.append(tex);
		debugAssert(index == (unsigned)tangentArray.size());
		tangentArray.append(G3D::Vector3::zero());
		debugAssert(index == (unsigned)vertexRefCounts.size());
		vertexRefCounts.append(1);
	} else {
		index = freeList.pop();
		visibleGeometry.vertexArray[index] = vertex;
		visibleGeometry.normalArray[index] = normal;
		texCoordArray[index] = tex;
		tangentArray[index] = G3D::Vector3::zero();
		debugAssert(index < (unsigned)vertexRefCounts.size());
		vertexRefCounts[index] = 1;
	}
	vertexRefCount++;
	return index;
}
void Mesh::initStatics()
{
	visibleGeometry.vertexArray.resize(1);
	visibleGeometry.normalArray.resize(1);
	texCoordArray.resize(1);
	tangentArray.resize(1);
	vertexRefCounts.resize(1);
	vertexRefCounts[0] = 1;
	freeList.clear();
}
unsigned int Mesh::allocVertex(unsigned int index, unsigned int count)
{
	// INFERRED disabled debug check; original release code retains a no-op loop.
	debugAssert(index < (unsigned)vertexRefCounts.size());
	vertexRefCounts[index] += count;
	vertexRefCount += count;
	return index;
}

void Mesh::freeVertex(unsigned int index)
{
	if (!vertexRefCounts.getCArray()) return;
	if (!vertexRefCounts.size()) return;
	// INFERRED disabled debug checks; original release code retains both no-op loops.
	debugAssert(index < (unsigned)vertexRefCounts.size());
	vertexRefCount--;
	int refCount = vertexRefCounts[index];
	debugAssert(refCount > 0);
	if (refCount == 1) {
		vertexRefCounts[index] = 0;
		freeList.push(index);
	} else {
		vertexRefCounts[index] = refCount - 1;
	}
}
} }
