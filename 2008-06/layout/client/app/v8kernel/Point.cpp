#include "v8kernel/Point2008.h"

namespace RBX
{
	void Point::forceToBody()
	{
		body->accumulateForce(force, worldPos);
	}

	void Point::step()
	{
		worldPos = body->getPVUnsafe().position.pointToWorldSpace(localPos);
		force = G3D::Vector3::zero();
	}

	void Point::setWorldPos(const G3D::Vector3& _worldPos)
	{
		worldPos = _worldPos;
		localPos = body->getCoordinateFrame().pointToObjectSpace(worldPos);
	}
}
