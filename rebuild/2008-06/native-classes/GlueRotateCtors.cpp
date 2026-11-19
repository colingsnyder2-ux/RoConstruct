// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Glue/Rotate/RotateP/RotateV/Motor constructors from the 005e4000 unit. Byte-exact: Glue() 005e49a0, Rotate() 005e4ad0,
// RotateP() 005e4c60, RotateV() 005e4dd0 and the (Joint*) constructors 005e4920/005e4a60/005e4b90/005e4d30 (identical
// bodies, one per class). Unlike Snap/Weld these set no name in the constructor. The Motor() default is not recovered here.
// /fp:fast: Motor::setMaxVelocity 005e4fe0 loads maxVelocity before the argument and compares with fucom / fstp st(1),
// the same x87 order as VelocityMotor::setMaxVelocity 0060c580 (Feature.cpp, /fp:fast); without it cl emits fucompp.
//
// Root cause of the former RotateV() identity failure: JointInstance.h reaches the donor v8world/Joint.h (13 virtual
// slots), but the 2008 binary's Joint has 15 slots (canStepWorld/canStepUi/stepWorld/stepUi) and its RotateVJoint vtable
// 0083e17c references ?canStepUi@DynamicRotateJoint 00565950, ?getJointType@RotateVJoint 005e2790 and
// ??_GRotateVJoint 005e28e0. The donor Joint/RigidJoint/Edge declarations are therefore pre-included under
// non-colliding macro names so v8world/Joints2008.h can define the native 15-slot hierarchy under the original
// symbol names; IJointOwner keeps its donor meaning because JointInstance.h derives from it.
#define IJointOwner IJointOwnerDonor
#define Edge EdgeDonor
#define EdgeState EdgeStateDonor
#define UNDEFINED UNDEFINED_DONOR
#define STEPPING STEPPING_DONOR
#define SLEEPING SLEEPING_DONOR
#define TOUCHING TOUCHING_DONOR
#define TOUCHING_SLEEPING TOUCHING_SLEEPING_DONOR
#define Joint JointDonor
#define RigidJoint RigidJointDonor
#include "v8world/Joint.h"
#include "v8world/RigidJoint.h"
#undef RigidJoint
#undef Edge
#undef EdgeState
#undef UNDEFINED
#undef STEPPING
#undef SLEEPING
#undef TOUCHING
#undef TOUCHING_SLEEPING
#undef Joint

#define NATIVE_IPIPELINED2008_DONOR
#include "v8world/Joints2008.h"
#include "v8datamodel/JointInstance.h"

// 005e4fe0 raises prop_MaxVelocity 0097ab74 (getset factory PropDescriptor<Motor, float> 005e29c0, constructor 005e36e0).
static RBX::Reflection::PropDescriptor<RBX::Motor, float> prop_MaxVelocity("MaxVelocity", "Data", &RBX::Motor::getMaxVelocity, &RBX::Motor::setMaxVelocity, RBX::Reflection::PropertyDescriptor::STANDARD);

namespace RBX {
Glue::Glue(Joint* joint) : DescribedCreatable<Glue, JointInstance, sGlue>(joint) { }
Glue::Glue() : DescribedCreatable<Glue, JointInstance, sGlue>(new GlueJoint()) { }
Rotate::Rotate(Joint* joint) : DescribedCreatable<Rotate, JointInstance, sRotate>(joint) { }
Rotate::Rotate() : DescribedCreatable<Rotate, JointInstance, sRotate>(new RotateJoint()) { }
RotateP::RotateP(Joint* joint)
    : DescribedCreatable<RotateP, JointInstance, sRotateP>(joint)
{
}
RotateV::RotateV(Joint* joint) : DescribedCreatable<RotateV, JointInstance, sRotateV>(joint)
{
}
// 005e4dd0: the 2008 default ctor news a native RotateVJoint (0xc8 bytes, channelValue at +0xc4 cleared inline),
// stores the proven 0083e17c vtable and forwards a Joint* to the proven DescribedCreatable base ctor 005e42b0.
RotateV::RotateV() : DescribedCreatable<RotateV, JointInstance, sRotateV>(static_cast<Joint*>(new RotateVJoint()))
{
}
Motor::Motor(Joint* joint) : DescribedCreatable<Motor, JointInstance, sMotor>(joint) { }

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
