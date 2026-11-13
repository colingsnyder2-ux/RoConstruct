// 2008-06 native RBX::BodyMover family (inactive); evidence in native-headers/v8datamodel/BodyMovers.h.
// The original unit 0062e090..00633101 also holds Rocket (native-classes/Rocket.cpp). Verified by
// tests/record_native_body_movers.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// BodyMovers | 2008-06 | draft (no current byte proof)
// 0/11 mapped addresses byte-exact | 11 unproved | 4 referenced strings (not rechecked) | by king_originala (+3) (mixed 5)
// <<< native-status | src 3793eee6 | roc native-status --write
#include "v8datamodel/BodyMovers.h"
#include "v8datamodel/Rocket.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"

namespace RBX
{

	char sBodyPosition[] = "BodyPosition";               // 0095c6e8
	char sBodyVelocity[] = "BodyVelocity";               // 0095c6f8
	char sBodyGyro[] = "BodyGyro";                       // 0095c708
	char sBodyAngularVelocity[] = "BodyAngularVelocity"; // 0095c714
	char sBodyForce[] = "BodyForce";                     // 0095c728
	char sBodyThrust[] = "BodyThrust";                   // 0095c734

	// Template members the shared headers only declare (same definitions as Team.cpp / Message.cpp).
	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	template<class A>
	DescribedCreatable<C, D, N>::DescribedCreatable(A arg0)
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >(arg0) {}

	// 00630860 (called from the factory registration unit 005c3d8e): declares each class name.
	void registerBodyMovers()
	{
		BodyGyro::className();
		BodyPosition::className();
		BodyVelocity::className();
		BodyAngularVelocity::className();
		BodyForce::className();
		BodyThrust::className();
		Rocket::className();
	}

	BodyMover::BodyMover(const char* name)
		: Instance(name),
		  world(NULL),
		  part()
	{
	}

	BodyMover::~BodyMover()
	{
	}

	bool BodyMover::askSetParent(const Instance* instance) const
	{
		return dynamic_cast<const PartInstance*>(instance) != NULL;
	}

	void BodyMover::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		// No Instance::onServiceProvider call and no world update here in 2008 (00632db0).
		if (oldProvider)
			Notifier<RunService, Stepped>::disconnect(oldProvider->create<RunService>(), this);
		if (newProvider)
			Notifier<RunService, Stepped>::connect(newProvider->create<RunService>(), this);
	}

	// Workspace::getWorldIfInWorkspace 005a3390 (native v8datamodel/Workspace.h).
	void BodyMover::onAncestorChanged(const AncestorChanged& event)
	{
		Instance::onAncestorChanged(event);

		if (event.child == this)
			part = shared_from<PartInstance>(dynamic_cast<PartInstance*>(event.newParent));

		World* worldIfInWorkspace = part.lock() ? Workspace::getWorldIfInWorkspace(this) : NULL;
		if (world != worldIfInWorkspace)
		{
			if (world)
				world->getKernel().removeConnector2ndPass(this);
			world = worldIfInWorkspace;
			if (worldIfInWorkspace)
				worldIfInWorkspace->getKernel().insertConnector2ndPass(this);
		}
	}

	// ---- BodyGyro (dynamic initializers 007f81c0..007f8250) ----
	Reflection::BoundProp<float, 1> BodyGyro::prop_kP("P", "Goals", &BodyGyro::kP, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> BodyGyro::prop_kD("D", "Goals", &BodyGyro::kD, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> BodyGyro::prop_maxTorque("maxTorque", "Goals", &BodyGyro::maxTorque, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::CoordinateFrame, 1> BodyGyro::prop_cframe("cframe", "Goals", &BodyGyro::cframe, Reflection::PropertyDescriptor::STANDARD);

	BodyGyro::BodyGyro()
		: Base(sBodyGyro),
		  kP(3000.0f),
		  kD(500.0f),
		  maxTorque(400000.0f, 0.0f, 400000.0f),
		  cframe()
	{
	}

	// ---- BodyPosition (007f8280..007f8370) ----
	Reflection::BoundProp<float, 1> BodyPosition::prop_kP("P", "Goals", &BodyPosition::kP, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> BodyPosition::prop_kD("D", "Goals", &BodyPosition::kD, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> BodyPosition::prop_maxForce("maxForce", "Goals", &BodyPosition::maxForce, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> BodyPosition::prop_position("position", "Goals", &BodyPosition::position, Reflection::PropertyDescriptor::STANDARD);
	// Security 0 (NeedTrustedCaller in the donor enum) is what the 2008 initializers push.
	static Reflection::BoundFuncDesc<BodyPosition, G3D::Vector3(void), 0> func_getLastForceOld(&BodyPosition::getLastForce, "lastForce", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<BodyPosition, G3D::Vector3(void), 0> func_getLastForce(&BodyPosition::getLastForce, "GetLastForce", Reflection::FunctionDescriptor::NeedTrustedCaller);

	BodyPosition::BodyPosition()
		: Base(sBodyPosition),
		  kP(10000.0f),
		  kD(1250.0f),
		  maxForce(4000.0f, 4000.0f, 4000.0f),
		  position(0.0f, 50.0f, 0.0f),
		  lastForce()
	{
	}

	G3D::Vector3 BodyPosition::getLastForce()
	{
		return lastForce;
	}

	// ---- BodyVelocity (007f83a0..007f8460) ----
	Reflection::BoundProp<float, 1> BodyVelocity::prop_kP("P", "Goals", &BodyVelocity::kP, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> BodyVelocity::prop_maxForce("maxForce", "Goals", &BodyVelocity::maxForce, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> BodyVelocity::prop_velocity("velocity", "Goals", &BodyVelocity::velocity, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundFuncDesc<BodyVelocity, G3D::Vector3(void), 0> func_getLastForceVOld(&BodyVelocity::getLastForce, "lastForce", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<BodyVelocity, G3D::Vector3(void), 0> func_getLastForceV(&BodyVelocity::getLastForce, "GetLastForce", Reflection::FunctionDescriptor::NeedTrustedCaller);

	BodyVelocity::BodyVelocity()
		: Base(sBodyVelocity),
		  kP(1250.0f),
		  maxForce(4000.0f, 4000.0f, 4000.0f),
		  velocity(0.0f, 2.0f, 0.0f),
		  lastForce()
	{
	}

	bool BodyVelocity::preventBodySleep() const
	{
		return velocity != G3D::Vector3::zero();
	}

	G3D::Vector3 BodyVelocity::getLastForce()
	{
		return lastForce;
	}

	// ---- BodyAngularVelocity (007f8490..007f84f0) ----
	Reflection::BoundProp<float, 1> BodyAngularVelocity::prop_kP("P", "Goals", &BodyAngularVelocity::kP, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> BodyAngularVelocity::prop_maxTorque("maxTorque", "Goals", &BodyAngularVelocity::maxTorque, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> BodyAngularVelocity::prop_angularVelocity("angularvelocity", "Goals", &BodyAngularVelocity::angularVelocity, Reflection::PropertyDescriptor::STANDARD);

	BodyAngularVelocity::BodyAngularVelocity()
		: Base(sBodyAngularVelocity),
		  kP(1250.0f),
		  maxTorque(4000.0f, 4000.0f, 4000.0f),
		  angularVelocity(0.0f, 2.0f, 0.0f),
		  lastTorque()
	{
	}

	bool BodyAngularVelocity::preventBodySleep() const
	{
		return angularVelocity != G3D::Vector3::zero();
	}

	// ---- BodyForce (007f8520) ----
	Reflection::BoundProp<G3D::Vector3, 1> BodyForce::prop_Force("force", "Goals", &BodyForce::force, Reflection::PropertyDescriptor::STANDARD);

	BodyForce::BodyForce()
		: Base(sBodyForce),
		  force(G3D::Vector3::unitY())
	{
	}

	bool BodyForce::preventBodySleep() const
	{
		return force != G3D::Vector3::zero();
	}

	// ---- BodyThrust (007f8550, 007f8580) ----
	Reflection::BoundProp<G3D::Vector3, 1> BodyThrust::prop_force("force", "Goals", &BodyThrust::force, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> BodyThrust::prop_location("location", "Goals", &BodyThrust::location, Reflection::PropertyDescriptor::STANDARD);

	BodyThrust::BodyThrust()
		: Base(sBodyThrust),
		  force(G3D::Vector3::unitY()),
		  location(G3D::Vector3::zero())
	{
	}

	bool BodyThrust::preventBodySleep() const
	{
		return force != G3D::Vector3::zero();
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::weak_ptr<RBX::PartInstance>;
template class std::_Vector_const_iterator<RBX::Listener<RBX::RunService,RBX::Stepped> *,std::allocator<RBX::Listener<RBX::RunService,RBX::Stepped> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::RunService,RBX::Stepped> *,std::allocator<RBX::Listener<RBX::RunService,RBX::Stepped> *> >;

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sBodyGyro>();
template void RBX::Name::callDoDeclare<RBX::sBodyForce>();
template void RBX::Name::callDoDeclare<RBX::sBodyThrust>();
template void RBX::Name::callDoDeclare<RBX::sBodyPosition>();
template void RBX::Name::callDoDeclare<RBX::sBodyVelocity>();
template void RBX::Name::callDoDeclare<RBX::sBodyAngularVelocity>();
