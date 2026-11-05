// from server: 100% by colin
// from server: 98% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_unit_d25716957c544124.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_unit_cc3dd87ed7e7c246.cpp")
#pragma include_alias("v8datamodel/JointInstance.h", "roc_unit_ffc89e90dbae649c.cpp")
#pragma include_alias("v8datamodel/Gyro.h", "roc_unit_49d5cd98eaed3b87.cpp")
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#include "humanoid/Humanoid.h"
namespace RBX {
	Reflection::PropDescriptor<Humanoid, G3D::Vector3> propWalkToPoint("WalkToPoint", "Control", &Humanoid::getWalkToPoint, &Humanoid::setWalkToPoint, Reflection::PropertyDescriptor::STREAMING);
	Reflection::PropDescriptor<Humanoid, G3D::Vector3> propWalkDirection("WalkDirection", "Control", &Humanoid::getWalkDirection, &Humanoid::setWalkDirection, Reflection::PropertyDescriptor::STREAMING);
	Reflection::PropDescriptor<Humanoid, float> propWalkRotationalVelocity("WalkRotationalVelocity", "Control", &Humanoid::getWalkRotationalVelocity, &Humanoid::setWalkRotationalVelocity, Reflection::PropertyDescriptor::STREAMING);
	Reflection::PropDescriptor<Humanoid, bool> propJump("Jump", "Control", &Humanoid::getJump, &Humanoid::setJump, Reflection::PropertyDescriptor::STREAMING);
	Reflection::PropDescriptor<Humanoid, G3D::Vector3> propTargetPoint("TargetPoint", "Control", &Humanoid::getTargetPoint, &Humanoid::setTargetPoint, Reflection::PropertyDescriptor::STREAMING);
	Reflection::PropDescriptor<Humanoid, bool> propSit("Sit", "Control", &Humanoid::getSit, &Humanoid::setSit, Reflection::PropertyDescriptor::STREAMING);
	Reflection::BoundFuncDesc<Humanoid, void(G3D::Vector3, boost::shared_ptr<Instance>), 2> func_MoveTo(&Humanoid::moveTo2, "MoveTo", "location", "part", Reflection::FunctionDescriptor::AnyCaller);
	Reflection::RefPropDescriptor<Humanoid, PartInstance> propTorso("Torso", "Data", &Humanoid::getTorso, &Humanoid::setTorso, Reflection::PropertyDescriptor::UI);
	Reflection::RefPropDescriptor<Humanoid, PartInstance> propLeftLeg("LeftLeg", "Data", &Humanoid::getLeftLeg, &Humanoid::setLeftLeg, Reflection::PropertyDescriptor::UI);
	Reflection::RefPropDescriptor<Humanoid, PartInstance> propRightLeg("RightLeg", "Data", &Humanoid::getRightLeg, &Humanoid::setRightLeg, Reflection::PropertyDescriptor::UI);
	Reflection::RefPropDescriptor<Humanoid, PartInstance> propWalkToPart("WalkToPart", "Control", &Humanoid::getWalkToPart, &Humanoid::setWalkToPart, Reflection::PropertyDescriptor::STREAMING);
}
