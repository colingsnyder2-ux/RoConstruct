// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/engine-world
// 2008-06 v8datamodel/PartInstance.cpp reflection statics: dynamic initializers 007f48d0 (prop_RenderImportance) and
// 007f4630 (prop_Color).  Names and arguments from the 2007 donor v8datamodel/PartInstance.cpp; the 2008 initializers
// pass the same strings, getter / setter pairs and flags 0.
#include "v8datamodel/PartInstance.h"
#include "reflection/reflection.h"
namespace RBX {
	const Reflection::PropDescriptor<PartInstance, float> PartInstance::prop_RenderImportance("RenderImportance", "Behavior", &PartInstance::getRenderImportance, &PartInstance::setRenderImportance, Reflection::PropertyDescriptor::LEGACY);   // 0097626c
	const Reflection::PropDescriptor<PartInstance, G3D::Color3> PartInstance::prop_Color("Color", "Appearance", &PartInstance::getColor3, &PartInstance::setColor3, Reflection::PropertyDescriptor::LEGACY);   // 0097610c
}
