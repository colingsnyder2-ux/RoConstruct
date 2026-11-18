// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00448660: explicit instantiation of the class the body at 00448660 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "CRenderSettings.h"
template class RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::BevelMode>;
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::BevelMode>::EnumPropDescriptor(char const*, char const*, CRenderSettings::BevelMode (CRenderSettings::*)() const, void (CRenderSettings::*)(CRenderSettings::BevelMode), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::BevelMode>::EnumPropDescriptor(char const*, char const*, CRenderSettings::BevelMode (CRenderSettings::*)() const, void (CRenderSettings::*)(CRenderSettings::BevelMode const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::BevelMode>::EnumPropDescriptor(char const*, char const*, CRenderSettings::BevelMode (CRenderSettings::*)(), void (CRenderSettings::*)(CRenderSettings::BevelMode), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::BevelMode>::EnumPropDescriptor(char const*, char const*, CRenderSettings::BevelMode (CRenderSettings::*)(), void (CRenderSettings::*)(CRenderSettings::BevelMode const&), RBX::Reflection::PropertyDescriptor::Functionality);
