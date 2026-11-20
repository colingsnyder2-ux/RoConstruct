// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// RBX::Motor default constructor 005e4ee0 (identity registry ??0Motor@RBX@@QAE@XZ), the row after Motor(Joint*) in the
// joint-constructor unit 005e4000 (GlueRotateCtors.cpp holds its siblings and is not this batch's file, so this row has
// its own unit; flags and the donor/native joint-header preamble are copied from GlueRotateCtors.cpp).
// Evidence: new(0x98) MotorJoint() 005e5bf0, the DescribedCreatable<Motor, JointInstance, sMotor>(Joint*) base ctor
// 005e43a0, the Motor vtable chain (0083f68c ..), then setName (std::string from the class-name array 0083f6cc,
// Instance::setName 0055af90), the same shape as Weld() 005e4810 in SnapWeldCtors.cpp.
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

namespace RBX {
// 005e4ee0
Motor::Motor() : DescribedCreatable<Motor, JointInstance, sMotor>(new MotorJoint())
{
	setName(sMotor);
}
}
