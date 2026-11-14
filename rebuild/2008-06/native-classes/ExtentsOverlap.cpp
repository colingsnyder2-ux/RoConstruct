// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "util/Extents.h"

namespace RBX
{
	void Extents::unionWith(const Extents& other)
	{
		low = low.min(other.low);
		high = high.max(other.high);
	}

	bool Extents::overlapsOrTouches(const Extents& other) const
	{
		if ((low.x > other.high.x) || (low.y > other.high.y) || (low.z > other.high.z))
			return false;
		if ((high.y < other.low.y) || (high.x < other.low.x) || (high.z < other.low.z))
			return false;
		return true;
	}
}
