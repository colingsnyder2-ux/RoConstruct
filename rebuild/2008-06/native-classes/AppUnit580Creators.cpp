// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native rows of the Creatable / FactoryProduct template instances for the Feature.cpp classes (Hole,
// MotorFeature, VelocityMotor) that the StandardVerbs / command verbs translation unit (0057d250..005831ff) emits at
// the start of the application range 00580000..00584000, inactive. Verified by tests/record_native_app_unit580.py.
// Every header is a committed native header, read-only here.
//
// The rows (COMDAT run of the verbs unit, link order):
//   * FactoryProduct<MotorFeature, Feature, sMotorFeature>::Creator::create() const 00580040 (175 B; calls
//     Creatable<Instance>::create<MotorFeature> 0057ffc0);
//   * shared_ptr<Hole>(Hole*, Creatable<Instance>::Deleter) 00580180 (171 B; calls the shared_count instance 005800f0,
//     counted by creatable-shared-count), Creatable<Instance>::create<Hole>() 00580230 (120 B: new 0x150 =
//     sizeof(Hole), Hole() 0060c840) and FactoryProduct<Hole, Feature, sHole>::Creator::create() const 005802b0;
//   * shared_ptr<VelocityMotor>(VelocityMotor*, Deleter) 005803f0 (shared_count instance 00580360), create<VelocityMotor>
//     005804a0 (new 0x170 = sizeof(VelocityMotor), VelocityMotor() 0060bbb0) and the VelocityMotor Creator 00580520.
// v8datamodel/Feature.h declares the const char class-name arrays the RTTI names (3QBDB). The Creator::create
// definition is the one native-classes/AppUnit578_2008Creators.cpp uses for the declaration in util/Object.h.
#include "v8datamodel/Feature.h"
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

template boost::shared_ptr<RBX::Hole> RBX::Creatable<RBX::Instance>::create<RBX::Hole>();
template boost::shared_ptr<RBX::VelocityMotor> RBX::Creatable<RBX::Instance>::create<RBX::VelocityMotor>();

template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::MotorFeature, RBX::Feature, RBX::sMotorFeature>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Hole, RBX::Feature, RBX::sHole>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::VelocityMotor, RBX::JointInstance, RBX::sVelocityMotor>::Creator::create() const;
