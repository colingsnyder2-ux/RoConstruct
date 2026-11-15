// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Donor shadow-volume method; 2008 original 00549050.
#include "ViewNew/RenderBaseMesh.h"
namespace RBX { namespace RenderBase {
void Mesh::computeDirectionalShadowVolume(
	const G3D::CoordinateFrame& cframe,
	const G3D::Vector3& wsLightVector,
	G3D::Array<unsigned int>& indexArray,
	G3D::Array<G3D::Vector3>& shadowVertex,
	bool generateLightCap
) const
{
	G3D::Vector3 objectLight = cframe.vectorToObjectSpace(wsLightVector);

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
				const G3D::Vector3& v0 = shadowSurface.geometry[face.vertexIndex[0]];
				const G3D::Vector3& v1 = shadowSurface.geometry[face.vertexIndex[1]];
				const G3D::Vector3& v2 = shadowSurface.geometry[face.vertexIndex[2]];

				shadowVertex.append(
					cframe.pointToWorldSpace(v0), cframe.pointToWorldSpace(v1), cframe.pointToWorldSpace(v2)
				);
			}
		}
	}

	for (int e = 0; e < shadowSurface.edgeArray.size(); e++) {
		const G3D::MeshAlg::Edge& edge = shadowSurface.edgeArray[e];
		debugAssert(edge.faceIndex[0] >= 0); // inferred disabled invariant
		debugAssert(edge.faceIndex[1] >= 0); // inferred disabled invariant
		bool b0 = backface[edge.faceIndex[0]];
		bool b1 = backface[edge.faceIndex[1]];

		if (b0 != b1) {
			const G3D::Vector3& first = shadowSurface.geometry[edge.vertexIndex[0]];
			const G3D::Vector3& v0 = shadowSurface.geometry[edge.vertexIndex[1]]; // second edge vertex

			G3D::Vector3 wvertex0 = cframe.pointToWorldSpace(first), wvertex1 = cframe.pointToWorldSpace(v0);

			int v1 = shadowVertex.size(); // first new vertex index
			shadowVertex.append(wvertex0, wvertex1);

			unsigned int A;
			unsigned int B;

			if (b0) {
				A = v1;
				B = v1 + 1;
			}
			else {
				A = v1 + 1;
				B = v1;
			}

			indexArray.append(A, B, 0);
		}
	}
}

} }

