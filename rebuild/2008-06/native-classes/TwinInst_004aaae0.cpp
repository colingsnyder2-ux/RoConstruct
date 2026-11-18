// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 004aaae0: explicit instantiation of the class the body at 004aaae0 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "Network/NetworkSettings.h"
template class RBX::Reflection::EnumPropDescriptor<class RBX::NetworkSettings,enum RBX::NetworkSettings::PhysicsReceiveMethod>;
template RBX::Reflection::EnumPropDescriptor<class RBX::NetworkSettings,enum RBX::NetworkSettings::PhysicsReceiveMethod>::EnumPropDescriptor(char const*, char const*, RBX::NetworkSettings::PhysicsReceiveMethod (RBX::NetworkSettings::*)() const, void (RBX::NetworkSettings::*)(RBX::NetworkSettings::PhysicsReceiveMethod), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::NetworkSettings,enum RBX::NetworkSettings::PhysicsReceiveMethod>::EnumPropDescriptor(char const*, char const*, RBX::NetworkSettings::PhysicsReceiveMethod (RBX::NetworkSettings::*)() const, void (RBX::NetworkSettings::*)(RBX::NetworkSettings::PhysicsReceiveMethod const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::NetworkSettings,enum RBX::NetworkSettings::PhysicsReceiveMethod>::EnumPropDescriptor(char const*, char const*, RBX::NetworkSettings::PhysicsReceiveMethod (RBX::NetworkSettings::*)(), void (RBX::NetworkSettings::*)(RBX::NetworkSettings::PhysicsReceiveMethod), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::NetworkSettings,enum RBX::NetworkSettings::PhysicsReceiveMethod>::EnumPropDescriptor(char const*, char const*, RBX::NetworkSettings::PhysicsReceiveMethod (RBX::NetworkSettings::*)(), void (RBX::NetworkSettings::*)(RBX::NetworkSettings::PhysicsReceiveMethod const&), RBX::Reflection::PropertyDescriptor::Functionality);
