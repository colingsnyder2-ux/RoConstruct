// 2008-06 native rows of the joint-creator block 004b21c0..004b337f inside the application range 004b0000..004bc000
// (inactive). Verified by tests/record_native_app_unit4b0_2008.py. All headers are read-only here.
//
// The block is one run of compiler-emitted template instances, in the order Lighting, Snap, Weld, Glue, Rotate,
// RotateP, RotateV, Motor. Each class has four bodies:
//   * FactoryProduct<C, D, N>::Creator::create() const (175 B, slot 0 of the Creator vtable): calls
//     Creatable<Instance>::create<C>() and returns it as shared_ptr<Object>;
//   * boost::detail::shared_count(C*, Creatable<Instance>::Deleter) (131 B; counted by creatable-shared-count);
//   * boost::shared_ptr<C>(C*, Creatable<Instance>::Deleter) (171 B, the enable_shared_from_this hook-up);
//   * Creatable<Instance>::create<C>() (120 B: malloc(sizeof(C)), C(), shared_ptr<C>(p, Deleter())).
// Lighting's create<Lighting> 004adb60 and its shared_ptr / shared_count sit below the range (lighting2008).
// sizeof(C) comes from the native v8datamodel/JointInstance.h: malloc 0x154 in create<Weld> 004b2620 and the
// other create<C> rows.
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/Lighting2008.h"
#include "util/Object.h"

namespace RBX
{
	// util/Object.h declares Creator::create() only; this is the definition every Creator vtable slot 0 reaches.
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}
}

template boost::shared_ptr<RBX::Weld> RBX::Creatable<RBX::Instance>::create<RBX::Weld>();
template boost::shared_ptr<RBX::Glue> RBX::Creatable<RBX::Instance>::create<RBX::Glue>();
template boost::shared_ptr<RBX::Rotate> RBX::Creatable<RBX::Instance>::create<RBX::Rotate>();
template boost::shared_ptr<RBX::RotateP> RBX::Creatable<RBX::Instance>::create<RBX::RotateP>();
template boost::shared_ptr<RBX::RotateV> RBX::Creatable<RBX::Instance>::create<RBX::RotateV>();

template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Lighting, RBX::Instance, RBX::sLighting>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Snap, RBX::AutoJoint, RBX::sSnap>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Weld, RBX::AutoJoint, RBX::sWeld>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Glue, RBX::AutoJoint, RBX::sGlue>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Rotate, RBX::AutoJoint, RBX::sRotate>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::RotateP, RBX::AutoJoint, RBX::sRotateP>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::RotateV, RBX::AutoJoint, RBX::sRotateV>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Motor, RBX::AutoJoint, RBX::sMotor>::Creator::create() const;
