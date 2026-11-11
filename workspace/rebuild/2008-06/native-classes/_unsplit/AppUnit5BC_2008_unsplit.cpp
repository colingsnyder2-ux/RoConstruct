// UNSPLIT CANDIDATE (2026-11-08): AppUnit5BC_2008 family
// Originals preserved; review before promotion.

// ---- BEGIN AppUnit5BC_2008Creators.cpp ----
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
// AppUnit5BC_2008_unsplit | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 1cf37091 | roc native-status --write
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
// ---- END AppUnit5BC_2008Creators.cpp ----

// ---- BEGIN AppUnit5BC_2008Descriptors.cpp ----
// 2008-06 native class-name and class-descriptor template instances of the class-registration block 005bf800..005c09ff
// inside the application range 005bc000..005c8000 (inactive). Verified by tests/record_native_app_unit5bc_2008.py.
// All headers are read-only here.
//
// The block is the COMDAT run of the unit that holds the class-registration constructor 005c3ca0 (it calls every
// Described<C>::classDescriptor() below) and the Name static initializers 007f5650..007f5b50:
//   * Name::doDeclare<sC>() (101 B, `static const Name& n = declare(sC, -1)`) and Name::callDoDeclare<sC>() (5 B, a
//     tail jump), both inline in native util/Name.h, instantiated here through Name::declare<sC>();
//   * Reflection::Described<C, sC, B>::classDescriptor() (101 B, `static ClassDescriptor foo(B::classDescriptor(), sC)`),
//     inline in native reflection/reflection.h.
// Built here: the Explosion, FlagStandService and ObjectValue names and the Explosion, FlagStandService, Visit,
// JointInstance and ObjectValue descriptors (the other rows of the block are counted by the class receipts; the joint
// descriptors 005c3420..005c36c0 call JointInstance's 005c08d0 directly, which the native AutoJoint base does not give).
#include "v8datamodel/Explosion.h"
#include "v8datamodel/FlagStandService.h"
#include "v8datamodel/Value.h"
#include "v8datamodel/Visit.h"
#include "v8datamodel/JointInstance.h"

namespace RBX
{
	template const Name& Name::declare<sExplosion>();
	template const Name& Name::declare<sFlagStandService>();
	template const Name& Name::declare<sObjectValue>();

	namespace Reflection
	{
		template ClassDescriptor& Described<Explosion, sExplosion, FactoryProduct<Explosion, Instance, sExplosion> >::classDescriptor();
		template ClassDescriptor& Described<FlagStandService, sFlagStandService, FactoryProduct<FlagStandService, Instance, sFlagStandService> >::classDescriptor();
		template ClassDescriptor& Described<Visit, sVisit, FactoryProduct<Visit, Instance, sVisit> >::classDescriptor();
		template ClassDescriptor& Described<JointInstance, sJointInstance, NonFactoryProduct<Instance, sJointInstance> >::classDescriptor();
		template ClassDescriptor& Described<ObjectValue, sObjectValue, FactoryProduct<ObjectValue, Instance, sObjectValue> >::classDescriptor();
	}
}
// ---- END AppUnit5BC_2008Descriptors.cpp ----

// ---- BEGIN AppUnit5BC_2008Visit.cpp ----
// 2008-06 native RBX::Visit unit rows (v8datamodel/Visit.cpp, 005c4400..005c52ff of the application range
// 005bc000..005c8000), inactive. Verified by tests/record_native_app_unit5bc_2008.py against the committed read-only
// native v8datamodel/Visit.h (sizeof 0x150: uploadUrl +0x130, pingThread +0x14c, read from the constructor 005c5220,
// the destructor 005c4790 and setPing 005c4bb0).
// Evidence:
//   * dynamic initializers 007f5ba0 (SetUploadUrl, "url"), 007f5bd0 (GetUploadUrl) and the SetPing descriptor
//     ("pingUrl", "interval"), BoundFuncDesc vtables 00838ed0 / 00838edc / 00838ee8;
//   * Visit() 005c5220: DescribedCreatable<Visit>() 005c4d10, uploadUrl("NoVisit") (literal 00817f00), pingThread = 0,
//     setName("Visit");
//   * setPing 005c4bb0: url != "" (operator!= import 008023cc), new worker_thread(boost::bind(&Visit::ping, url, interval),
//     "rbx_visit") (0x14 bytes, ctor 005971d0), else pingThread.reset().
#include "v8datamodel/Visit.h"
#include "util/Http.h"
#include <boost/thread.hpp>

namespace RBX
{
	// Template members the shared headers only declare (same definitions as ClickDetector.cpp / Team.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}
}

static RBX::Reflection::BoundFuncDesc<RBX::Visit, void(std::string), 1> UploadUrlFunction(&RBX::Visit::setUploadUrl, "SetUploadUrl", "url", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);
static RBX::Reflection::BoundFuncDesc<RBX::Visit, std::string(void), 0> getUploadUrl(&RBX::Visit::getUploadUrl, "GetUploadUrl", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);
static RBX::Reflection::BoundFuncDesc<RBX::Visit, void(std::string, int), 2> desc_setPing(&RBX::Visit::setPing, "SetPing", "pingUrl", "interval", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);

namespace RBX
{
	Visit::Visit()
		: uploadUrl("NoVisit")
	{
		setName("Visit");
	}

	Visit::~Visit() {}

	void Visit::setPing(std::string url, int interval)
	{
		if (url != "")
		{
			pingThread.reset(new worker_thread(boost::bind(&Visit::ping, url, interval), "rbx_visit"));
		}
		else
		{
			pingThread.reset();
		}
	}

	worker_thread::work_result Visit::ping(std::string url, int interval)
	{
		try
		{
			std::string message;
			Http(url).get(message);
		}
		catch (...)
		{
			// 005c4692: the 2008 handler is an empty catch(...) that resumes at 005c464b (no failure message)
		}

		boost::xtime xt;
		boost::xtime_get(&xt, boost::TIME_UTC);

		xt.sec += interval;

		boost::thread::sleep(xt);

		return worker_thread::more;
	}
}
// ---- END AppUnit5BC_2008Visit.cpp ----

