// 2008-06 native (inactive): humanoid state force limits 00666350 / 006663a0 (see AppUnit664/HumanoidForceLimits.h).
#include "AppUnit664/HumanoidForceLimits.h"

namespace RBX
{
	namespace HUMAN
	{
		G3D::Vector3 maxMoveForce()
		{
			static G3D::Vector3 force(1000.0f, 10000.0f, 1000.0f);
			return force;
		}

		G3D::Vector3 minMoveForce()
		{
			static G3D::Vector3 force(-1000.0f, 0.0f, -1000.0f);
			return force;
		}
	}
}
