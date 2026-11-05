#include "util/Units.h"

using namespace RBX;

G3D::Vector3 Units::kmsAccelerationToRbx(const G3D::Vector3& kmsAccel)
{
	return kmsAccel * 20.0f;
}

float Units::kmsForceToRbx(float kmsForce)
{
	return kmsForce * 20.0f;
}