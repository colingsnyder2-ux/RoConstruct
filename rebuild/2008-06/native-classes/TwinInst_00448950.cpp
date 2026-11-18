// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00448950: explicit instantiation of the class the body at 00448950 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "CRenderSettings.h"
template class RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::ShadowMode>;
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::ShadowMode>::EnumPropDescriptor(char const*, char const*, CRenderSettings::ShadowMode (CRenderSettings::*)() const, void (CRenderSettings::*)(CRenderSettings::ShadowMode), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::ShadowMode>::EnumPropDescriptor(char const*, char const*, CRenderSettings::ShadowMode (CRenderSettings::*)() const, void (CRenderSettings::*)(CRenderSettings::ShadowMode const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::ShadowMode>::EnumPropDescriptor(char const*, char const*, CRenderSettings::ShadowMode (CRenderSettings::*)(), void (CRenderSettings::*)(CRenderSettings::ShadowMode), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::ShadowMode>::EnumPropDescriptor(char const*, char const*, CRenderSettings::ShadowMode (CRenderSettings::*)(), void (CRenderSettings::*)(CRenderSettings::ShadowMode const&), RBX::Reflection::PropertyDescriptor::Functionality);
