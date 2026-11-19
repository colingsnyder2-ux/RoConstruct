// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00448220: explicit instantiation of the class the body at 00448220 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "CRenderSettings.h"
template class RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::GraphicsMode>;
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::GraphicsMode>::EnumPropDescriptor(char const*, char const*, CRenderSettings::GraphicsMode (CRenderSettings::*)() const, void (CRenderSettings::*)(CRenderSettings::GraphicsMode), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::GraphicsMode>::EnumPropDescriptor(char const*, char const*, CRenderSettings::GraphicsMode (CRenderSettings::*)() const, void (CRenderSettings::*)(CRenderSettings::GraphicsMode const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::GraphicsMode>::EnumPropDescriptor(char const*, char const*, CRenderSettings::GraphicsMode (CRenderSettings::*)(), void (CRenderSettings::*)(CRenderSettings::GraphicsMode), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class CRenderSettings,enum CRenderSettings::GraphicsMode>::EnumPropDescriptor(char const*, char const*, CRenderSettings::GraphicsMode (CRenderSettings::*)(), void (CRenderSettings::*)(CRenderSettings::GraphicsMode const&), RBX::Reflection::PropertyDescriptor::Functionality);
