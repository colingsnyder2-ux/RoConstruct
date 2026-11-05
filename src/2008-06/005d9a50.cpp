// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_walknativehumanoidlayoutefa12ae2d470dac4.cpp

// Candidate translation unit (score above; library headers required).
#ifndef HUMANOID_HUMANOID_H
#define HUMANOID_HUMANOID_H

#include "decomp.h"
#include "util/Handle.h"
#include "util/IControllable.h"
#include "util/IRenderable.h"
#include "util/Name.h"
#include "util/RunStateOwner.h"
#include "v8datamodel/ICharacterSubject.h"
#include "v8datamodel/PartInstance.h"
#include "v8kernel/Connector.h"
#include "v8tree/Instance.h"

#include <boost/shared_ptr.hpp>
#include <memory>

namespace RBX {

class __declspec(novtable) IModelModifier { public: virtual ~IModelModifier() {} };
class Body;
class Controller;
class World;

extern char sHumanoid[];

// SIZE 0x1f0
class Humanoid : public DescribedCreatable<Humanoid, Instance, sHumanoid>,
				 public Connector,
				 public IControllable,
				 public IRenderable,
				 public ICharacterSubject,
				 public IModelModifier, public Listener<RunService, Stepped>
{

public:
	enum WalkMode
	{
		HAS_PART = 0,
		HAS_POINT = 1,
		CLICK_TO_MOVE = 2,
		DIRECTION_MOVE = 3
	};

	// SIZE 0x08
	class __declspec(novtable) State : public INamed
	{
	public:
		virtual ~State() {} // vtable+0x04

		virtual void onComputeForce(const float stepDt) = 0;                   // vtable+0x08
		virtual State* onStep(const float stepDt, Controller& controller) = 0; // vtable+0x0c

		// FUNCTION: WEBSERVICE 0x100a0710 FOLDED
		virtual float getIntendedRotationAboutYAxis() const // vtable+0x10
		{
			return 0;
		}

	protected:
		State(Humanoid* humanoid) : humanoid(humanoid) {}

		Humanoid* const humanoid; // 0x04
	};

	static Reflection::SignalDesc<Humanoid, void()> event_Died;
	static Reflection::SignalDesc<Humanoid, void(float)> event_Running;
	static Reflection::SignalDesc<Humanoid, void(float)> event_Climbing;
	static Reflection::SignalDesc<Humanoid, void(bool)> event_Jumping;
	static Reflection::SignalDesc<Humanoid, void(bool)> event_FreeFalling;
	static Reflection::SignalDesc<Humanoid, void(bool)> event_GettingUp;
	static Reflection::SignalDesc<Humanoid, void(bool)> event_FallingDown;
	static Reflection::SignalDesc<Humanoid, void(bool)> event_Seated;

	virtual ~Humanoid();

	Body* getTorsoBody();
	Body* getRootBody();

	float getHealth() const { return health; }

	void setMaxHealth(float value);
	// FUNCTION: WEBSERVICE 0x100a0750
	float getMaxHealth() const { return maxHealth; }

	G3D::Vector3 getWalkDirection() const { return walkDirection; }

	void setWalkRotationalVelocity(const float& value);
	// FUNCTION: WEBSERVICE 0x100a0790
	float getWalkRotationalVelocity() const { return walkRotationalVelocity; }

	const G3D::Vector3& getWalkToPoint() const { return walkToPoint; }

	PartInstance* getWalkToPart() const { return walkToPart.get(); }

	void setJump(bool value);
	// FUNCTION: WEBSERVICE 0x100a07b0
	bool getJump() const { return jump; }

	void setSit(bool value);
	// FUNCTION: WEBSERVICE 0x100a07c0
	bool getSit() const { return sit; }

	const G3D::Vector3& getTargetPoint() const { return targetPoint; }

	G3D::Vector3 updateWalkDirection();

	Primitive* getTorsoPrimitive() const;
	Primitive* getLeftLegPrimitive();
	Primitive* getRightLegPrimitive();

	PartInstance* getHead() const;
	PartInstance* getTorso() const;
	PartInstance* getLeftLeg() const;
	PartInstance* getRightLeg() const;
	PartInstance* getLeftArm() const;
	PartInstance* getRightArm() const;

private:
	bool hasWalkToPoint(G3D::Vector3& worldPosition) const;

	virtual bool shouldRender2d() const;
	virtual bool shouldRender3dAdorn() const;
	virtual void render2d(Adorn* adorn);
	virtual void render3dAdorn(Adorn* adorn);
	void renderMultiplayer(Adorn* adorn, const G3D::GCamera& camera);
	virtual bool isControllable() const;
	virtual void onEvent(const RunService* source, Stepped event);
	virtual void computeForce(float dt, bool throttling);
	virtual const CoordinateFrame getLocation() const;
	virtual ContactManager* getContactManager();
	virtual void tellCameraNear(float distance);
	virtual float getIntendedRotationAboutYAxis();
	virtual void cameraSetWalkOrientation(float rad, bool noAdjust);

public:
	virtual void getIgnorePrims(std::vector<const Primitive*>& ignore);

	Humanoid();

private:
	G3D::Vector3 getIntendedMovementVector(bool setWalkMode);
	virtual G3D::Vector3 getIntendedMovementVector();

private:
	float health;                                     // 0x16c
	float maxHealth;                                  // 0x170
	float walkRotationalVelocity;                     // 0x174
	int walkTimer;                                    // 0x178
	WalkMode walkMode;                                // 0x17c
	shared_ptr<PartInstance> walkToPart;              // 0x180
	G3D::Vector3 walkToPoint;                         // 0x188
	G3D::Vector3 walkDirection;                       // 0x194
	G3D::Vector3 targetPoint;                         // 0x1a0
	bool jump : 1;                                    // 0x1ac
	bool imDead : 1;                                  // 0x1ac
	bool hadHeadJoint : 1;                            // 0x1ac
	bool observedFlag : 1;
	bool sit : 1;                                     // 0x1ac
	mutable boost::shared_ptr<PartInstance> head;     // 0x1b0
	mutable boost::shared_ptr<PartInstance> torso;    // 0x1b8
	mutable boost::shared_ptr<PartInstance> leftLeg;  // 0x1c0
	mutable boost::shared_ptr<PartInstance> rightLeg; // 0x1c8
	mutable boost::shared_ptr<PartInstance> rightArm; // 0x1d0
	mutable boost::shared_ptr<PartInstance> leftArm;  // 0x1d8
	World* world;                                     // 0x1e0
	std::auto_ptr<State> currentState;                // 0x1e4
};

DECOMP_SIZE_ASSERT(Humanoid, 0x1f0)
DECOMP_SIZE_ASSERT(Humanoid::State, 0x08)

// clang-format off
// SYNTHETIC: WEBSERVICE 0x1021b310
// RBX::`dynamic initializer for 'propWalkRotationalVelocity''
// SYNTHETIC: WEBSERVICE 0x1021b370
// RBX::`dynamic initializer for 'propJump''
// SYNTHETIC: WEBSERVICE 0x1021b430
// RBX::`dynamic initializer for 'propSit''
// SYNTHETIC: WEBSERVICE 0x1021b4f0
// RBX::`dynamic initializer for 'propMaxHealth''
// SYNTHETIC: WEBSERVICE 0x1021b5e0
// `dynamic initializer for 'RBX::Humanoid::event_Died''
// SYNTHETIC: WEBSERVICE 0x1021b610
// `dynamic initializer for 'RBX::Humanoid::event_Running''
// SYNTHETIC: WEBSERVICE 0x1021b630
// `dynamic initializer for 'RBX::Humanoid::event_Climbing''
// SYNTHETIC: WEBSERVICE 0x1021b650
// `dynamic initializer for 'RBX::Humanoid::event_Jumping''
// SYNTHETIC: WEBSERVICE 0x1021b670
// `dynamic initializer for 'RBX::Humanoid::event_FreeFalling''
// SYNTHETIC: WEBSERVICE 0x1021b690
// `dynamic initializer for 'RBX::Humanoid::event_GettingUp''
// SYNTHETIC: WEBSERVICE 0x1021b6b0
// `dynamic initializer for 'RBX::Humanoid::event_FallingDown''
// SYNTHETIC: WEBSERVICE 0x1021b6d0
// `dynamic initializer for 'RBX::Humanoid::event_Seated''
// SYNTHETIC: WEBSERVICE 0x10223400
// RBX::`dynamic atexit destructor for 'propSit''
// SYNTHETIC: WEBSERVICE 0x10223420
// RBX::`dynamic atexit destructor for 'propMaxHealth''
// SYNTHETIC: WEBSERVICE 0x10223480
// RBX::`dynamic atexit destructor for 'propJump''
// SYNTHETIC: WEBSERVICE 0x102234a0
// RBX::`dynamic atexit destructor for 'propWalkRotationalVelocity''
// SYNTHETIC: WEBSERVICE 0x10223500
// `dynamic atexit destructor for 'RBX::Humanoid::event_Climbing''
// SYNTHETIC: WEBSERVICE 0x10223510
// `dynamic atexit destructor for 'RBX::Humanoid::event_FreeFalling''
// SYNTHETIC: WEBSERVICE 0x10223520
// `dynamic atexit destructor for 'RBX::Humanoid::event_GettingUp''
// SYNTHETIC: WEBSERVICE 0x10223530
// `dynamic atexit destructor for 'RBX::Humanoid::event_FallingDown''
// SYNTHETIC: WEBSERVICE 0x10223540
// `dynamic atexit destructor for 'RBX::Humanoid::event_Seated''
// SYNTHETIC: WEBSERVICE 0x10223560
// `dynamic atexit destructor for 'RBX::Humanoid::event_Running''
// SYNTHETIC: WEBSERVICE 0x10223570
// `dynamic atexit destructor for 'RBX::Humanoid::event_Jumping''
// SYNTHETIC: WEBSERVICE 0x10223590
// `dynamic atexit destructor for 'RBX::Humanoid::event_Died''
// clang-format on

} // namespace RBX

#endif // HUMANOID_HUMANOID_H

namespace RBX {
Humanoid::Humanoid()
	: health(100), maxHealth(100), walkRotationalVelocity(0), walkTimer(0), walkMode(DIRECTION_MOVE), jump(false),
	  imDead(false), hadHeadJoint(false), observedFlag(false), sit(false), world(NULL)
{
	setName("Humanoid");
}


}
namespace RBX {
G3D::Vector3 Humanoid::getIntendedMovementVector(bool setWalkMode)
{
	G3D::Vector3 result = G3D::Vector3::zero();

	if (walkMode == DIRECTION_MOVE) {
		result = walkDirection;
	}
	else if (walkMode == CLICK_TO_MOVE) {
		PartInstance* torso = getTorso();
		G3D::Vector3 worldPosition;

		if (torso != NULL && hasWalkToPoint(worldPosition)) {
			const G3D::Vector3& translation = torso->getCoordinateFrame().translation;

			G3D::Vector3 delta = worldPosition - translation;

			worldPosition.x = delta.x;
			worldPosition.y = delta.y + 3.0f;
			worldPosition.z = delta.z;

			float distance = (worldPosition.z * worldPosition.z + worldPosition.x * worldPosition.x) +
							 worldPosition.y * worldPosition.y;

			worldPosition.y = 0;

			if (sqrtf(distance) < 2.0f) {
				if (setWalkMode) {
					walkMode = DIRECTION_MOVE;
				}

				result = G3D::Vector3::zero();
			}
			else {
				result = worldPosition.unit();
			}
		}
	}

	return result;
}


}
