// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8kernel/Link.cpp

// Candidate translation unit (score above; library headers required).
#include "v8kernel/Link.h"

#include "util/Math.h"
#include "v8kernel/Body.h"

#include <cstddef>

namespace RBX {

// FUNCTION: WEBSERVICE 0x101027f0
void Link::dirty()
{
	if (body != NULL) {
		body->getRoot()->advanceStateIndex();
	}
}

// FUNCTION: WEBSERVICE 0x10102800
void RevoluteLink::computeChildInParent(CoordinateFrame& answer) const
{
	CoordinateFrame rotatedParentCoord(Math::rotateAboutZ(parentCoord.rotation, jointAngle), parentCoord.translation);

	answer = rotatedParentCoord * childCoordInverse;
}

// FUNCTION: WEBSERVICE 0x10102880
Link::Link() : body(NULL), stateIndex(Body::getNextStateIndex())
{
}

// FUNCTION: WEBSERVICE 0x101028c0
const CoordinateFrame& Link::getChildInParent() const
{
	int index = body->getParent()->getStateIndex();

	if (stateIndex != index) {
		computeChildInParent(childInParent);

		stateIndex = index;
	}

	return childInParent;
}

// FUNCTION: WEBSERVICE 0x10102900
void Link::reset(const CoordinateFrame& parentC, const CoordinateFrame& childC)
{
	parentCoord = parentC;
	childCoord = childC;
	childCoordInverse = childC.inverse();
}

Link::~Link()
{
}

} // namespace RBX
