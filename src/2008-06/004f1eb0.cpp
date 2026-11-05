// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-view-dll roc_espeon_pbbstdreferenceclamp42d9923d1c681e13.cpp

// Candidate translation unit (score above; library headers required).
#include "PBBMesh.h"
#include <algorithm>
PBBBuilder::PBBBuilder(G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>& level, G3D::Vector3 size, RBX::View::RenderSurfaceTypes surfaceTypes)
	: LevelBuilder(level, size, surfaceTypes)
{
	strips.x = std::max<int>(1, size.x / 6.0f);
	strips.y = std::max<int>(1, size.y / 6.0f);
	strips.z = std::max<int>(1, size.z / 6.0f);

	strips.x = std::min<int>(4, strips.x);
	strips.y = std::min<int>(4, strips.y);
	strips.z = std::min<int>(4, strips.z);
}

