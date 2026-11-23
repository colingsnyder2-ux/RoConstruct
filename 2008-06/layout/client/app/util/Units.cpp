#include "../../../../../../tools/rbxgs/Client/App/include/util/Units.h"

namespace RBX {
G3D::Vector3 Units::kmsAccelerationToRbx(const G3D::Vector3& kmsAccel)
{
	return kmsAccel * 20.0f;
}
}
