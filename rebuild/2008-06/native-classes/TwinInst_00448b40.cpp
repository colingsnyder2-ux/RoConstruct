// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00448b40: explicit instantiation of the class the body at 00448b40 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "CRenderSettings.h"
template class RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::AASamples>;
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::AASamples>::EnumPropDescriptor(char const*, char const*, CRenderSettings::AASamples (CRenderSettings::*)() const, void (CRenderSettings::*)(CRenderSettings::AASamples), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::AASamples>::EnumPropDescriptor(char const*, char const*, CRenderSettings::AASamples (CRenderSettings::*)() const, void (CRenderSettings::*)(CRenderSettings::AASamples const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::AASamples>::EnumPropDescriptor(char const*, char const*, CRenderSettings::AASamples (CRenderSettings::*)(), void (CRenderSettings::*)(CRenderSettings::AASamples), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::AASamples>::EnumPropDescriptor(char const*, char const*, CRenderSettings::AASamples (CRenderSettings::*)(), void (CRenderSettings::*)(CRenderSettings::AASamples const&), RBX::Reflection::PropertyDescriptor::Functionality);
