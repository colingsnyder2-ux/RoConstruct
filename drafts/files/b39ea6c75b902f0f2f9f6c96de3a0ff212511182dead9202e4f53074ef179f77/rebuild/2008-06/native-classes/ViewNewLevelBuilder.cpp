// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/partsurface-profile
#include "ViewNew/QuadVolume.h"
namespace RBX { namespace ViewNew {
// Native declarations and vtable identity: WindowsClient/include/ViewNew/QuadVolume.h.
// 00500d80
LevelBuilder::LevelBuilder(G3D::ReferenceCountedPointer<RenderBase::Mesh::Level>& value, G3D::Vector3 size, RenderSurfaceTypes types)
 : halfSize(size * 0.5f), surfaceTypes(types), level(value), textureScale(2,2) {}
// 00500d30
void LevelBuilder::build(Purpose purpose) {
 buildTop(purpose); buildBottom(purpose); buildLeft(purpose);
 buildRight(purpose); buildFront(purpose); buildBack(purpose);
}
// 00500fd0
void LevelBuilder::appendQuadFromIndexArray(int a,int b,int c) {
 appendQuadFromVertexIndices(level->indexArray[a],level->indexArray[b],level->indexArray[c]);
}
// 00501000
void LevelBuilder::appendQuadFromIndexArray(int a,int b,int c,int d) {
 appendQuadFromVertexIndices(level->indexArray[a],level->indexArray[b],level->indexArray[c],level->indexArray[d]);
}

// Donor QuadVolume.cpp; dispatch and allocation order verified against 00500ca0/00500de0/00500eb0.
float LevelBuilder::offset(RenderSurfaceType surfaceType)
		{
			switch (surfaceType)
			{
			case STUDS:
				return 0.0f;
			case INLET:
				return 0.5f;
			case WELD:
				return 1.0f;
			case GLUE:
				return 1.5f;

			default:
				return 0.0f;
			}
		}
void LevelBuilder::buildFace(NormalId normalId, Purpose purpose)
		{
			switch (normalId)
			{
			case NORM_X:
				buildRight(purpose);
				break;
			case NORM_Y:
				buildTop(purpose);
				break;
			case NORM_Z:
				buildBack(purpose);
				break;
			case NORM_X_NEG:
				buildLeft(purpose);
				break;
			case NORM_Y_NEG:
				buildBottom(purpose);
				break;
			case NORM_Z_NEG:
				buildFront(purpose);
				break;
			}
		}
void LevelBuilder::appendQuadFromVertexIndices(unsigned a, unsigned b, unsigned c)
		{
			switch (level->primitive)
			{
			case G3D::RenderDevice::TRIANGLES:
				level->indexArray.append(
					RenderBase::Mesh::allocVertex(a, 1),
					RenderBase::Mesh::allocVertex(b, 1),
					RenderBase::Mesh::allocVertex(c, 1)
				);
				break;
			case G3D::RenderDevice::QUADS:
				level->indexArray.append(
					RenderBase::Mesh::allocVertex(a, 1),
					RenderBase::Mesh::allocVertex(a, 1),
					RenderBase::Mesh::allocVertex(b, 1),
					RenderBase::Mesh::allocVertex(c, 1)
				);
				break;
			}
		}
void LevelBuilder::appendQuadFromVertexIndices(unsigned a, unsigned b, unsigned c, unsigned d)
		{
			switch (level->primitive)
			{
			case G3D::RenderDevice::TRIANGLES:
				level->indexArray.append(
					RenderBase::Mesh::allocVertex(a, 1),
					RenderBase::Mesh::allocVertex(b, 1),
					RenderBase::Mesh::allocVertex(c, 1)
				);
				level->indexArray.append(
					RenderBase::Mesh::allocVertex(c, 1),
					RenderBase::Mesh::allocVertex(d, 1),
					RenderBase::Mesh::allocVertex(a, 1)
				);
				break;
			case G3D::RenderDevice::QUADS:
				level->indexArray.append(
					RenderBase::Mesh::allocVertex(a, 1),
					RenderBase::Mesh::allocVertex(b, 1),
					RenderBase::Mesh::allocVertex(c, 1),
					RenderBase::Mesh::allocVertex(d, 1)
				);
				break;
			}
		}
} }
