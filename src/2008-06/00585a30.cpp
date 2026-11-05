// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_cd777c9aaa53f273.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_unit_cc3dd87ed7e7c246.cpp")
#pragma include_alias("v8datamodel/JointInstance.h", "roc_unit_ffc89e90dbae649c.cpp")
#pragma include_alias("v8datamodel/Gyro.h", "roc_unit_49d5cd98eaed3b87.cpp")
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#include "v8datamodel/ModelInstance.h"
namespace RBX
{
	const char* sModel = "Model";

	static const Name& partName = Name::declare(sModel, 2000);

	static Reflection::PropDescriptor<ModelInstance, G3D::CoordinateFrame> desc_ModelInPrimary("ModelInPrimary", "Data", &ModelInstance::getModelInPrimary, &ModelInstance::setModelInPrimary, Reflection::PropertyDescriptor::STREAMING); // L25
	static Reflection::RefPropDescriptor<ModelInstance, PartInstance> primaryPartProp("PrimaryPart", "Data", &ModelInstance::getPrimaryPartInternal, &ModelInstance::setPrimaryPart, Reflection::PropertyDescriptor::STANDARD); // L26
	static Reflection::BoundFuncDesc<ModelInstance, void(), 0> desc_breakJoints(&ModelInstance::breakJoints, "BreakJoints", Reflection::FunctionDescriptor::AnyCaller); // L27
	static Reflection::BoundFuncDesc<ModelInstance, void(), 0> desc_makeJoints(&ModelInstance::makeJoints, "MakeJoints", Reflection::FunctionDescriptor::AnyCaller); // L28

	static Reflection::BoundFuncDesc<ModelInstance, void(G3D::Vector3), 1> model_moveFunctionOld(&PVInstance::moveToPoint, "move", "location", Reflection::FunctionDescriptor::AnyCaller); // L30
	static Reflection::BoundFuncDesc<ModelInstance, void(G3D::Vector3), 1> model_moveFunction(&PVInstance::moveToPoint, "MoveTo", "location", Reflection::FunctionDescriptor::AnyCaller); // L31

	bool ModelInstance::showModelCoord = false;
}
