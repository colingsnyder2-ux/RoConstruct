// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client RbxView/QuadVolume.cpp

// Candidate translation unit (score above; library headers required).
#include "QuadVolume.h"

namespace RBX {
namespace View {

LevelBuilder::LevelBuilder(
	G3D::ReferenceCountedPointer<Render::Mesh::Level>& level,
	G3D::Vector3 size,
	RenderSurfaceTypes surfaceTypes
)
	: halfSize(size * 0.5f), surfaceTypes(surfaceTypes), level(level), textureScale(2.0f, 2.0f)
{
}

// FUNCTION: WEBSERVICE 0x1018ae60
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
void LevelBuilder::build(Purpose purpose)
{
	buildTop(purpose);
	buildBottom(purpose);
	buildLeft(purpose);
	buildRight(purpose);
	buildFront(purpose);
	buildBack(purpose);
}

} // namespace View
} // namespace RBX
