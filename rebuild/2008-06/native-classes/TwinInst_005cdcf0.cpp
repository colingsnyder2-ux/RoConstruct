// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 005cdcf0: explicit instantiation of the class the body at 005cdcf0 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8datamodel/Camera.h"
template class RBX::Reflection::EnumPropDescriptor<class RBX::Camera,enum RBX::Camera::CameraType>;
template RBX::Reflection::EnumPropDescriptor<class RBX::Camera,enum RBX::Camera::CameraType>::EnumPropDescriptor(char const*, char const*, RBX::Camera::CameraType (RBX::Camera::*)() const, void (RBX::Camera::*)(RBX::Camera::CameraType), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::Camera,enum RBX::Camera::CameraType>::EnumPropDescriptor(char const*, char const*, RBX::Camera::CameraType (RBX::Camera::*)() const, void (RBX::Camera::*)(RBX::Camera::CameraType const&), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::Camera,enum RBX::Camera::CameraType>::EnumPropDescriptor(char const*, char const*, RBX::Camera::CameraType (RBX::Camera::*)(), void (RBX::Camera::*)(RBX::Camera::CameraType), RBX::Reflection::PropertyDescriptor::Functionality);
template RBX::Reflection::EnumPropDescriptor<class RBX::Camera,enum RBX::Camera::CameraType>::EnumPropDescriptor(char const*, char const*, RBX::Camera::CameraType (RBX::Camera::*)(), void (RBX::Camera::*)(RBX::Camera::CameraType const&), RBX::Reflection::PropertyDescriptor::Functionality);
