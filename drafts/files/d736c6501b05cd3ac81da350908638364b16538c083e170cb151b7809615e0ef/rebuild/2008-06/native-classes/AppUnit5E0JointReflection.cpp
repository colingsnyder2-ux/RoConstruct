// 2008-06 native rows of the v8datamodel/JointInstance.cpp unit inside the application range 005e0000..005e4000
// (inactive). Verified by tests/record_native_app_unit5e0.py (receipt app-unit5e0-working.json). Built against the
// committed native v8datamodel/JointInstance.h and reflection/*.h, all read-only.
//
// Only the property getset factories are built: their bodies and symbols depend on the member-pointer types alone,
// which the GetSetImpl RTTI names (vtables 0083e280 / 0083e294 / 0083e2a8):
//   PropDescriptor<JointInstance, PartInstance*>  PartInstance* () const, void (PartInstance*)   005e2920
//       (called by the RefPropDescriptor<JointInstance, PartInstance> constructor 005e3540)
//   PropDescriptor<JointInstance, CoordinateFrame> const CoordinateFrame& () const, void (const CoordinateFrame&)
//       005e2970 (called by the PropDescriptor constructor 005e3630)
//   PropDescriptor<Motor, float>                  float () const, void (float)                  005e29c0
//       (called by the PropDescriptor constructor 005e36e0)
// JointInstance has non-virtual multiple inheritance (IRenderable +0x130, IJointOwner +0x140), so the member pointers
// are 8 bytes (new(0x18), stores at +8..+0x14). The descriptor constructors, the JointInstance members and the joint
// classes are not built: in 2008 Snap .. Motor derive from DescribedCreatable<C, JointInstance, sC> and the class
// names are const char arrays (RTTI $1?sWeld@2@3QBDB, vtable 0083f24c), which the native JointInstance.h does not
// declare (proposal in the receipt).
#include "v8datamodel/JointInstance.h"

namespace R = RBX::Reflection;

template std::auto_ptr<R::TypedPropertyDescriptor<RBX::PartInstance*>::GetSet>
R::PropDescriptor<RBX::JointInstance, RBX::PartInstance*>::getset(
	RBX::PartInstance* (RBX::JointInstance::*)() const, void (RBX::JointInstance::*)(RBX::PartInstance*));
template std::auto_ptr<R::TypedPropertyDescriptor<G3D::CoordinateFrame>::GetSet>
R::PropDescriptor<RBX::JointInstance, G3D::CoordinateFrame>::getset(
	const G3D::CoordinateFrame& (RBX::JointInstance::*)() const, void (RBX::JointInstance::*)(const G3D::CoordinateFrame&));
template std::auto_ptr<R::TypedPropertyDescriptor<float>::GetSet>
R::PropDescriptor<RBX::Motor, float>::getset(float (RBX::Motor::*)() const, void (RBX::Motor::*)(float));
