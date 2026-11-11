// Inactive native recovery of the RBX::Units unit 00660180..006601ba (2008-06): the two out-of-line conversions of
// util/Units.h (donor header, read-only), between the Cofm getters 00660160 / 00660170 and the hit-test filter unit
// 006601c0. Both multiply by the 20.0f constant at 008222f0 and return in the cdecl way the callers expect (Vector3 by
// hidden return pointer at 00660180; float in st0 at 006601b0). Callers: 0063e5bb, 00658f82, 0066ec49 (Vector3) and
// 00646c91 (float). See tests/record_native_app_unit660_2008.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "util/Units.h"

namespace RBX
{
	G3D::Vector3 Units::kmsAccelerationToRbx(const G3D::Vector3& kmsAccel)   // 00660180
	{
		return kmsAccel * 20.0f;
	}

	float Units::kmsForceToRbx(float kmsForce)                                // 006601b0
	{
		return kmsForce * 20.0f;
	}
}
