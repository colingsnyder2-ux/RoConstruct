// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Donor RenderLib method; 2008 original 00548150.
#include "ViewNew/RenderBaseMesh.h"
namespace RBX { namespace RenderBase {
void Mesh::computeShadowSurface(const LevelRef& level)
{
	shadowSurface.dropShadowGeometry = level;
	shadowSurface.geometry.clear();

	G3D::Array<G3D::Vector3> rawGeometry;

	for (int i = 0; i < level->indexArray.size(); i++) {
		unsigned int index = level->indexArray[i];
		G3D::Vector3 v = visibleGeometry.vertexArray[index];
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
	G3D::MeshAlg::computeWeld(rawGeometry, shadowSurface.geometry, toNew, toOld);

	for (int i = 0; i < indexArray.size(); i++) {
		indexArray[i] = toNew[indexArray[i]];
	}

	G3D::Array<G3D::MeshAlg::Vertex> vertexArray;
	G3D::MeshAlg::computeAdjacency(
		shadowSurface.geometry, indexArray, shadowSurface.faceArray, shadowSurface.edgeArray, vertexArray
	);

	for (int i = 0; i < shadowSurface.edgeArray.size(); i++) {
		for (int j = 0; j < 2; j++) {
			// INFERRED disabled invariant; original retains the no-op loop.
            debugAssert(shadowSurface.edgeArray[i].faceIndex[j] >= 0);
		}
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

} }

