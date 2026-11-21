// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/pv-parent
// 00609590: explicit instantiation of the class the body at 00609590 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8datamodel/PVInstance.h"
template class RBX::Reflection::EnumPropDescriptor<class RBX::PVInstance,enum RBX::Controller::ControllerType>;
template RBX::Reflection::EnumPropDescriptor<class RBX::PVInstance,enum RBX::Controller::ControllerType>::EnumPropDescriptor(char const*, char const*, RBX::Controller::ControllerType (RBX::PVInstance::*)() const, void (RBX::PVInstance::*)(RBX::Controller::ControllerType), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::PVInstance,enum RBX::Controller::ControllerType>::EnumPropDescriptor(char const*, char const*, RBX::Controller::ControllerType (RBX::PVInstance::*)() const, void (RBX::PVInstance::*)(RBX::Controller::ControllerType const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::PVInstance,enum RBX::Controller::ControllerType>::EnumPropDescriptor(char const*, char const*, RBX::Controller::ControllerType (RBX::PVInstance::*)(), void (RBX::PVInstance::*)(RBX::Controller::ControllerType), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::PVInstance,enum RBX::Controller::ControllerType>::EnumPropDescriptor(char const*, char const*, RBX::Controller::ControllerType (RBX::PVInstance::*)(), void (RBX::PVInstance::*)(RBX::Controller::ControllerType const&), RBX::Reflection::PropertyDescriptor::Functionality);
