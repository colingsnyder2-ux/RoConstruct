// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// 2008-06 native RBX::Motor member function recoveries.
// PROVEN EXACT: 005e5080 (61 bytes) Motor::setCurrentAngle, 005e5020 (88 bytes) Motor::setDesiredAngle.
// Include prelude mirrors the proven GlueRotateCtors.cpp unit so the 15-slot native Joint /
// MotorJoint hierarchy (Joint +0x88 link, +0x8c currentAngle, +0x90 maxVelocity, +0x94
// desiredAngle) is declared under the original symbol names.
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

extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)
extern "C" double __cdecl fabs(double);
#pragma intrinsic(fabs)

// INFERRED: the descriptor addresses 0097aae0 / 0097ab58 are the two PropDescriptor<Motor,float>
// objects built by Motor ctor 005e36e0 initializers 007f6e00 / 007f6dc0. Their getters/setters are
// getCurrentAngle/setCurrentAngle and getDesiredAngle/setDesiredAngle (assembly calls 005e5da0 and
// stores +0x94 respectively), matching the sibling VelocityMotor descriptors in Feature.cpp.
extern const float toleranceBase;   // INFERRED: binary constant at 00827494 (root_ref_bind)
extern const float toleranceScale;  // INFERRED: binary constant at 0083f6d4 (root_ref_bind)

namespace RBX {

static Reflection::PropDescriptor<Motor, float> prop_CurrentAngle("CurrentAngle", "Data", &Motor::getCurrentAngle, &Motor::setCurrentAngle, Reflection::PropertyDescriptor::STANDARD);
static Reflection::PropDescriptor<Motor, float> prop_DesiredAngle("DesiredAngle", "Data", &Motor::getDesiredAngle, &Motor::setDesiredAngle, Reflection::PropertyDescriptor::STANDARD);

// 005e5080: compare value with MotorJoint::currentAngle +0x8c, call MotorJoint::setCurrentAngle
// 005e5da0 and raise prop_CurrentAngle. Byte order matches VelocityMotor::setCurrentAngle 0060c600.
void Motor::setCurrentAngle(float value)
{
	MotorJoint* mj = static_cast<MotorJoint*>(joint);
	if (value != mj->getCurrentAngle())
	{
		mj->setCurrentAngle(value);
		raisePropertyChanged(prop_CurrentAngle);
	}
}

// 005e5020: compare value with MotorJoint::desiredAngle +0x94 (barrier keeps the loaded previous),
// then tolerance test fabs(value-previous) <= (fabs(value)+toleranceBase)*toleranceScale, store +0x94
// and tail-jump to Instance::raisePropertyChanged 0040db00 with prop_DesiredAngle.
void Motor::setDesiredAngle(float value)
{
	MotorJoint* mj = static_cast<MotorJoint*>(joint);
	float previous = mj->desiredAngle;
	_ReadWriteBarrier();
	if (value != previous && !(fabs(value - previous) <= (fabs(value) + toleranceBase) * toleranceScale))
	{
		mj->desiredAngle = value;
		raisePropertyChanged(prop_DesiredAngle);
	}
}

} // namespace RBX
