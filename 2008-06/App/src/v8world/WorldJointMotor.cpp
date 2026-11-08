// 2008-06 native RBX::MotorJoint (inactive); evidence in native-headers/v8world/Joints2008.h.
// Verified by tests/record_native_world_joints.py. Rows of the MotorJoint unit (005e5bf0..005e5ee0): the constructor
// 005e5bf0, setCurrentAngle 005e5da0, the destructor 005e5e00, stepUi 005e5e70 and the scalar deleting destructor
// 005e5ee0 (vtable 0083f764 is emitted here); setCurrentAngle 005e5da0 only in the pending build (KERNEL_STAGE). resetLink 005e5c90 and isAligned 005e5d00 read the native Primitive
// (body, coordinate frame) and are not part of this unit yet.
// >>> native-status (generated) -- do not edit >>>
// WorldJointMotor | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src bbbcecba | roc native-status --write
#include "v8world/Joints2008.h"

namespace RBX
{
	// 005e5bf0: new RevoluteLink (0xd0; Link() 00613d20, RevoluteLink vtable 0083f75c).
	MotorJoint::MotorJoint()
		: link(new RevoluteLink()),
		  currentAngle(0.0f),
		  maxVelocity(0.0f),
		  desiredAngle(0.0f)
	{
	}

	// 005e5e00: non-virtual ~Link (0047d410, folded empty body) then operator delete.
	MotorJoint::~MotorJoint()
	{
		delete link;
	}

#ifdef NATIVE_WORLD_JOINTS_PENDING
	// 005e5da0: IPipelined::getWorld inline (the 2008 KERNEL_STAGE is 7: `cmp eax, 7` at 005e5dc8; the donor
	// v8kernel/IStage.h has 8, see PROPOSALS); RevoluteLink::setJointAngle inline (+0xcc, Link::dirty 00613cb0).
	void MotorJoint::setCurrentAngle(float value)
	{
		if (currentAngle != value)
		{
			currentAngle = value;
			if (getWorld())
				link->setJointAngle(value);
		}
	}
#endif

	// 005e5e70
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
