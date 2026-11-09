// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_0a5160c3f82cced4.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#include "v8datamodel/PVInstance.h"
namespace RBX
{
	const char* sPVInstance = "PVInstance";

	static Reflection::PropDescriptor<PVInstance, G3D::CoordinateFrame> desc_CoordFrame("CoordinateFrame", "Data", NULL, &PVInstance::setPVGridOffsetLegacy, Reflection::PropertyDescriptor::LEGACY); // L23
	static Reflection::PropDescriptor<PVInstance, bool> prop_ControllerFlagShown("ControllerFlagShown", "Appearance", &PVInstance::getShowControllerFlag, &PVInstance::setShowControllerFlag, Reflection::PropertyDescriptor::STANDARD); // L32
	const Reflection::EnumPropDescriptor<PVInstance, Controller::ControllerType> PVInstance::prop_ControllerType("Controller", "Behavior", &PVInstance::getControllerType, &PVInstance::setControllerType, Reflection::PropertyDescriptor::STANDARD); // L34
}
