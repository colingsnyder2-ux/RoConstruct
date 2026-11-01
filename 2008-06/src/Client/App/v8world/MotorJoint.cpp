#pragma float_control(precise,off)
#include "v8world/MotorJoint.h"
#include "v8world/World.h"
#include "v8world/Primitive.h"
#include "v8world/Assembly.h"
#include "util/Math.h"

namespace RBX
{
	// TODO: check which of these belong in the header file

	MotorJoint::MotorJoint()
		: currentAngle(0.0f),
		  link(new RevoluteLink()),
		  maxVelocity(0.0f),
		  desiredAngle(0.0f)
	{
	}

	MotorJoint::~MotorJoint()
	{
		delete link;
	}

	G3D::CoordinateFrame MotorJoint::getMeInOther(Primitive* me)
	{
		G3D::CoordinateFrame rotatedCoord0 = G3D::CoordinateFrame(
			Math::rotateAboutZ(jointCoord0.rotation, currentAngle),
			jointCoord0.translation);

		G3D::CoordinateFrame p1InP0 = rotatedCoord0 * jointCoord1.inverse();
		if (me == getPrimitive(1))
		{
			return p1InP0;
		}
		else
		{
			RBXASSERT(me == getPrimitive(0));
			return p1InP0.inverse();
		}
	}

	size_t MotorJoint::hashCode() const
	{
		const int magic = 1640531527;
		size_t h;

		h = (Math::hash(jointCoord0.translation) - magic);
		h = (Math::hash(jointCoord1.translation) - magic + (h >> 2) + (h << 6)) ^ h;
		return h;
	}

	void MotorJoint::setCurrentAngle(float value)
	{
		if (currentAngle != value)
		{
			currentAngle = value;
			if (getWorld2008())
				link->setJointAngle(value);
		}
	}

	void MotorJoint::setJointAngle(float value)
	{
		RBXASSERT(link);
		if ((1.0f) == -1)
		{
			RBXASSERT(0);

			Primitive* p0 = getPrimitive(0);

			G3D::CoordinateFrame oldParentCoord = p0->getCoordinateFrame();
			link->setJointAngle(-value);
			Assembly* assembly = getPrimitive(1)->getAssembly();
			if (!assembly->getAnchored())
			{
				Primitive* mainPrim = assembly->getMainPrimitive();
				G3D::CoordinateFrame newParentCoord = p0->getCoordinateFrame();
				G3D::CoordinateFrame parentInRoot = mainPrim->getCoordinateFrame().toObjectSpace(newParentCoord);
				G3D::CoordinateFrame newRoot = oldParentCoord * parentInRoot.inverse();
				mainPrim->getBody()->setCoordinateFrame(newRoot);
			}
		}
		else
		{
			link->setJointAngle(value);
		}
	}

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

	void MotorJoint::stepUi(int uiStepId)
	{
		double speed = fabs(maxVelocity);
		double delta = static_cast<double>(desiredAngle) - currentAngle;
		if (fabs(delta) < speed)
			setCurrentAngle(desiredAngle);
		else if (delta > 0.0)
			setCurrentAngle(static_cast<float>(currentAngle + speed));
		else
			setCurrentAngle(static_cast<float>(currentAngle - speed));
	}
}
