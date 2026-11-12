// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client RbxView/QuadVolume.cpp

// Candidate translation unit (score above; library headers required).
#include "QuadVolume.h"

namespace RBX {
namespace View {

// FUNCTION: WEBSERVICE 0x1018ae60
// FUNCTION: ROBLOX 0x0052c3d0
void LevelBuilder::buildFace(NormalId normalId, Purpose purpose)
{
	switch (normalId) {
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

// FUNCTION: WEBSERVICE 0x1018aef0
// FUNCTION: ROBLOX 0x0052c460
void LevelBuilder::build(Purpose purpose)
{
	buildTop(purpose);
	buildBottom(purpose);
	buildLeft(purpose);
	buildRight(purpose);
	buildFront(purpose);
	buildBack(purpose);
}

// FUNCTION: WEBSERVICE 0x1018af40
// FUNCTION: ROBLOX 0x00495140
LevelBuilder::LevelBuilder(
	G3D::ReferenceCountedPointer<Render::Mesh::Level>& level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes
)
	: halfSize(size * 0.5f), surfaceTypes(surfaceTypes), level(level), textureScale(2.0f, 2.0f)
{
}

// FUNCTION: WEBSERVICE 0x1018afa0
// FUNCTION: ROBLOX 0x004951a0
void LevelBuilder::appendQuadFromVertexIndices(unsigned int a, unsigned int b, unsigned int c)
{
	switch (level->primitive) {
	case G3D::RenderDevice::QUADS:
		level->indexArray.append(
			Render::Mesh::allocVertex(a, 1),
			Render::Mesh::allocVertex(a, 1),
			Render::Mesh::allocVertex(b, 1),
			Render::Mesh::allocVertex(c, 1)
		);
		break;
	case G3D::RenderDevice::TRIANGLES:
		level->indexArray.append(
			Render::Mesh::allocVertex(a, 1), Render::Mesh::allocVertex(b, 1), Render::Mesh::allocVertex(c, 1)
		);
		break;
	}
}

// FUNCTION: WEBSERVICE 0x1018b070
// FUNCTION: ROBLOX 0x00495270
void LevelBuilder::appendQuadFromVertexIndices(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
	switch (level->primitive) {
	case G3D::RenderDevice::QUADS:
		level->indexArray.append(
			Render::Mesh::allocVertex(a, 1),
			Render::Mesh::allocVertex(b, 1),
			Render::Mesh::allocVertex(c, 1),
			Render::Mesh::allocVertex(d, 1)
		);
		break;
	case G3D::RenderDevice::TRIANGLES:
		level->indexArray.append(
			Render::Mesh::allocVertex(a, 1), Render::Mesh::allocVertex(b, 1), Render::Mesh::allocVertex(c, 1)
		);
		level->indexArray.append(
			Render::Mesh::allocVertex(c, 1), Render::Mesh::allocVertex(d, 1), Render::Mesh::allocVertex(a, 1)
		);
		break;
	}
}

// FUNCTION: WEBSERVICE 0x1018b190
// FUNCTION: ROBLOX 0x00495390
void LevelBuilder::appendQuadFromIndexArray(int a, int b, int c)
{
	appendQuadFromVertexIndices(level->indexArray[a], level->indexArray[b], level->indexArray[c]);
}

// FUNCTION: WEBSERVICE 0x1018b1c0
// FUNCTION: ROBLOX 0x004953c0
void LevelBuilder::appendQuadFromIndexArray(int a, int b, int c, int d)
{
	appendQuadFromVertexIndices(level->indexArray[a], level->indexArray[b], level->indexArray[c], level->indexArray[d]);
}

} // namespace View
} // namespace RBX
