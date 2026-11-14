// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 2008-06 native RBX::AutoJoint C0 / C1 setters (inactive): setC0 005e4490 and setC1 005e44c0. Flags: the sibling
// AutoJoint.cpp (setPart0 / setPart1). Donor bodies: tools/rbxgs v8datamodel/JointInstance.cpp AutoJoint::setC0/setC1.
// Both call Joint::setJointCoord 00645750 on the joint at +0x150 (JointInstance::joint) and then
// Instance::raisePropertyChanged 0040db00 with the static descriptors prop_C0 0097ab3c / prop_C1 0097ab90.
// The 2008 getset factory of the C0/C1 descriptors is PropDescriptor<JointInstance, CoordinateFrame> 005e2970
// (AppUnit5E0JointReflection.cpp); the shared JointInstance.h declares getC0/setC0 on AutoJoint (the identity-registry
// names ?setC0@AutoJoint@RBX@@), so the descriptors below take the AutoJoint member pointers as AutoJoint.cpp does for
// Part0 / Part1. Only the setter bodies are claimed here.
#include "v8datamodel/JointInstance.h"

static RBX::Reflection::PropDescriptor<RBX::AutoJoint, G3D::CoordinateFrame> prop_C1("C1", "Data", &RBX::AutoJoint::getC1, &RBX::AutoJoint::setC1, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::AutoJoint, G3D::CoordinateFrame> prop_C0("C0", "Data", &RBX::AutoJoint::getC0, &RBX::AutoJoint::setC0, RBX::Reflection::PropertyDescriptor::STANDARD);

namespace RBX
{
	// 005e4490
	void AutoJoint::setC0(const G3D::CoordinateFrame& value)
	{
		joint->setJointCoord(0, value);
		raisePropertyChanged(prop_C0);
	}

	// 005e44c0
	void AutoJoint::setC1(const G3D::CoordinateFrame& value)
	{
		joint->setJointCoord(1, value);
		raisePropertyChanged(prop_C1);
	}
}
