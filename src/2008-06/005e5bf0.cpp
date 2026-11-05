// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/MotorJoint.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/MotorJoint.h"

#include "decomp.h"
#include "util/Math.h"
#include "v8kernel/Body.h"
#include "v8world/Primitive.h"
#include "v8world/World.h"

#include <cmath>
#include <cstddef>

namespace RBX {

// FUNCTION: WEBSERVICE 0x1010a910 FOLDED
Joint::JointType MotorJoint::getJointType() const
{
	return MOTOR_JOINT;
}

// FUNCTION: WEBSERVICE 0x1011fed0
MotorJoint::MotorJoint() : link(new RevoluteLink()), currentAngle(0.0f), maxVelocity(0.0f), desiredAngle(0.0f)
{
}

// FUNCTION: WEBSERVICE 0x1011ff70
RevoluteLink* MotorJoint::resetLink()
{
	int index = getPrimitive(1)->getBody()->getParent() != getPrimitive(0)->getBody();

	link->reset(index == 0 ? jointCoord0 : jointCoord1, index == 1 ? jointCoord0 : jointCoord1);

	link->setJointAngle(currentAngle);

	return link;
}

// FUNCTION: WEBSERVICE 0x1011ffd0
bool MotorJoint::isAligned()
{
	CoordinateFrame baseWorld = getPrimitive(0)->getCoordinateFrame() * jointCoord0;
	CoordinateFrame rotorWorld = getPrimitive(1)->getCoordinateFrame() * jointCoord1;

	return Math::fuzzyEq(baseWorld.translation, rotorWorld.translation, 1.0e-5f) &&
		   Math::fuzzyEq(baseWorld.rotation.getColumn(2), rotorWorld.rotation.getColumn(2), 1.0e-5f);
}

// FUNCTION: WEBSERVICE 0x10120070
void MotorJoint::setCurrentAngle(float value)
{
	if (currentAngle != value) {
		currentAngle = value;

		World* world = getWorld();

		if (world != NULL) {
			world->onMotorAngleChanged(this);
			link->setJointAngle(value);
		}
	}
}

// FUNCTION: WEBSERVICE 0x101200d0
MotorJoint::~MotorJoint()
{
	delete link;
}

// FUNCTION: WEBSERVICE 0x10120140
void MotorJoint::stepUi(int uiStepId)
{
	float maxStep = fabs(maxVelocity);

	float delta = desiredAngle - currentAngle;

	if (fabs(delta) < maxStep) {
		setCurrentAngle(desiredAngle);
	}
	else if (delta > 0.0f) {
		setCurrentAngle(currentAngle + maxStep);
	}
	else {
		setCurrentAngle(currentAngle - maxStep);
	}
}

} // namespace RBX
