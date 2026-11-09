// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_daedc454a17b971b.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/Primitive.h"
namespace RBX {
void Primitive::setGridCorner(const G3D::CoordinateFrame& gridCorner)
	{
		G3D::Vector3 hVec = (*reinterpret_cast<Geometry* const*>(reinterpret_cast<const char*>(this) + 0x9c))->getGridSize() * 0.5f;
		setCoordinateFrame(G3D::CoordinateFrame(gridCorner.rotation, gridCorner.pointToWorldSpace(hVec)));
	}

	
}
