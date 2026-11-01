#pragma float_control(precise,off,push)
#include "util/RunningAverage.h"
#include "util/Math.h"

namespace RBX
{
	void RunningAverageState::update(const G3D::CoordinateFrame& cofm, float radius)
	{
		const float weightNew = 1.0f - 0.75f;
		position = 0.75f * position + weightNew * cofm.translation;
		angles = (angles * 0.75f) + (Quaternion(cofm.rotation) * (weightNew * radius));
	}

	bool RunningAverageState::withinTolerance(const G3D::CoordinateFrame& cofm, float radius, float tolerance)
	{
		G3D::Vector3 deltaPos = Math::vector3Abs(this->position - cofm.translation);
		if (Math::maxAxisLength(deltaPos) > tolerance)
			return false;
		Quaternion deltaAngles = Quaternion(cofm.rotation) * radius;
		if ((this->angles - deltaAngles).maxComponent() > tolerance)
			return false;
		return true;
	}
}
#pragma float_control(pop)
