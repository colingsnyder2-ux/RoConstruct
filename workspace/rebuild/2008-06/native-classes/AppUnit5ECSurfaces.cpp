// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 v8datamodel/Surfaces.cpp (application range 005ec000..005f0000): the Surfaces members that do not need the
// per-face property descriptor statics. Inactive native unit against the read-only native v8datamodel/Surfaces.h.
// Layout (constructor 005ecbb0): six 8-byte Surface members, Top +0x0 (NORM_Y), Bottom +0x8 (NORM_Y_NEG),
// Left +0x10 (NORM_X_NEG), Right +0x18 (NORM_X), Front +0x20 (NORM_Z_NEG), Back +0x28 (NORM_Z), each built by
// Surface(PartInstance*, NormalId) 005f1270.
#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surfaces.h"

namespace RBX
{
	// 005ecbb0
	Surfaces::Surfaces(PartInstance* partInstance)
		: Top(partInstance, NORM_Y), Bottom(partInstance, NORM_Y_NEG), Left(partInstance, NORM_X_NEG),
		  Right(partInstance, NORM_X), Front(partInstance, NORM_Z_NEG), Back(partInstance, NORM_Z)
	{
	}

	// 005ecc50: Bottom INLET (4), then Front / Back / Left / Right NO_SURFACE (Surface::getSurfaceType 005f1290)
	const bool Surfaces::isStandardPart() const
	{
		return Bottom.getSurfaceType() == INLET && Front.getSurfaceType() == NO_SURFACE
			&& Back.getSurfaceType() == NO_SURFACE && Left.getSurfaceType() == NO_SURFACE
			&& Right.getSurfaceType() == NO_SURFACE;
	}
}
