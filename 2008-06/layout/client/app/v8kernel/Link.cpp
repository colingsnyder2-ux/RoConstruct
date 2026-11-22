#include "v8kernel/Link.h"
#include "v8kernel/Body2008.h"
#include "util/Math.h"

namespace RBX
{
	void recoveredFrameMultiply(const G3D::CoordinateFrame&, const G3D::CoordinateFrame&, G3D::CoordinateFrame&);
}

namespace RBX
{
	Link::Link()
		: body(NULL)
	{
		stateIndex = Body::getNextStateIndex();
	}

	const G3D::CoordinateFrame& Link::getChildInParent() const
	{
		int index = body->getParent()->getStateIndex();

		if (stateIndex != index)
		{
			computeChildInParent(childInParent);
			stateIndex = index;
		}

		return childInParent;
	}

	void Link::reset(const G3D::CoordinateFrame& _parentCoord, const G3D::CoordinateFrame& _childCoord)
	{
		parentCoord = _parentCoord;
		childCoord = _childCoord;
		childCoordInverse = _childCoord.inverse();
	}

	void RevoluteLink::computeChildInParent(G3D::CoordinateFrame& answer) const
	{
		G3D::CoordinateFrame rotatedParentCoord(
			Math::rotateAboutZ(parentCoord.rotation, jointAngle),
			parentCoord.translation);

		recoveredFrameMultiply(rotatedParentCoord, childCoordInverse, answer);
	}
}

#include "util/Name.h"

namespace RBX {

void Link::dirty()
{
	if (body) {
		body->getRoot()->advanceStateIndex();
	}
}

}
