// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005ef690: explicit instantiation of the class the body at 005ef690 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8datamodel/FaceInstance.h"
template class RBX::Reflection::EnumPropDescriptor<class RBX::FaceInstance,enum RBX::NormalId>;
template RBX::Reflection::EnumPropDescriptor<class RBX::FaceInstance,enum RBX::NormalId>::EnumPropDescriptor(char const*, char const*, RBX::NormalId (RBX::FaceInstance::*)() const, void (RBX::FaceInstance::*)(RBX::NormalId), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::FaceInstance,enum RBX::NormalId>::EnumPropDescriptor(char const*, char const*, RBX::NormalId (RBX::FaceInstance::*)() const, void (RBX::FaceInstance::*)(RBX::NormalId const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::FaceInstance,enum RBX::NormalId>::EnumPropDescriptor(char const*, char const*, RBX::NormalId (RBX::FaceInstance::*)(), void (RBX::FaceInstance::*)(RBX::NormalId), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::FaceInstance,enum RBX::NormalId>::EnumPropDescriptor(char const*, char const*, RBX::NormalId (RBX::FaceInstance::*)(), void (RBX::FaceInstance::*)(RBX::NormalId const&), RBX::Reflection::PropertyDescriptor::Functionality);
