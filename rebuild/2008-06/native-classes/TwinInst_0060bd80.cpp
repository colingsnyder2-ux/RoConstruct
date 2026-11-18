// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 0060bd80: explicit instantiation of the class the body at 0060bd80 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8datamodel/Feature.h"
template class RBX::Reflection::EnumPropDescriptor<class RBX::Feature,enum RBX::NormalId>;
template RBX::Reflection::EnumPropDescriptor<class RBX::Feature,enum RBX::NormalId>::EnumPropDescriptor(char const*, char const*, RBX::NormalId (RBX::Feature::*)() const, void (RBX::Feature::*)(RBX::NormalId), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::Feature,enum RBX::NormalId>::EnumPropDescriptor(char const*, char const*, RBX::NormalId (RBX::Feature::*)() const, void (RBX::Feature::*)(RBX::NormalId const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::Feature,enum RBX::NormalId>::EnumPropDescriptor(char const*, char const*, RBX::NormalId (RBX::Feature::*)(), void (RBX::Feature::*)(RBX::NormalId), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::Feature,enum RBX::NormalId>::EnumPropDescriptor(char const*, char const*, RBX::NormalId (RBX::Feature::*)(), void (RBX::Feature::*)(RBX::NormalId const&), RBX::Reflection::PropertyDescriptor::Functionality);
