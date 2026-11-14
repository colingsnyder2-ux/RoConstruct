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
#include "AppDraw/DrawAdorn.h"
#ifdef NATIVE_HUMANOID2008_PENDING
#include "Network/Players.h"
#endif
#include <G3D/g3dmath.h>
#include "v8datamodel/PartInstance.h"   // getIntendedMovementVector(bool) 005d9a50: getCoordinateFrame 00598cb0

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

#ifdef NATIVE_HUMANOID_PENDING_GETTERS
	// 005d7a30 ?getRightArmGrip@Humanoid@RBX@@QBE?AVCoordinateFrame@G3D@@XZ (90 bytes; caller Tool weld "RightGrip").
	// Pending header proposal: humanoid/Humanoid2008.h does not declare getRightArmGrip. Donor tools/rbxgs
	// Humanoid.cpp body: CoordinateFrame() 004782d0, lookAt 00518b90 with target (0,-1,0) and up (0,0,-1) (-1.0f
	// 0081c3b8), translation (0,-1,0) stored at +0x24..+0x2c. A trial (2026-11-14) compiled this body against the
	// donor humanoid/Humanoid.h declaration (HumanoidStateFloor.cpp flags) and it was byte-identical to 005d7a30
	// (90/90 bytes, relocations masked; prove.py inactive_exact). The body reads no Humanoid field.
	G3D::CoordinateFrame Humanoid::getRightArmGrip() const
	{
		G3D::CoordinateFrame cframe;
		cframe.lookAt(G3D::Vector3(0.0f, -1.0f, 0.0f), G3D::Vector3(0.0f, 0.0f, -1.0f));
		cframe.translation = G3D::Vector3(0.0f, -1.0f, 0.0f);

		return cframe;
	}
#endif

	void Humanoid::renderWaypoint(Adorn* adorn, const G3D::Vector3& waypoint)
	{
		DrawAdorn::cylinder(adorn, G3D::CoordinateFrame(waypoint), 1, 0.2f, 1.0f, G3D::Color3::green());
	}

	void Humanoid::computeForce(const float dt, bool throttling)
	{
		if (world)
			currentState->onComputeForce(dt);
	}

	// 005d9a50 (337 bytes): donor tools/rbxgs Humanoid.cpp body. walkMode +0x1b8 (3 DIRECTION_MOVE -> walkDirection
	// +0x1d0; 2 CLICK_TO_MOVE -> getTorso 005d8b10, hasWalkToPoint 005d79b0, getCoordinateFrame 00598cb0,
	// Vector3::zero 004782a0, Vector3::direction 004fab70).
	G3D::Vector3 Humanoid::getIntendedMovementVector(bool setWalkMode)
	{
		G3D::Vector3 result = G3D::Vector3::zero();

		if (walkMode == DIRECTION_MOVE)
		{
			result = walkDirection;
		}
		else if (walkMode == CLICK_TO_MOVE)
		{
			PartInstance* torso = getTorso();
			G3D::Vector3 worldPosition;

			if (torso && hasWalkToPoint(worldPosition))
			{
				// Target: the distance test adds 3.0f (0081e380) to the y difference and the flattened delta
				// (y = 0) is stored before the 2.0f (0081c434) comparison; the delta lives in worldPosition's slot.
				// Rejected: donor body (delta.y = 0 before magnitude; separate delta, 308 bytes); separate
				// G3D::Vector3 delta = worldPosition - torsoPosition with y += 3 (335 bytes, extra 12-byte local).
				// PARKED (3 hypotheses): this in-place form is 339 bytes with the target's frame (0x18); it still
				// stores x'/y'/z' as they are computed, while the target keeps y' + 3 in st only and sums
				// z'*z' + x'*x' before (y' + 3)^2. Next lead: a magnitude over a temporary such as
				// (worldPosition + G3D::Vector3(0, 3, 0)).magnitude() after flattening x/z in place.
				worldPosition -= torso->getCoordinateFrame().translation;
				worldPosition.y += 3.0f;
				float distance = worldPosition.magnitude();
				worldPosition.y = 0.0f;

				if (distance < 2.0f)
				{
					if (setWalkMode)
						walkMode = DIRECTION_MOVE;

					result = G3D::Vector3::zero();
				}
				else
				{
					result = worldPosition.direction();
				}
			}
		}

		return result;
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
