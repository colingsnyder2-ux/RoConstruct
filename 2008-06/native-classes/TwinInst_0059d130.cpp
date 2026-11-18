// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 0059d130: explicit instantiation of the class the body at 0059d130 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "ViewNew/PartChunk.h"
#include "v8datamodel/PartInstance.h"
#include "reflection/reflection.h"
#include "reflection/Metadata.h"
template class RBX::Reflection::EnumPropDescriptor<class RBX::PartInstance,enum RBX::Part::PartType>;
template RBX::Reflection::EnumPropDescriptor<class RBX::PartInstance,enum RBX::Part::PartType>::EnumPropDescriptor(char const*, char const*, RBX::Part::PartType (RBX::PartInstance::*)() const, void (RBX::PartInstance::*)(RBX::Part::PartType), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::PartInstance,enum RBX::Part::PartType>::EnumPropDescriptor(char const*, char const*, RBX::Part::PartType (RBX::PartInstance::*)() const, void (RBX::PartInstance::*)(RBX::Part::PartType const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::PartInstance,enum RBX::Part::PartType>::EnumPropDescriptor(char const*, char const*, RBX::Part::PartType (RBX::PartInstance::*)(), void (RBX::PartInstance::*)(RBX::Part::PartType), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::PartInstance,enum RBX::Part::PartType>::EnumPropDescriptor(char const*, char const*, RBX::Part::PartType (RBX::PartInstance::*)(), void (RBX::PartInstance::*)(RBX::Part::PartType const&), RBX::Reflection::PropertyDescriptor::Functionality);
