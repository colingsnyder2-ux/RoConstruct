// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00448a30: explicit instantiation of the class the body at 00448a30 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "CRenderSettings.h"
template class RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::AntialiasingMode>;
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::AntialiasingMode>::EnumPropDescriptor(char const*, char const*, CRenderSettings::AntialiasingMode (CRenderSettings::*)() const, void (CRenderSettings::*)(CRenderSettings::AntialiasingMode), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::AntialiasingMode>::EnumPropDescriptor(char const*, char const*, CRenderSettings::AntialiasingMode (CRenderSettings::*)() const, void (CRenderSettings::*)(CRenderSettings::AntialiasingMode const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::AntialiasingMode>::EnumPropDescriptor(char const*, char const*, CRenderSettings::AntialiasingMode (CRenderSettings::*)(), void (CRenderSettings::*)(CRenderSettings::AntialiasingMode), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::AntialiasingMode>::EnumPropDescriptor(char const*, char const*, CRenderSettings::AntialiasingMode (CRenderSettings::*)(), void (CRenderSettings::*)(CRenderSettings::AntialiasingMode const&), RBX::Reflection::PropertyDescriptor::Functionality);
