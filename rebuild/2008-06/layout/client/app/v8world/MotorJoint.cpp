// =============================================================================
// MotorJoint.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8world/MotorJoint.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#undef _RELEASEASSERT
#include "v8world/Joints2008.h"
#include "v8world/Primitive2008.h"
#include "util/Math.h"

#include "v8kernel/Body2008.h"

namespace RBX
{
	bool MotorJoint::isAligned()
	{
		G3D::CoordinateFrame baseWorld = getPrimitive(0)->getCoordinateFrame() * jointCoord0;
		G3D::CoordinateFrame otherBaseWorld = getPrimitive(1)->getCoordinateFrame() * jointCoord1;

		if (Math::fuzzyEq(baseWorld.translation, otherBaseWorld.translation, 0.00001f))
		{
			if (Math::fuzzyEq(baseWorld.rotation.getColumn(2), otherBaseWorld.rotation.getColumn(2), 0.00001f))
				return true;
		}
		return false;
	}
}

namespace RBX
{
RBX::RevoluteLink* MotorJoint::resetLink()
{
	int reversed = getPrimitive(1)->getBody()->getParent() != getPrimitive(0)->getBody();
	link->reset(reversed == 0 ? jointCoord0 : jointCoord1,
	            reversed == 1 ? jointCoord0 : jointCoord1);
	link->setJointAngle(currentAngle);
	return link;
}
}

namespace RBX
{
	MotorJoint::MotorJoint()
		: link(new RevoluteLink()),
		  currentAngle(0.0f),
		  maxVelocity(0.0f),
		  desiredAngle(0.0f)
	{
	}

	MotorJoint::~MotorJoint()
	{
		delete link;
	}

	void MotorJoint::setCurrentAngle(float value)
	{
		if (currentAngle != value)
		{
			currentAngle = value;
			if (getWorld())
				link->setJointAngle(value);
		}
	}

	void MotorJoint::stepUi(int uiStepId)
	{
		float velocity = fabs(maxVelocity);
		float delta = desiredAngle - currentAngle;
		if (fabs(delta) < velocity)
			setCurrentAngle(desiredAngle);
		else if (delta > 0.0f)
			setCurrentAngle(currentAngle + velocity);
		else
			setCurrentAngle(currentAngle - velocity);
	}
}
