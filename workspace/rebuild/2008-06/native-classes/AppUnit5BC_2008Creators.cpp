// 2008-06 native rows of the Creatable / FactoryProduct block 005c0a20..005c33ff and 005c3da0..005c3ecf inside the
// application range 005bc000..005c8000 (inactive). Verified by tests/record_native_app_unit5bc_2008.py. All headers are
// read-only here.
//
// The block is one run of compiler-emitted template instances, in the unit that also holds the class-registration
// constructor 005c3ca0 (it calls every Described<C>::classDescriptor() of the classes below) and ObjectValue. Each
// class has up to four bodies, in link order:
//   * boost::detail::shared_count(C*, Creatable<Instance>::Deleter) (131 B; counted by creatable-shared-count);
//   * boost::shared_ptr<C>(C*, Creatable<Instance>::Deleter) (171 B, the enable_shared_from_this hook-up);
//   * Creatable<Instance>::create<C>() (120 / 122 B: malloc(sizeof(C)), C(), shared_ptr<C>(p, Deleter()));
//   * FactoryProduct<C, D, N>::Creator::create() const (175 B, slot 0 of the Creator vtable 0083882c..00838aac):
//     calls Creatable<Instance>::create<C>() and returns it as shared_ptr<Object>.
// Classes in link order: ClickDetector, Explosion, FlagStand, FlagStandService, ForceField, GeometryService, BodyGyro,
// BodyForce, BodyThrust, BodyPosition, BodyVelocity, BodyAngularVelocity, Rocket, DebrisService, Seat, Sparkles, and
// ObjectValue (shared_ptr 005c2b90, create 005c3da0, Creator 005c3e20). The ForceField, GeometryService and
// DebrisService shared_ptr / create rows are counted by their own receipts; only their Creator rows are built here.
// sizeof(C) comes from the native headers and is checked by the malloc size each create<C> passes.
// >>> native-status (generated) -- do not edit >>>
// AppUnit5BC_2008Creators | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 59e1751d | roc native-status --write
#include "v8datamodel/ClickDetector.h"
#include "v8datamodel/Explosion.h"
#include "v8datamodel/FlagStand.h"
#include "v8datamodel/FlagStandService.h"
#include "v8datamodel/ForceField.h"
#include "v8datamodel/GeometryService.h"
#include "v8datamodel/BodyMovers.h"
#include "v8datamodel/Rocket.h"
#include "v8datamodel/Value.h"
#include "v8datamodel/DebrisService.h"
#include "v8datamodel/Seat.h"
#include "v8datamodel/Sparkles.h"
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

template boost::shared_ptr<RBX::ClickDetector> RBX::Creatable<RBX::Instance>::create<RBX::ClickDetector>();
template boost::shared_ptr<RBX::Explosion> RBX::Creatable<RBX::Instance>::create<RBX::Explosion>();
template boost::shared_ptr<RBX::FlagStand> RBX::Creatable<RBX::Instance>::create<RBX::FlagStand>();
template boost::shared_ptr<RBX::FlagStandService> RBX::Creatable<RBX::Instance>::create<RBX::FlagStandService>();
template boost::shared_ptr<RBX::BodyGyro> RBX::Creatable<RBX::Instance>::create<RBX::BodyGyro>();
template boost::shared_ptr<RBX::BodyForce> RBX::Creatable<RBX::Instance>::create<RBX::BodyForce>();
template boost::shared_ptr<RBX::BodyThrust> RBX::Creatable<RBX::Instance>::create<RBX::BodyThrust>();
template boost::shared_ptr<RBX::BodyPosition> RBX::Creatable<RBX::Instance>::create<RBX::BodyPosition>();
template boost::shared_ptr<RBX::BodyVelocity> RBX::Creatable<RBX::Instance>::create<RBX::BodyVelocity>();
template boost::shared_ptr<RBX::BodyAngularVelocity> RBX::Creatable<RBX::Instance>::create<RBX::BodyAngularVelocity>();
template boost::shared_ptr<RBX::Rocket> RBX::Creatable<RBX::Instance>::create<RBX::Rocket>();
template boost::shared_ptr<RBX::Seat> RBX::Creatable<RBX::Instance>::create<RBX::Seat>();
template boost::shared_ptr<RBX::Sparkles> RBX::Creatable<RBX::Instance>::create<RBX::Sparkles>();
template boost::shared_ptr<RBX::ObjectValue> RBX::Creatable<RBX::Instance>::create<RBX::ObjectValue>();

template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::ClickDetector, RBX::Instance, RBX::sClickDetector>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Explosion, RBX::Instance, RBX::sExplosion>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::FlagStand, RBX::PartInstance, RBX::sFlagStand>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::FlagStandService, RBX::Instance, RBX::sFlagStandService>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::ForceField, RBX::Instance, RBX::sForceField>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::GeometryService, RBX::Instance, RBX::sGeometryService>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::BodyGyro, RBX::BodyMover, RBX::sBodyGyro>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::BodyForce, RBX::BodyMover, RBX::sBodyForce>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::BodyThrust, RBX::BodyMover, RBX::sBodyThrust>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::BodyPosition, RBX::BodyMover, RBX::sBodyPosition>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::BodyVelocity, RBX::BodyMover, RBX::sBodyVelocity>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::BodyAngularVelocity, RBX::BodyMover, RBX::sBodyAngularVelocity>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Rocket, RBX::BodyMover, RBX::sRocket>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::DebrisService, RBX::Instance, RBX::sDebrisService>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Seat, RBX::PartInstance, RBX::sSeat>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Sparkles, RBX::Instance, RBX::sSparkles>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::ObjectValue, RBX::Instance, RBX::sObjectValue>::Creator::create() const;
