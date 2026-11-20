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
