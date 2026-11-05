// from server: 46% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client Rendering/RenderLib/Mesh.cpp

// Candidate translation unit (score above; library headers required).
#include "renderlib/Mesh.h"

#include "renderlib/Chunk.h"

namespace RBX {
namespace Render {

G3D::MeshAlg::Geometry Mesh::visibleGeometry;
G3D::Array<G3D::Vector2> Mesh::texCoordArray;
G3D::Array<G3D::Vector3> Mesh::tangentArray;
Mesh::VertexList Mesh::vertexRefCounts;
Mesh::VertexList Mesh::freeList;
G3D::VAR Mesh::vertexVAR;
G3D::VAR Mesh::normalVAR;
G3D::VAR Mesh::texCoordVAR;
G3D::VAR Mesh::tangentVAR;
bool Mesh::varDirty;

static int vertexRefCount;
static bool init;

// FUNCTION: WEBSERVICE 0x101655f0
void Mesh::endRender(G3D::RenderDevice* rd)
{
	rd->endIndexedPrimitives();
}

// FUNCTION: WEBSERVICE 0x10165830
unsigned int Mesh::allocVertex(unsigned int i, unsigned int count)
{
	vertexRefCounts[i] += count;
	vertexRefCount += count;

	return i;
}

// FUNCTION: WEBSERVICE 0x10165fc0
const Mesh::LevelRef Mesh::detailLevel(float meshLOD) const
{
	return levels[detailIndex(levels.size() * meshLOD)].getPointer();
}

// FUNCTION: WEBSERVICE 0x10166020
void Mesh::sendGeometry(const Level* lvl, G3D::RenderDevice* rd)
{
	if (lvl != NULL && lvl->indexArray.size() > 0) {
		rd->sendIndices(lvl->primitive, lvl->indexArray);
	}
}

// FUNCTION: WEBSERVICE 0x10166cc0
unsigned int Mesh::allocVertex(
	const G3D::Vector3& vertex,
	const G3D::Vector3& normal,
	const G3D::Vector2& tex,
	bool share
)
{
	if (!varDirty) {
		varDirty = true;
	}

	if (freeList.size() == 0) {
		int index = visibleGeometry.vertexArray.size();

		visibleGeometry.vertexArray.append(vertex);
		visibleGeometry.normalArray.append(normal);
		texCoordArray.append(tex);
		tangentArray.append(G3D::Vector3::zero());
		vertexRefCounts.append(1);
		vertexRefCount++;

		return index;
	}

	unsigned int index = freeList.last();
	freeList.resize(freeList.size() - 1, false);

	visibleGeometry.vertexArray[index] = vertex;
	visibleGeometry.normalArray[index] = normal;
	texCoordArray[index] = tex;
	tangentArray[index] = G3D::Vector3::zero();
	vertexRefCounts[index] = 1;
	vertexRefCount++;

	return index;
}

// STUB: WEBSERVICE 0x10166e40
void Mesh::freeVertex(unsigned int i)
{
	int* refCounts = vertexRefCounts.getCArray();

	if (refCounts != NULL) {
		vertexRefCount--;

		if (refCounts[i] == 1) {
			refCounts[i] = 0;
			freeList.append(i);
			return;
		}

		refCounts[i]--;
	}
}

// FUNCTION: WEBSERVICE 0x10166e80
Mesh::Level::~Level()
{
	for (int i = 0; i < indexArray.size(); i++) {
		freeVertex(indexArray[i]);
	}
}

// FUNCTION: WEBSERVICE 0x10166f50
Mesh::~Mesh()
{
}

// FUNCTION: WEBSERVICE 0x10166fc0
void Mesh::makeVAR()
{
	if (varDirty) {
		G3D::VARAreaRef area =
			G3D::VARArea::create(visibleGeometry.vertexArray.size() * 44 + 1024, G3D::VARArea::WRITE_ONCE);

		vertexVAR = G3D::VAR(visibleGeometry.vertexArray, area);
		normalVAR = G3D::VAR(visibleGeometry.normalArray, area);
		texCoordVAR = G3D::VAR(texCoordArray, area);
		tangentVAR = G3D::VAR(tangentArray, area);

		varDirty = false;
	}
}

// FUNCTION: WEBSERVICE 0x10167400
void Mesh::beginRender(G3D::RenderDevice* rd, bool usetexCoords, bool useTangent)
{
	makeVAR();
	rd->beginIndexedPrimitives();

	if (vertexVAR.valid()) {
		rd->setVertexArray(vertexVAR);
	}

	if (normalVAR.valid()) {
		rd->setNormalArray(normalVAR);
	}

	if (usetexCoords) {
		if (texCoordVAR.valid()) {
			rd->setTexCoordArray(0, texCoordVAR);
		}
	}

	if (useTangent) {
		if (tangentVAR.valid()) {
			rd->setTexCoordArray(2, tangentVAR);
		}
	}
}

// FUNCTION: WEBSERVICE 0x10167600
void Mesh::initStatics()
{
	visibleGeometry.vertexArray.resize(1);
	visibleGeometry.normalArray.resize(1);
	texCoordArray.resize(1);
	tangentArray.resize(1);
	vertexRefCounts.resize(1);
	vertexRefCounts[0] = 1;
	freeList.resize(0);
}

// STUB: WEBSERVICE 0x101676c0
void Mesh::computeDirectionalShadowVolume(
	const G3D::CoordinateFrame& cframe,
	const G3D::Vector3& wsLightVector,
	G3D::Array<unsigned int>& indexArray,
	G3D::Array<G3D::Vector3>& shadowVertex,
	bool generateLightCap
) const
{
	G3D::Vector3 objectLight = cframe.rotation.transpose() * wsLightVector;
	const G3D::Array<G3D::Vector3>& geometry = shadowSurface.geometry;

	static G3D::Array<bool> backface;
	backface.resize(shadowSurface.faceNormalArray.size(), false);

	for (int f = 0; f < shadowSurface.faceNormalArray.size(); f++) {
		backface[f] = shadowSurface.faceNormalArray[f].dot(objectLight) < 0;
	}

	if (generateLightCap) {
		for (int f = 0; f < backface.size(); f++) {
			if (!backface[f]) {
				int n = shadowVertex.size();
				indexArray.append(n, n + 1, n + 2);

				const G3D::MeshAlg::Face& face = shadowSurface.faceArray[f];
				const G3D::Vector3& v0 = geometry[face.vertexIndex[0]];
				const G3D::Vector3& v1 = geometry[face.vertexIndex[1]];
				const G3D::Vector3& v2 = geometry[face.vertexIndex[2]];

				shadowVertex
					.append(cframe.pointToWorldSpace(v0), cframe.pointToWorldSpace(v1), cframe.pointToWorldSpace(v2));
			}
		}
	}

	for (int e = 0; e < shadowSurface.edgeArray.size(); e++) {
		const G3D::MeshAlg::Edge& edge = shadowSurface.edgeArray[e];
		bool b0 = backface[edge.faceIndex[0]];

		if (b0 != backface[edge.faceIndex[1]]) {
			int n = shadowVertex.size();
			const G3D::Vector3& v0 = geometry[edge.vertexIndex[0]];
			const G3D::Vector3& v1 = geometry[edge.vertexIndex[1]];

			G3D::Vector3 p0 = cframe.pointToWorldSpace(v0);
			G3D::Vector3 p1 = cframe.pointToWorldSpace(v1);

			shadowVertex.append(p0, p1);

			if (b0) {
				indexArray.append(n, n + 1, 0);
			}
			else {
				indexArray.append(n + 1, n, 0);
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x10167b50
Mesh::Level::Level(G3D::RenderDevice::Primitive primitive) : primitive(primitive)
{
}

// FUNCTION: WEBSERVICE 0x10167bb0
Mesh::Mesh()
{
	if (!init) {
		initStatics();
		init = true;
	}

	debugBoundingRadius = 0.0f;
}

// STUB: WEBSERVICE 0x10167d70
G3D::ReferenceCountedPointer<Mesh> Mesh::aggregate(
	const std::vector<G3D::ReferenceCountedPointer<Chunk> >& chunkArray,
	G3D::CoordinateFrame& outCFrame,
	float& outBoundingRadius
)
{
	STUB(0x10167d70);
	return NULL;
}

// FUNCTION: WEBSERVICE 0x101689d0
void Mesh::computeShadowSurface(const LevelRef& level)
{
	shadowSurface.dropShadowGeometry = level;
	shadowSurface.geometry.resize(0, false);

	G3D::Array<G3D::Vector3> rawGeometry;

	for (int i = 0; i < level->indexArray.size(); i++) {
		G3D::Vector3 v = visibleGeometry.vertexArray[level->indexArray[i]];
		rawGeometry.append(v);
	}

	G3D::Array<int> indexArray;

	if (level->primitive == G3D::RenderDevice::TRIANGLES) {
		G3D::MeshAlg::createIndexArray(level->indexArray.size(), indexArray);
	}
	else {
		G3D::Array<int> tmp;
		G3D::MeshAlg::createIndexArray(level->indexArray.size(), tmp);
		G3D::MeshAlg::toIndexedTriList(tmp, (G3D::MeshAlg::Primitive) level->primitive, indexArray);
	}

	G3D::Array<G3D::Vector3> newVertexPositions;
	G3D::Array<int> toNew;
	G3D::Array<int> toOld;
	G3D::MeshAlg::computeWeld(rawGeometry, shadowSurface.geometry, toNew, toOld, 1e-05);

	for (int i = 0; i < indexArray.size(); i++) {
		indexArray[i] = toNew[indexArray[i]];
	}

	G3D::Array<G3D::MeshAlg::Vertex> vertexArray;
	G3D::MeshAlg::computeAdjacency(
		shadowSurface.geometry,
		indexArray,
		shadowSurface.faceArray,
		shadowSurface.edgeArray,
		vertexArray
	);

	for (int i = 0; i < shadowSurface.edgeArray.size(); i++) {
	}

	shadowSurface.faceNormalArray.resize(shadowSurface.faceArray.size());

	for (int f = 0; f < shadowSurface.faceNormalArray.size(); f++) {
		G3D::Vector3 vertex[3];

		for (int i = 0; i < 3; i++) {
			vertex[i] = shadowSurface.geometry[shadowSurface.faceArray[f].vertexIndex[i]];
		}

		shadowSurface.faceNormalArray[f] = (vertex[1] - vertex[0]).cross(vertex[2] - vertex[0]).direction();
	}
}

} // namespace Render
} // namespace RBX
