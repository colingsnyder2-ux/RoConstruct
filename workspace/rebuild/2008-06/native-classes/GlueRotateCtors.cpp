// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Glue/Rotate/RotateP/RotateV/Motor constructors from the 005e4000 unit. Byte-exact: Glue() 005e49a0, Rotate() 005e4ad0 and the
// (Joint*) constructors 005e4920/005e4a60/005e4b90/005e4d30 (identical bodies, one per class). Unlike Snap/Weld these set no
// name in the constructor. The RotateP()/RotateV()/Motor() defaults are not recovered here.
// /fp:fast: Motor::setMaxVelocity 005e4fe0 loads maxVelocity before the argument and compares with fucom / fstp st(1),
// the same x87 order as VelocityMotor::setMaxVelocity 0060c580 (Feature.cpp, /fp:fast); without it cl emits fucompp.
#include "v8datamodel/JointInstance.h"
#include "v8world/GlueJoint.h"
#include "v8world/RotateJoint.h"
// The 2008 MotorJoint (no polarity; maxVelocity +0x90, stored by 005e4fe0) over the donor Joint that JointInstance.h
// reaches, in place of the donor v8world/MotorJoint.h.
#define NATIVE_MOTOR_JOINT_DONOR_BASE
#include "v8world/Joints2008.h"

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
}
