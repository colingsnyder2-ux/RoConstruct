// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8kernel/Point.cpp

// Candidate translation unit (score above; library headers required).
#include "v8kernel/Point.h"

#include "decomp.h"
#include "v8kernel/Body.h"

#include <cstddef>

namespace RBX {

// FUNCTION: WEBSERVICE 0x1011e660
Point::Point(Body* _body) : numOwners(1), body(_body != NULL ? _body : Body::getWorldBody())
{
}

// FUNCTION: WEBSERVICE 0x1011e6d0
void Point::forceToBody()
{
	body->accumulateForce(force, worldPos);
}

// FUNCTION: WEBSERVICE 0x1011e6f0
void Point::step()
{
	worldPos = body->getPV().position.pointToWorldSpace(localPos);
	force = Vector3::zero();
}

// FUNCTION: WEBSERVICE 0x1011e7c0
void Point::setWorldPos(const Vector3& _worldPos)
{
	worldPos = _worldPos;
	localPos = body->getPV().position.pointToObjectSpace(worldPos);
}

} // namespace RBX
