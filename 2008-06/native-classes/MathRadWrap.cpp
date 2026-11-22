// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#undef _RELEASEASSERT
// 2008-06 native RBX::Math::radWrap (inactive). Flags copied from AppUnit5DC_2008Math.cpp (the util/Math.cpp rows).
// Identity: registry ?radWrap@Math@RBX@@SAMM@Z 005cbec0 (identity-closure); its row sits between the ControllerService
// rows (005cbe70) and Camera::askSetParent 005cbf20, away from the other Math rows 005dd780..005df47f; callers include
// Math::rotationToByte 005ded68 and the Humanoid/Camera bodies. Declaration: util/Math.h (static float radWrap(float)).
#include "util/Math.h"
#include <cmath>

namespace RBX
{
	// 005cbec0: -pi [0083a318] / pi [0081e378] range test, then floor((rad + pi) * (1 / twoPi) [0083a314]) rounded by
	// fistp (Math::iRound) and rad - n * twoPi [0082b3b4]. Donor body: util/Math.cpp.
	float Math::radWrap(float rad)
	{
		if (rad >= -pi() && rad < pi())
			return rad;

		float rot = 1 / twoPi();
		float f = floor((rad + pi()) * rot);
		return rad - Math::iRound(f) * twoPi();
	}
}
