// 2008-06 native RBX::Rocket (inactive); evidence in native-headers/v8datamodel/Rocket.h. The original compiles it
// in the BodyMover unit (0062e090..00633101), so it uses the same unit profile (see
// tests/record_native_body_movers.py). Verified by tests/record_native_body_movers.py.
// >>> native-status (generated) -- do not edit >>>
// Rocket | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src be2bf013 | roc native-status --write
#include "v8datamodel/Rocket.h"
#include "v8datamodel/PartInstance.h"
#ifdef NATIVE_ROCKET_PENDING
#include "v8datamodel/Workspace.h" // native Workspace / Network::Players headers (declaration-only overlays in the recorder)
#include "Network/Players.h"
#endif

namespace RBX
{
	char sRocket[] = "RocketPropulsion"; // 0095c740

	// Template members the shared headers only declare (same definitions as BodyMovers.cpp).
	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	template<class A>
	DescribedCreatable<C, D, N>::DescribedCreatable(A arg0)
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >(arg0) {}

	// Dynamic initializers 007f7f10..007f8190 (in this order).
	Reflection::RefPropDescriptor<Rocket, PartInstance> Rocket::prop_Target("Target", "Goals", &Rocket::getTarget, &Rocket::setTarget, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> Rocket::prop_targetOffset("TargetOffset", "Goals", &Rocket::targetOffset, &Rocket::onGoalChanged, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_targetRadius("TargetRadius", "Goals", &Rocket::targetRadius, &Rocket::onGoalChanged, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_MaxSpeed("MaxSpeed", "Thrust", &Rocket::maxSpeed, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_MaxThrust("MaxThrust", "Thrust", &Rocket::maxThrust, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_ThrustP("ThrustP", "Thrust", &Rocket::kThrustP, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_ThrustD("ThrustD", "Thrust", &Rocket::kThrustD, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_TurnP("TurnP", "Turn", &Rocket::kTurnP, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_TurnD("TurnD", "Turn", &Rocket::kTurnD, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> Rocket::prop_MaxTorque("MaxTorque", "Turn", &Rocket::maxTorque, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_CartoonFactor("CartoonFactor", "Goals", &Rocket::cartoonFactor, Reflection::PropertyDescriptor::STANDARD);

	// Security 0 (NeedTrustedCaller in the donor enum) is what the 2008 initializers push.
	Reflection::BoundFuncDesc<Rocket, void(void), 0> Rocket::func_Fire(&Rocket::fire, "Fire", Reflection::FunctionDescriptor::NeedTrustedCaller);
	Reflection::BoundFuncDesc<Rocket, void(void), 0> Rocket::func_Abort(&Rocket::abort, "Abort", Reflection::FunctionDescriptor::NeedTrustedCaller);

	Reflection::SignalDesc<Rocket, void(void)> Rocket::event_ReachedTarget("ReachedTarget");

	Rocket::Rocket()
		: Base(sRocket),
		  active(false),
		  target(),
		  targetOffset(),
		  targetRadius(4.0f),
		  firedEvent(false),
		  maxThrust(4000.0f),
		  kThrustP(5.0f),
		  kThrustD(0.001f),
		  maxSpeed(30.0f),
		  kTurnP(3000.0f),
		  kTurnD(500.0f),
		  maxTorque(400000.0f, 400000.0f, 0.0f),
		  cartoonFactor(0.7f)
	{
	}

#ifdef NATIVE_ROCKET_PENDING
	// Needs Workspace::findWorkspace (005a3380) and Network::Players::clientIsPresent (00495e60); the donor headers
	// do not compile against the 2008 reflection.h. Verified against generated declaration-only headers.
	void Rocket::fire()
	{
		if (!Workspace::findWorkspace(this))
			throw std::runtime_error("Rocket:Fire may only be called when the Rocket is in the Workspace");
		if (Network::Players::clientIsPresent(this, true))
			throw std::runtime_error("Rocket:Fire may not be called from a client");
		active = true;
	}
#endif

	void Rocket::abort()
	{
		active = false;
	}

	void Rocket::setTarget(PartInstance* value)
	{
		if (target.get() != value)
		{
			target = shared_from<PartInstance>(value);
			firedEvent = false;
			raisePropertyChanged(Rocket::prop_Target);
		}
	}
}
