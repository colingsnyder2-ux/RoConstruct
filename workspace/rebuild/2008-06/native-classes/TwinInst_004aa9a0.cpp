// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 004aa9a0: explicit instantiation of the class the body at 004aa9a0 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "Network/NetworkSettings.h"
template class RBX::Reflection::EnumPropDescriptor<class RBX::NetworkSettings,enum RBX::NetworkSettings::PhysicsSendMethod>;
template RBX::Reflection::EnumPropDescriptor<class RBX::NetworkSettings,enum RBX::NetworkSettings::PhysicsSendMethod>::EnumPropDescriptor(char const*, char const*, RBX::NetworkSettings::PhysicsSendMethod (RBX::NetworkSettings::*)() const, void (RBX::NetworkSettings::*)(RBX::NetworkSettings::PhysicsSendMethod), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::NetworkSettings,enum RBX::NetworkSettings::PhysicsSendMethod>::EnumPropDescriptor(char const*, char const*, RBX::NetworkSettings::PhysicsSendMethod (RBX::NetworkSettings::*)() const, void (RBX::NetworkSettings::*)(RBX::NetworkSettings::PhysicsSendMethod const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::NetworkSettings,enum RBX::NetworkSettings::PhysicsSendMethod>::EnumPropDescriptor(char const*, char const*, RBX::NetworkSettings::PhysicsSendMethod (RBX::NetworkSettings::*)(), void (RBX::NetworkSettings::*)(RBX::NetworkSettings::PhysicsSendMethod), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::NetworkSettings,enum RBX::NetworkSettings::PhysicsSendMethod>::EnumPropDescriptor(char const*, char const*, RBX::NetworkSettings::PhysicsSendMethod (RBX::NetworkSettings::*)(), void (RBX::NetworkSettings::*)(RBX::NetworkSettings::PhysicsSendMethod const&), RBX::Reflection::PropertyDescriptor::Functionality);
