// 2008-06 native RBX::Humanoid (inactive): one original unit (005d74a0..005dccxx; initializers 007f62d0..007f6950,
// atexit 007ff300..007ff660). Evidence in native-headers/humanoid/Humanoid2008.h; verified by
// tests/record_native_humanoid2008.py. Bodies after the donor tools/rbxgs Humanoid.cpp where the 2008 bytes agree.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// Humanoid2008 | 2008-06 | draft (no current byte proof)
// 0/13 mapped addresses byte-exact | 13 unproved | 1 referenced strings (not rechecked) | by king_originala (+5) (mixed 6)
// <<< native-status | src 0ffbb1d7 | roc native-status --write
#include "humanoid/Humanoid2008.h"
#include "v8tree/Service.h"
#include "util/Object.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"
#include "AppDraw/DrawAdorn.h"
#ifdef NATIVE_HUMANOID2008_PENDING
#include "Network/Players.h"
#endif
#include <G3D/g3dmath.h>

namespace RBX
{
	char sHumanoid[] = "Humanoid"; // 009537e8 (.data; doDeclare 0048a2c0, classDescriptor 005c0860)

	// Template members the shared headers only declare (same definitions as Seat.cpp / NetworkPlayer.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	namespace Reflection
	{
		// Declared (not defined) in reflection/reflection.h (same definition as NetworkPlayers.cpp).
		template<typename Class, typename Function>
		BoundFuncDesc<Class, Function, 2>::BoundFuncDesc(
			typename BoundFuncDesc<Class, Function, 2>::FunctionSig function,
			const char* name,
			const char* arg1Name,
			const char* arg2Name,
			Security security)
			: FuncDesc<Class>(name, security),
			  function(function),
			  default1(),
			  default2()
		{
			declareSignature(arg1Name, arg2Name);
		}
	}

	// Dynamic initializers 007f62d0..007f6950, in this order (descriptor statics 0097a2..0097a6). The PartInstance
	// reference properties Torso / LeftLeg / RightLeg / WalkToPart (007f62d0..007f63f0) are defined in
	// Humanoid2008Parts.cpp with the bodies that need a complete PartInstance.
	Reflection::PropDescriptor<Humanoid, G3D::Vector3> propWalkToPoint("WalkToPoint", "Control", &Humanoid::getWalkToPoint, &Humanoid::setWalkToPoint, Reflection::PropertyDescriptor::STREAMING); // 0097a4cc
	Reflection::PropDescriptor<Humanoid, G3D::Vector3> propWalkDirection("WalkDirection", "Control", &Humanoid::getWalkDirection, &Humanoid::setWalkDirection, Reflection::PropertyDescriptor::STREAMING); // 0097a4e8
	Reflection::PropDescriptor<Humanoid, float> propWalkRotationalVelocity("WalkRotationalVelocity", "Control", &Humanoid::getWalkRotationalVelocity, &Humanoid::setWalkRotationalVelocity, Reflection::PropertyDescriptor::STREAMING); // 0097a2d8
	Reflection::PropDescriptor<Humanoid, bool> propJump("Jump", "Control", &Humanoid::getJump, &Humanoid::setJump, Reflection::PropertyDescriptor::STREAMING);                       // 0097a26c
	Reflection::PropDescriptor<Humanoid, G3D::Vector3> propTargetPoint("TargetPoint", "Control", &Humanoid::getTargetPoint, &Humanoid::setTargetPoint, Reflection::PropertyDescriptor::STREAMING); // 0097a4b0
	Reflection::PropDescriptor<Humanoid, bool> propSit("Sit", "Control", &Humanoid::getSit, &Humanoid::setSit, Reflection::PropertyDescriptor::STREAMING);                           // 0097a3ec
	Reflection::PropDescriptor<Humanoid, bool> propStrafe("Strafe", "Control", &Humanoid::getStrafe, &Humanoid::setStrafe, Reflection::PropertyDescriptor::STREAMING);               // 0097a5c0
	Reflection::PropDescriptor<Humanoid, float> propHealth("Health", "Game", &Humanoid::getHealth, &Humanoid::setHealth, Reflection::PropertyDescriptor::STANDARD);                    // 0097a460
	Reflection::PropDescriptor<Humanoid, float> propMaxHealth("MaxHealth", "Game", &Humanoid::getMaxHealth, &Humanoid::setMaxHealth, Reflection::PropertyDescriptor::STANDARD);       // 0097a3d0

	// TakeDamage 007f67b0 and MoveTo 007f67f0 push security 0 (NeedTrustedCaller).
	static Reflection::BoundFuncDesc<Humanoid, void(float), 1> func_TakeDamage(&Humanoid::takeDamage, "TakeDamage", "amount", Reflection::FunctionDescriptor::NeedTrustedCaller); // 0097a288
	static Reflection::BoundFuncDesc<Humanoid, void(G3D::Vector3, boost::shared_ptr<Instance>), 2> func_MoveTo(&Humanoid::moveTo2, "MoveTo", "location", "part", Reflection::FunctionDescriptor::NeedTrustedCaller); // 0097a408

	Humanoid::Humanoid()
		: health(100.0f),
		  maxHealth(100.0f),
		  walkMode(DIRECTION_MOVE),
		  walkTimer(0),
		  walkRotationalVelocity(0.0f),
		  jump(false),
		  imDead(false),
		  hadHeadJoint(false),
		  sit(false),
		  strafe(false),
		  world(NULL)
	{
		setName("Humanoid");
	}

	Humanoid::~Humanoid()
	{
	}

	bool Humanoid::askSetParent(const Instance* instance) const
	{
		return dynamic_cast<const ModelInstance*>(instance) != NULL;
	}

	ModelInstance* Humanoid::getCharacterFromHumanoid(Humanoid* humanoid)
	{
		if (humanoid)
		{
			if (ModelInstance* character = dynamic_cast<ModelInstance*>(humanoid->getParent()))
				return character;
		}

		return NULL;
	}

#ifdef NATIVE_HUMANOID2008_PENDING
	// ModelInstance::findModifierOfType<T> (005d8690 = <Humanoid>) is a proposal for the native ModelInstance.h owner;
	// the pending build uses a generated copy with that member template.
	Humanoid* Humanoid::modelIsCharacter(const Instance* testModel)
	{
		if (testModel)
		{
			if (const ModelInstance* model = dynamic_cast<const ModelInstance*>(testModel))
				return model->findModifierOfType<Humanoid>();
		}

		return NULL;
	}

	Humanoid* Humanoid::getLocalHumanoidFromContext(const Instance* context)
	{
		return modelIsCharacter(Network::Players::findLocalCharacter(context));
	}
#endif

	G3D::CoordinateFrame Humanoid::getTopOfHead() const
	{
		return G3D::CoordinateFrame(G3D::Vector3(0.0f, 0.5f, 0.0f));
	}

	// 005d75a0: NOT exact (147 vs 151 bytes; EH scope shape only). The original registers an EH
	// scope table (0x7c4a3a) for the "Head" string local with the local initialized before the
	// branch (extra 4-byte frame + push ebx); no source form tried reproduces the scope-table
	// registration. Parked 2026-11-12 after three hypotheses (early-return; head local with the
	// cast after; head local with the cast inside). Next proof: the original's EH-frame trigger
	// (a try/catch or a different local layout).
	PartInstance* Humanoid::getHeadFromCharacter(const ModelInstance* character)
	{
		if (character == NULL)
			return NULL;

		std::string name("Head");
		return dynamic_cast<PartInstance*>(character->findFirstChildByName(name));
	}

	// The six limb getters (005d8a10..005d8f10): cache the body part on first use.
	PartInstance* Humanoid::getHead() const
	{
		if (head == NULL && getParent() != NULL)
			head = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Head"));
		return head.get();
	}

	PartInstance* Humanoid::getTorso() const
	{
		if (torso == NULL && getParent() != NULL)
			torso = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Torso"));
		return torso.get();
	}

	PartInstance* Humanoid::getLeftLeg() const
	{
		if (leftLeg == NULL && getParent() != NULL)
			leftLeg = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Left Leg"));
		return leftLeg.get();
	}

	PartInstance* Humanoid::getRightLeg() const
	{
		if (rightLeg == NULL && getParent() != NULL)
			rightLeg = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Right Leg"));
		return rightLeg.get();
	}

	PartInstance* Humanoid::getLeftArm() const
	{
		if (leftArm == NULL && getParent() != NULL)
			leftArm = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Left Arm"));
		return leftArm.get();
	}

	PartInstance* Humanoid::getRightArm() const
	{
		if (rightArm == NULL && getParent() != NULL)
			rightArm = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Right Arm"));
		return rightArm.get();
	}

	void Humanoid::renderWaypoint(Adorn* adorn, const G3D::Vector3& waypoint)
	{
		DrawAdorn::cylinder(adorn, G3D::CoordinateFrame(waypoint), 1, 0.2f, 1.0f, G3D::Color3::green());
	}

	void Humanoid::computeForce(const float dt, bool throttling)
	{
		if (world)
			currentState->onComputeForce(dt);
	}

	G3D::Vector3 Humanoid::getIntendedMovementVector()
	{
		return getIntendedMovementVector(false);
	}

	G3D::Vector3 Humanoid::updateWalkDirection()
	{
		return getIntendedMovementVector(true);
	}

	float Humanoid::getIntendedRotationAboutYAxis()
	{
		return currentState.get() ? currentState->getIntendedRotationAboutYAxis() : 0.0f;
	}

	void Humanoid::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (oldProvider)
		{
			currentState.reset();
			Listener<RunService, Stepped>* listener = this;
			if (RunService* runService = oldProvider->create<RunService>())
				runService->Notifier<RunService, Stepped>::removeListener(listener);
		}

		if (newProvider)
		{
			Listener<RunService, Stepped>* listener = this;
			if (RunService* runService = newProvider->create<RunService>())
				runService->Notifier<RunService, Stepped>::addListener(listener);
		}
	}

	void Humanoid::setHealth(float value)
	{
		float clamped = G3D::clamp(value, 0.0f, maxHealth);
		if (health != clamped)
		{
			health = clamped;
			raisePropertyChanged(propHealth);
			if (health == 0.0f && !imDead)
			{
				imDead = true;
				event_Died.fire(this);
			}
		}
	}

	void Humanoid::setMaxHealth(float value)
	{
		if (maxHealth != value)
		{
			maxHealth = value;
			raisePropertyChanged(propMaxHealth);
		}
	}

	void Humanoid::setWalkDirection(const G3D::Vector3& value)
	{
		if (walkDirection != value)
		{
			if (value == G3D::Vector3::zero())
			{
				walkDirection = value;
			}
			else
			{
				walkDirection = G3D::Vector3(value.x, 0.0f, value.z).direction();
				walkMode = DIRECTION_MOVE;
			}

			raisePropertyChanged(propWalkDirection);
		}
	}

	void Humanoid::setWalkRotationalVelocity(const float& value)
	{
		if (walkRotationalVelocity != value)
		{
			walkRotationalVelocity = value;
			raisePropertyChanged(propWalkRotationalVelocity);
		}
	}

	void Humanoid::setWalkToPoint(const G3D::Vector3& value)
	{
		if (walkToPoint != value)
		{
			walkToPoint = value;
			raisePropertyChanged(propWalkToPoint);
		}

		walkMode = (walkMode == HAS_PART) ? CLICK_TO_MOVE : HAS_POINT;
		walkTimer = (walkMode == CLICK_TO_MOVE) ? 240 : 0;
	}

	void Humanoid::setStrafe(bool value)
	{
		if (strafe != value)
		{
			strafe = value;
			raisePropertyChanged(propStrafe);
		}
	}

	void Humanoid::setJump(bool value)
	{
		if (jump != value)
		{
			jump = value;
			raisePropertyChanged(propJump);
		}
	}

	void Humanoid::setSit(bool value)
	{
		if (sit != value)
		{
			sit = value;
			raisePropertyChanged(propSit);
		}
	}

	Reflection::SignalDesc<Humanoid, void(void)> Humanoid::event_Died("Died");
	Reflection::SignalDesc<Humanoid, void(float)> Humanoid::event_Running("Running", "speed");
	Reflection::SignalDesc<Humanoid, void(float)> Humanoid::event_Climbing("Climbing", "speed");
	Reflection::SignalDesc<Humanoid, void(bool)> Humanoid::event_Jumping("Jumping", "active");
	Reflection::SignalDesc<Humanoid, void(bool)> Humanoid::event_FreeFalling("FreeFalling", "active");
	Reflection::SignalDesc<Humanoid, void(bool)> Humanoid::event_GettingUp("GettingUp", "active");
	Reflection::SignalDesc<Humanoid, void(bool)> Humanoid::event_Strafing("Strafing", "active");
	Reflection::SignalDesc<Humanoid, void(bool)> Humanoid::event_FallingDown("FallingDown", "active");
	Reflection::SignalDesc<Humanoid, void(bool)> Humanoid::event_Seated("Seated", "active");
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Reflection::SignalDescImpl<1,void __cdecl(float)>;
template class RBX::Reflection::TSignalDesc<void __cdecl(float)>;
template class std::auto_ptr<RBX::HUMAN::HumanoidState>;

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sHumanoid>();
