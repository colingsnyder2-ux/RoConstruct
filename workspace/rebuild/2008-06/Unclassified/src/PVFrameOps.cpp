#pragma float_control(precise, off)
#include "PVFrameOps.h"

// Genuine SDK dependency; independently matches00598a60.
__declspec(noinline) RBX::Velocity RBX::PV::velocityAtPoint(const G3D::Vector3& worldPos) const
	{
		G3D::Vector3 v1 = worldPos - this->position.translation;
		G3D::Vector3 v2 = this->velocity.rotational.cross(v1);
		return Velocity(this->velocity.linear + v2, this->velocity.rotational);
	}

void RBX::recoveredPVLocalFrame(const PV& source, const G3D::CoordinateFrame& local, PV& result)
{
    recoveredFrameMultiply(source.position, local, result.position);
    result.velocity = source.velocityAtPoint(result.position.translation);
}
