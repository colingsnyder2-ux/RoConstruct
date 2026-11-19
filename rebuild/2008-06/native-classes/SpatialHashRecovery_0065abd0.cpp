// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::SpatialHash 0065abd0 (inactive); forwards the primitive's fast fuzzy extents to 0065a950.
#include "v8world/SpatialHash2008.h"
#include "v8world/Primitive2008.h"

namespace RBX
{
	// 0065abd0
	void SpatialHash::onPrimitiveExtentsChanged(Primitive* p)
	{
		onPrimitiveExtentsChanged(p, p->getFastFuzzyExtents());
	}
}
