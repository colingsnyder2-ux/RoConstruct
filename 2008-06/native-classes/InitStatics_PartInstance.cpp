// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/engine-world
// 2008-06 v8datamodel/PartInstance.cpp reflection statics: dynamic initializer 007f48d0 (prop_RenderImportance;
// prop_Color 007f4630 now lives in PartInstanceProperties.cpp).  Names and arguments from the 2007 donor v8datamodel/PartInstance.cpp; the 2008 initializers
// pass the same strings, getter / setter pairs and flags 0.
#include "v8datamodel/PartInstance.h"
#include "reflection/reflection.h"
namespace RBX {
	const Reflection::PropDescriptor<PartInstance, float> PartInstance::prop_RenderImportance("RenderImportance", "Behavior", &PartInstance::getRenderImportance, &PartInstance::setRenderImportance, Reflection::PropertyDescriptor::LEGACY);   // 0097626c
	const Reflection::PropDescriptor<PartInstance, float> PartInstance::prop_Transparency("Transparency", "Appearance", &PartInstance::getTransparencyXml, &PartInstance::setTransparency, Reflection::PropertyDescriptor::STANDARD);   // 00976128 (init 007f46f0)
	const Reflection::PropDescriptor<PartInstance, float> PartInstance::prop_Reflectance("Reflectance", "Appearance", &PartInstance::getReflectance, &PartInstance::setReflectance, Reflection::PropertyDescriptor::STANDARD);   // 0097601c (init 007f4750)
	const Reflection::PropDescriptor<PartInstance, bool> PartInstance::prop_Locked("Locked", "Behavior", &PartInstance::getPartLocked, &PartInstance::setPartLocked, Reflection::PropertyDescriptor::STANDARD);   // 009760cc (init 007f47b0)
	// prop_Color 0097610c (initializer 007f4630) moved to PartInstanceProperties.cpp (batch 28), next to setColor 0059df40,
	// so its inline setColor3 COMDAT 0059e3d0 is emitted with setColor inlined.
}
