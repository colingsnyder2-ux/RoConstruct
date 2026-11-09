// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_unit_ad65837665067cec.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8datamodel/JointInstance.h", "roc_unit_ffc89e90dbae649c.cpp")
#undef _RELEASEASSERT
#include "v8datamodel/JointInstance.h"
#include "v8world/Joint.h"
namespace RBX {
	JointInstance::JointInstance(Joint* joint) 
	: joint(joint)
{
	joint->setJointOwner(this);

	PartInstance* p0 = PartInstance::fromPrimitive(joint->getPrimitive(0));
	PartInstance* p1 = PartInstance::fromPrimitive(joint->getPrimitive(1));
	part[0] = shared_from<PartInstance>(p0);
	part[1] = shared_from<PartInstance>(p1);
}
}
