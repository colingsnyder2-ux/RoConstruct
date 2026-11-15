// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Glue/Rotate/RotateP/RotateV/Motor constructors from the 005e4000 unit. Byte-exact: Glue() 005e49a0, Rotate() 005e4ad0 and the
// (Joint*) constructors 005e4920/005e4a60/005e4b90/005e4d30 (identical bodies, one per class). Unlike Snap/Weld these set no
// name in the constructor. The RotateP()/RotateV()/Motor() defaults are not recovered here.
#include "v8datamodel/JointInstance.h"
#include "v8world/GlueJoint.h"
#include "v8world/RotateJoint.h"
#include "v8world/MotorJoint.h"

// 005e4fe0 raises prop_MaxVelocity 0097ab74 (getset factory PropDescriptor<Motor, float> 005e29c0, constructor 005e36e0).
static RBX::Reflection::PropDescriptor<RBX::Motor, float> prop_MaxVelocity("MaxVelocity", "Data", &RBX::Motor::getMaxVelocity, &RBX::Motor::setMaxVelocity, RBX::Reflection::PropertyDescriptor::STANDARD);

namespace RBX {
Glue::Glue(Joint* joint) : DescribedCreatable<Glue, AutoJoint, sGlue>(joint) { }
Glue::Glue() : DescribedCreatable<Glue, AutoJoint, sGlue>(new GlueJoint()) { }
Rotate::Rotate(Joint* joint) : DescribedCreatable<Rotate, AutoJoint, sRotate>(joint) { }
Rotate::Rotate() : DescribedCreatable<Rotate, AutoJoint, sRotate>(new RotateJoint()) { }
RotateP::RotateP(Joint* joint)
    : DescribedCreatable<RotateP, AutoJoint, sRotateP>(joint)
{
}
RotateV::RotateV(Joint* joint) : DescribedCreatable<RotateV, AutoJoint, sRotateV>(joint)
{
}
Motor::Motor(Joint* joint) : DescribedCreatable<Motor, AutoJoint, sMotor>(joint) { }

// Pending the 2008 MotorJoint layout (NATIVE_WORLD_JOINTS_PENDING): the donor v8world/MotorJoint.h reached here keeps
// `int polarity` (absent in 2008, native v8world/Joints2008.h), so maxVelocity lands at +0x94 instead of +0x90 (the
// default build's getter is byte-identical to VelocityMotor::getDesiredAngle 0060a250). Joints2008.h cannot be
// included next to the donor joint headers that v8datamodel/JointInstance.h and PartInstance.h reach.
#ifdef NATIVE_WORLD_JOINTS_PENDING
// Motor::getMaxVelocity (inline in 005e4fe0): the joint +0x150 is a MotorJoint (maxVelocity +0x90 in 2008).
float Motor::getMaxVelocity() const
{
	return static_cast<MotorJoint*>(joint)->maxVelocity;
}

// 005e4fe0: one load of joint +0x150, compare / store maxVelocity, then a tail jump to Instance::raisePropertyChanged
// 0040db00 with prop_MaxVelocity. Donor: tools/rbxgs v8datamodel/JointInstance.cpp Motor::setMaxVelocity.
void Motor::setMaxVelocity(float value)
{
	if (value != getMaxVelocity())
	{
		static_cast<MotorJoint*>(joint)->maxVelocity = value;
		raisePropertyChanged(prop_MaxVelocity);
	}
}
#endif
}
