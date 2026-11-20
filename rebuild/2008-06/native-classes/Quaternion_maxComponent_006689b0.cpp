// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// Draft of RBX::Quaternion::maxComponent (006689b0).
// INFERRED: returns the largest of |x|, |y|, |z|, |w|; body derived from the 2008-06 binary.
// The donor header (tools/rbxgs/Client/App/include/util/Quaternion.h) declares maxComponent()
// with public floats x, y, z, w; this body is written from the target disassembly only.
#include "util/Quaternion.h"

#include <math.h>

namespace RBX
{
	float Quaternion::maxComponent() const
	{
		// INFERRED: balanced tournament max of the absolute components, derived from the
		// target disassembly (stores |w|,|z|,|y|,|x|, compares pairs, then the winners).
		float aw = fabsf(w);
		float az = fabsf(z);
		float ay = fabsf(y);
		float ax = fabsf(x);
		float m = az > aw ? az : aw;
		float n = ay > ax ? ay : ax;
		return m > n ? m : n;
	}
}
