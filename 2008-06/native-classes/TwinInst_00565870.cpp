// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNATIVE_DEBUGSETTINGS_PENDING
// 00565870: explicit instantiation of the class the body at 00565870 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8datamodel/DebugSettings.h"
template class RBX::Reflection::EnumPropDescriptor<class RBX::DebugSettings,enum RBX::DebugSettings::ErrorReporting>;
template RBX::Reflection::EnumPropDescriptor<class RBX::DebugSettings,enum RBX::DebugSettings::ErrorReporting>::EnumPropDescriptor(char const*, char const*, RBX::DebugSettings::ErrorReporting (RBX::DebugSettings::*)() const, void (RBX::DebugSettings::*)(RBX::DebugSettings::ErrorReporting), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::DebugSettings,enum RBX::DebugSettings::ErrorReporting>::EnumPropDescriptor(char const*, char const*, RBX::DebugSettings::ErrorReporting (RBX::DebugSettings::*)() const, void (RBX::DebugSettings::*)(RBX::DebugSettings::ErrorReporting const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::DebugSettings,enum RBX::DebugSettings::ErrorReporting>::EnumPropDescriptor(char const*, char const*, RBX::DebugSettings::ErrorReporting (RBX::DebugSettings::*)(), void (RBX::DebugSettings::*)(RBX::DebugSettings::ErrorReporting), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::DebugSettings,enum RBX::DebugSettings::ErrorReporting>::EnumPropDescriptor(char const*, char const*, RBX::DebugSettings::ErrorReporting (RBX::DebugSettings::*)(), void (RBX::DebugSettings::*)(RBX::DebugSettings::ErrorReporting const&), RBX::Reflection::PropertyDescriptor::Functionality);
