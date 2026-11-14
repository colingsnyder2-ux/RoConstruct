// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// Inactive native 2008-06 recovery: two out-of-line RBX::Extents members emitted outside the Extents unit
// (AppUnit609_2008Extents.cpp holds 0060f3e0..0060fe95):
//   unionWith 0057dee0 (?unionWith@Extents@RBX@@QAEXABV12@@Z), overlapsOrTouches 00606b60
//   (?overlapsOrTouches@Extents@RBX@@QBE_NABV12@@Z).
// Layout (low +0, high +0xc) is the committed native util/Extents.h (read-only here).
#include "util/Extents.h"

namespace RBX
{
	// 0057dee0
	void Extents::unionWith(const Extents& other)
	{
		low = low.min(other.low);
		high = high.max(other.high);
	}

	// 00606b60
	bool Extents::overlapsOrTouches(const Extents& other) const
	{
		if ((low.x > other.high.x) || (low.y > other.high.y) || (low.z > other.high.z))
			return false;
		if ((high.y < other.low.y) || (high.x < other.low.x) || (high.z < other.low.z))
			return false;
		return true;
	}
}
