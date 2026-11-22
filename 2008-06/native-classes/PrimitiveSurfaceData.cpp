// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
// 2008-06 RBX::Primitive::setSurfaceData (inactive), v8world/Primitive.cpp (application range 005e4000..005e8000; its
// siblings getFaceInObject 005e76f0 / setVelocity 005e7760 are in AppUnit5E4PrimitiveParts.cpp and setSurfaceType
// 005e7850 follows it). Declared by the part-embedded Primitive.h (surfaceData[6] at +0xd0). This unit also emits the
// out-of-line inline SurfaceData::isEmpty 005e7300 (?isEmpty@SurfaceData@RBX@@QBE_NXZ), which setSurfaceData calls
// twice (005e7789 / 005e77c3) and which inlines SurfaceData::empty() (static s 0097abc4, guard 0097abd0).
#undef _RELEASEASSERT
#include "v8world/Primitive.h"

namespace RBX
{
	// 005e7770: identity from the call pattern and the donor v8world/Primitive.cpp body (same branch order): the null
	// test at +0xd0[id], isEmpty, the forceinlined operator==, operator delete 006a067a / new 0xc 006a0920 with the
	// inline SurfaceData() (0, -0.5, 0.5), then the 12-byte copy.
	void Primitive::setSurfaceData(NormalId id, const SurfaceData& newSurfaceData)
	{
		if (!surfaceData[id] && newSurfaceData.isEmpty())
			return;

		if (surfaceData[id] && *surfaceData[id] == newSurfaceData)
			return;

		if (newSurfaceData.isEmpty())
		{
			delete surfaceData[id];
			surfaceData[id] = NULL;
			return;
		}
		else if (!surfaceData[id])
		{
			surfaceData[id] = new SurfaceData;
		}

		*surfaceData[id] = newSurfaceData;
	}
}
