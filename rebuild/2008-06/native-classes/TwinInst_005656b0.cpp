// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 005656b0: explicit instantiation of the class the body at 005656b0 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8datamodel/DebugSettings.h"
#include "v8world/World2008.h"
template class RBX::Reflection::EnumPropDescriptor<class RBX::DebugSettings,enum RBX::World::EThrottle>;
template RBX::Reflection::EnumPropDescriptor<class RBX::DebugSettings,enum RBX::World::EThrottle>::EnumPropDescriptor(char const*, char const*, RBX::World::EThrottle (RBX::DebugSettings::*)() const, void (RBX::DebugSettings::*)(RBX::World::EThrottle), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::DebugSettings,enum RBX::World::EThrottle>::EnumPropDescriptor(char const*, char const*, RBX::World::EThrottle (RBX::DebugSettings::*)() const, void (RBX::DebugSettings::*)(RBX::World::EThrottle const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::DebugSettings,enum RBX::World::EThrottle>::EnumPropDescriptor(char const*, char const*, RBX::World::EThrottle (RBX::DebugSettings::*)(), void (RBX::DebugSettings::*)(RBX::World::EThrottle), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::DebugSettings,enum RBX::World::EThrottle>::EnumPropDescriptor(char const*, char const*, RBX::World::EThrottle (RBX::DebugSettings::*)(), void (RBX::DebugSettings::*)(RBX::World::EThrottle const&), RBX::Reflection::PropertyDescriptor::Functionality);
