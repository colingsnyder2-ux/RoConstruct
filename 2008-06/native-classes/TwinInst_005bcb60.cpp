// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 005bcb60: explicit instantiation of the class the body at 005bcb60 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "util/Sound.h"
template class RBX::Reflection::EnumPropDescriptor<class RBX::Soundscape::SoundService,enum RBX::Soundscape::ReverbType>;
template RBX::Reflection::EnumPropDescriptor<class RBX::Soundscape::SoundService,enum RBX::Soundscape::ReverbType>::EnumPropDescriptor(char const*, char const*, RBX::Soundscape::ReverbType (RBX::Soundscape::SoundService::*)() const, void (RBX::Soundscape::SoundService::*)(RBX::Soundscape::ReverbType), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::Soundscape::SoundService,enum RBX::Soundscape::ReverbType>::EnumPropDescriptor(char const*, char const*, RBX::Soundscape::ReverbType (RBX::Soundscape::SoundService::*)() const, void (RBX::Soundscape::SoundService::*)(RBX::Soundscape::ReverbType const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::Soundscape::SoundService,enum RBX::Soundscape::ReverbType>::EnumPropDescriptor(char const*, char const*, RBX::Soundscape::ReverbType (RBX::Soundscape::SoundService::*)(), void (RBX::Soundscape::SoundService::*)(RBX::Soundscape::ReverbType), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::Soundscape::SoundService,enum RBX::Soundscape::ReverbType>::EnumPropDescriptor(char const*, char const*, RBX::Soundscape::ReverbType (RBX::Soundscape::SoundService::*)(), void (RBX::Soundscape::SoundService::*)(RBX::Soundscape::ReverbType const&), RBX::Reflection::PropertyDescriptor::Functionality);
