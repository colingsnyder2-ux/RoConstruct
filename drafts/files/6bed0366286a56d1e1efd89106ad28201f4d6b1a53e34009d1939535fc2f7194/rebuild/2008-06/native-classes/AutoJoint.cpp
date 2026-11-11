// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// >>> native-status (generated) -- do not edit >>>
// AutoJoint | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by auto
// <<< native-status | src fa909a5f | roc native-status --write
#include "v8datamodel/JointInstance.h"

static RBX::Reflection::RefPropDescriptor<RBX::AutoJoint, RBX::PartInstance> prop_Part0("Part0", "Data", &RBX::AutoJoint::getPart0, &RBX::AutoJoint::setPart0, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::RefPropDescriptor<RBX::AutoJoint, RBX::PartInstance> prop_Part1("Part1", "Data", &RBX::AutoJoint::getPart1, &RBX::AutoJoint::setPart1, RBX::Reflection::PropertyDescriptor::STANDARD);

namespace RBX {
void AutoJoint::setPart0(PartInstance* value)
	{
		setPart(0, value);
		raisePropertyChanged(prop_Part0);
	}

void AutoJoint::setPart1(PartInstance* value)
	{
		setPart(1, value);
		raisePropertyChanged(prop_Part1);
	}
}
