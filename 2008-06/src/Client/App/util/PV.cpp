#include "util/PV.h"

namespace RBX
{
	Velocity PV::velocityAtPoint(const G3D::Vector3& worldPos) const
	{
		G3D::Vector3 v1 = worldPos - this->position.translation;
		G3D::Vector3 v2 = this->velocity.rotational.cross(v1);
		return Velocity(this->velocity.linear + v2, this->velocity.rotational);
	}

	void computePVAtLocalCoord(const PV& pv, const G3D::CoordinateFrame& localCoord, PV& result)
	{
		G3D::CoordinateFrame worldCoord = pv.position * localCoord;
		PV answer(worldCoord, pv.velocityAtPoint(worldCoord.translation));
		result = answer;
	}

	PV PV::pvAtLocalCoord(const G3D::CoordinateFrame& localCoord) const
	{
		PV result;
		computePVAtLocalCoord(*this, localCoord, result);
		return result;
	}

	PV PV::pvAtLocalOffset(const G3D::Vector3& localOffset) const
	{
		G3D::CoordinateFrame cf(G3D::Matrix3::identity(), localOffset);
		return this->pvAtLocalCoord(cf);
	}
}