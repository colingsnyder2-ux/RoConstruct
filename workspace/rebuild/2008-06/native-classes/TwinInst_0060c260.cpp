// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 0060c260: explicit instantiation of the class the body at 0060c260 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8datamodel/Feature.h"
template class RBX::Reflection::EnumPropDescriptor<class RBX::Feature,enum RBX::Feature::InOut>;
template RBX::Reflection::EnumPropDescriptor<class RBX::Feature,enum RBX::Feature::InOut>::EnumPropDescriptor(char const*, char const*, RBX::Feature::InOut (RBX::Feature::*)() const, void (RBX::Feature::*)(RBX::Feature::InOut), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::Feature,enum RBX::Feature::InOut>::EnumPropDescriptor(char const*, char const*, RBX::Feature::InOut (RBX::Feature::*)() const, void (RBX::Feature::*)(RBX::Feature::InOut const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::Feature,enum RBX::Feature::InOut>::EnumPropDescriptor(char const*, char const*, RBX::Feature::InOut (RBX::Feature::*)(), void (RBX::Feature::*)(RBX::Feature::InOut), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::Feature,enum RBX::Feature::InOut>::EnumPropDescriptor(char const*, char const*, RBX::Feature::InOut (RBX::Feature::*)(), void (RBX::Feature::*)(RBX::Feature::InOut const&), RBX::Reflection::PropertyDescriptor::Functionality);
