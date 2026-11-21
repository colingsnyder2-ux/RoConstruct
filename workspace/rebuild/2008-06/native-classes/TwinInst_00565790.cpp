// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNATIVE_DEBUGSETTINGS_PENDING
// 00565790: explicit instantiation of the class the body at 00565790 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8datamodel/DebugSettings.h"
template class RBX::Reflection::EnumPropDescriptor<class RBX::DebugSettings,enum RBX::Debugable::AssertAction>;
template RBX::Reflection::EnumPropDescriptor<class RBX::DebugSettings,enum RBX::Debugable::AssertAction>::EnumPropDescriptor(char const*, char const*, RBX::Debugable::AssertAction (RBX::DebugSettings::*)() const, void (RBX::DebugSettings::*)(RBX::Debugable::AssertAction), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::DebugSettings,enum RBX::Debugable::AssertAction>::EnumPropDescriptor(char const*, char const*, RBX::Debugable::AssertAction (RBX::DebugSettings::*)() const, void (RBX::DebugSettings::*)(RBX::Debugable::AssertAction const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::DebugSettings,enum RBX::Debugable::AssertAction>::EnumPropDescriptor(char const*, char const*, RBX::Debugable::AssertAction (RBX::DebugSettings::*)(), void (RBX::DebugSettings::*)(RBX::Debugable::AssertAction), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::DebugSettings,enum RBX::Debugable::AssertAction>::EnumPropDescriptor(char const*, char const*, RBX::Debugable::AssertAction (RBX::DebugSettings::*)(), void (RBX::DebugSettings::*)(RBX::Debugable::AssertAction const&), RBX::Reflection::PropertyDescriptor::Functionality);
