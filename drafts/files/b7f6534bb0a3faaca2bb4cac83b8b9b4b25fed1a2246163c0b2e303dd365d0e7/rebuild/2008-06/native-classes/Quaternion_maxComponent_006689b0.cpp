// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// Draft of RBX::Quaternion::maxComponent (006689b0).
// INFERRED: returns the largest of |x|, |y|, |z|, |w|; body derived from the 2008-06 binary.
// The donor header (tools/rbxgs/Client/App/include/util/Quaternion.h) declares maxComponent()
// with public floats x, y, z, w; this body is written from the target disassembly only.
#include "util/Quaternion.h"

#include <math.h>
#include <algorithm>

namespace RBX
{
	// 006689b0: the four absolute values are stored w, z, y, x ([esp] .. [esp + 0xc]) and compared through pointers
	// (`lea edx, [esp]` / `lea ecx, [esp + 8]` selections), i.e. nested std::max over const references to the fabs
	// temporaries, the right-hand inner max evaluated first; the final `test ah, 0x41` returns the left max on ties.
	float Quaternion::maxComponent() const
	{
		return std::max(std::max(fabs(x), fabs(y)), std::max(fabs(z), fabs(w)));
	}
}
