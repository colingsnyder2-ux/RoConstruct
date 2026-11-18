// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0059d390: explicit instantiation of the class the body at 0059d390 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8datamodel/PartInstance.h"
template class RBX::Reflection::EnumPropDescriptor<class RBX::PartInstance,enum RBX::PartInstance::FormFactor>;
template RBX::Reflection::EnumPropDescriptor<class RBX::PartInstance,enum RBX::PartInstance::FormFactor>::EnumPropDescriptor(char const*, char const*, RBX::PartInstance::FormFactor (RBX::PartInstance::*)() const, void (RBX::PartInstance::*)(RBX::PartInstance::FormFactor), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::PartInstance,enum RBX::PartInstance::FormFactor>::EnumPropDescriptor(char const*, char const*, RBX::PartInstance::FormFactor (RBX::PartInstance::*)() const, void (RBX::PartInstance::*)(RBX::PartInstance::FormFactor const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::PartInstance,enum RBX::PartInstance::FormFactor>::EnumPropDescriptor(char const*, char const*, RBX::PartInstance::FormFactor (RBX::PartInstance::*)(), void (RBX::PartInstance::*)(RBX::PartInstance::FormFactor), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::PartInstance,enum RBX::PartInstance::FormFactor>::EnumPropDescriptor(char const*, char const*, RBX::PartInstance::FormFactor (RBX::PartInstance::*)(), void (RBX::PartInstance::*)(RBX::PartInstance::FormFactor const&), RBX::Reflection::PropertyDescriptor::Functionality);
