// =============================================================================
// Humanoid.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/humanoid/Humanoid.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "humanoid/Humanoid2008.h"
#include "v8tree/Service.h"
#include "util/Object.h"
#include "v8datamodel/ModelInstance.h"
#include "AppDraw/DrawAdorn.h"
#include "Network/Players.h"   // findLocalCharacter 0049aca0 (getLocalHumanoidFromContext 005d9bb0)
#include <G3D/g3dmath.h>
#include "v8datamodel/PartInstance.h"   // getIntendedMovementVector(bool) 005d9a50: getCoordinateFrame 00598cb0
#include "v8datamodel/Workspace.h"      // native (read only): getWorldIfInWorkspace 005a3390, findWorkspace 005a3380
#include "v8datamodel/Camera.h"         // native (read only): getCameraSubject 005cc420, setCameraSubject 005cde10
#include "v8kernel/Kernel.h"            // donor: insertConnector2ndPass 005fad50 / removeConnector2ndPass 005fad80
#include "v8datamodel/Teams.h"          // native (read only): getTeamColorForHumanoid 005d6180
#include "util/Color.h"                 // Color::lightGreen 005d7560
#include "RbxGraphics/Adorn.h"

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

	Reflection::PropDescriptor<Humanoid, G3D::Vector3> propWalkToPoint(
		"WalkToPoint",
		"Control",
		&Humanoid::getWalkToPoint,
		&Humanoid::setWalkToPoint,
		Reflection::PropertyDescriptor::STREAMING); // 0097a4cc
	Reflection::PropDescriptor<Humanoid, G3D::Vector3> propWalkDirection(
		"WalkDirection",
		"Control",
		&Humanoid::getWalkDirection,
		&Humanoid::setWalkDirection,
		Reflection::PropertyDescriptor::STREAMING); // 0097a4e8
	Reflection::PropDescriptor<Humanoid, float> propWalkRotationalVelocity(
		"WalkRotationalVelocity",
		"Control",
		&Humanoid::getWalkRotationalVelocity,
		&Humanoid::setWalkRotationalVelocity,
		Reflection::PropertyDescriptor::STREAMING); // 0097a2d8
	Reflection::PropDescriptor<Humanoid, bool> propJump("Jump", "Control", &Humanoid::getJump, &Humanoid::setJump, Reflection::PropertyDescriptor::STREAMING);                       // 0097a26c
	Reflection::PropDescriptor<Humanoid, G3D::Vector3> propTargetPoint(
		"TargetPoint",
		"Control",
		&Humanoid::getTargetPoint,
		&Humanoid::setTargetPoint,
		Reflection::PropertyDescriptor::STREAMING); // 0097a4b0
	Reflection::PropDescriptor<Humanoid, bool> propSit("Sit", "Control", &Humanoid::getSit, &Humanoid::setSit, Reflection::PropertyDescriptor::STREAMING);                           // 0097a3ec
	Reflection::PropDescriptor<Humanoid, bool> propStrafe("Strafe", "Control", &Humanoid::getStrafe, &Humanoid::setStrafe, Reflection::PropertyDescriptor::STREAMING);               // 0097a5c0
	Reflection::PropDescriptor<Humanoid, float> propHealth("Health", "Game", &Humanoid::getHealth, &Humanoid::setHealth, Reflection::PropertyDescriptor::STANDARD);                    // 0097a460
	Reflection::PropDescriptor<Humanoid, float> propMaxHealth("MaxHealth", "Game", &Humanoid::getMaxHealth, &Humanoid::setMaxHealth, Reflection::PropertyDescriptor::STANDARD);       // 0097a3d0

	static Reflection::BoundFuncDesc<Humanoid, void(float), 1> func_TakeDamage(
		&Humanoid::takeDamage,
		"TakeDamage",
		"amount",
		Reflection::FunctionDescriptor::NeedTrustedCaller); // 0097a288
	static Reflection::BoundFuncDesc<Humanoid, void(G3D::Vector3, boost::shared_ptr<Instance>), 2> func_MoveTo(
		&Humanoid::moveTo2,
		"MoveTo",
		"location",
		"part",
		Reflection::FunctionDescriptor::NeedTrustedCaller); // 0097a408

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

	PartInstance* Humanoid::getTorsoSlow() const
	{
		return dynamic_cast<PartInstance*>(getParent()->findFirstChildByName("Torso"));
	}

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

	void Humanoid::onAncestorChanged(const AncestorChanged& event)
	{
		Instance::onAncestorChanged(event);
		World* worldInWorkspace = Workspace::getWorldIfInWorkspace(this);
		if (worldInWorkspace != world)
		{
			if (world)
				world->getKernel().removeConnector2ndPass(this);
			world = worldInWorkspace;
			if (world)
			{
				currentState.reset(HUMAN::HumanoidState::createDefault(this));
				world->getKernel().insertConnector2ndPass(this);
				onLocalHumanoidEnteringWorkspace();
			}
		}
	}

	void Humanoid::onLocalHumanoidEnteringWorkspace()
	{
		Workspace* workspace = ServiceProvider::find<Workspace>(this);
		if (this == modelIsCharacter(Network::Players::findLocalCharacter(this)))
		{
			if (workspace->getCamera()->getCameraType() == Camera::CUSTOM_CAMERA && workspace->getCamera()->getCameraSubject() != this)
				workspace->getCamera()->setCameraSubject(this);
		}
	}

	void Humanoid::render2d(Adorn* adorn)
	{
		if (this != modelIsCharacter(Network::Players::findLocalCharacter(this)))
		{
			Workspace* workspace = Workspace::findWorkspace(this);
			if (workspace)
				renderMultiplayer(adorn, workspace->getGCamera());
		}
	}

	G3D::CoordinateFrame Humanoid::getTopOfHead() const
	{
		return G3D::CoordinateFrame(G3D::Vector3(0.0f, 0.5f, 0.0f));
	}

	G3D::CoordinateFrame Humanoid::getRightArmGrip() const
	{
		G3D::CoordinateFrame cframe;
		cframe.lookAt(G3D::Vector3(0.0f, -1.0f, 0.0f), G3D::Vector3(0.0f, 0.0f, -1.0f));
		cframe.translation = G3D::Vector3(0.0f, -1.0f, 0.0f);

		return cframe;
	}

#ifdef HUMANOID_HEADER_DECLARES_FINDRIGHTARM
	PartInstance* Humanoid::findRightArm() const
	{
		return static_cast<PartInstance*>(getParent() ? getParent()->findFirstChildByName("Right Arm") : NULL);
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
				worldPosition = worldPosition - torso->getCoordinateFrame().translation;
				float distance = (worldPosition + G3D::Vector3(0.0f, 3.0f, 0.0f)).magnitude();
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

template class RBX::Reflection::SignalDescImpl<1,void __cdecl(float)>;
template class RBX::Reflection::TSignalDesc<void __cdecl(float)>;
template class std::auto_ptr<RBX::HUMAN::HumanoidState>;

template void RBX::Name::callDoDeclare<RBX::sHumanoid>();

#define NATIVE_HUMANOID2008_DONOR_CONNECTOR
#include "v8datamodel/PartInstance.h"
#include "humanoid/HumanoidState.h"

namespace RBX
{
namespace HUMAN
{

bool HumanoidState::canTransition(int event)
{
	switch (event)
	{
	case 0:  return humanoid->imDead;
	case 1:  return humanoid->getJump();
	case 4:  return humanoid->getSit();
	case 5:  return !humanoid->getSit();
	case 6:  return tipped();
	case 7:  return upright();
	case 8:  return floorFound;
	case 9:  return !floorFound;
	case 2:  return humanoid->getStrafe();
	case 3:  return !humanoid->getStrafe();
	case 11: return floorPart.get() != NULL;
	case 10: return floorPart.get() == NULL;
	case 12: return onFloorStep();
	case 13: return !onFloorStep();
	case 15: return value0c <= 0.0f;
	case 14: return flag11;
	case 16: return sub_00643eb0();
	default: return false;
	}
}

}
}
