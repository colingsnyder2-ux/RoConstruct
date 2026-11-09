// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_partprops_aug2007_c6b3a87f2d1f942f.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/PartInstance.h"
namespace RBX {
extern const char* category_Part;
const Reflection::PropDescriptor<PartInstance, G3D::CoordinateFrame> PartInstance::prop_CFrame("CFrame", "Data", &PartInstance::getCoordinateFrame, &PartInstance::setCoordinateFrame, Reflection::PropertyDescriptor::STANDARD);
const Reflection::EnumPropDescriptor<PartInstance, Part::PartType> PartInstance::prop_shapeXml("shape", category_Part, &PartInstance::getPartType, &PartInstance::setPartTypeXml, Reflection::PropertyDescriptor::STREAMING);
const Reflection::PropDescriptor<PartInstance, G3D::Vector3> PartInstance::prop_Size("size", category_Part, &PartInstance::getPartSizeXml, &PartInstance::setPartSizeXml, Reflection::PropertyDescriptor::STREAMING);
}
