#pragma once
// >>> native-status (generated) -- do not edit >>>
// Humanoid2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 89c1f7ee | roc native-status --write
// 2008-06 native RBX::Humanoid (inactive). Declared under a non-colliding name: the original path humanoid/Humanoid.h
// is the donor header that many units still include (Team, Seat, Clothing, hit-test filters ...), so a native header
// at that path would shadow it for every recorder. Shape after the donor tools/rbxgs humanoid/Humanoid.h (a later
// source base); every base, field, slot and size below is read from the 2008-06 binary:
//   RTTI     vtable 0083d47c .?AVHumanoid@RBX@@ (30 bases): DescribedCreatable<Humanoid, Instance, sHumanoid> (name
//            mangled $1?sHumanoid@2@3PADA: a non-const char array, .data 009537e8), Connector +0x130 (KernelIndex
//            +0x134), IControllable +0x138, IRenderable +0x13c, ICharacterSubject +0x14c (ICameraSubject, virtual
//            base ILocation through the vbptr at +0x150: vbtable 0083d7d8 = {-4, 0xd8}), IModelModifier +0x1a0,
//            Listener<RunService, Stepped> +0x1a4. ILocation lives at +0x228 with its vtordisp at +0x224.
//   size     0x22c: Creatable<Instance>::create<Humanoid> 00490770 mallocs 0x22c and calls 005db280(1).
//   ctor     005db280: DescribedCreatable ctor 005dab50; Connector vtable 0083d1f4 and kernelIndex -1 (+0x134);
//            IRenderable index2d/index3d -1, bucket 0 (+0x140..+0x148); ICharacterSubject() 00641320 (most-derived 0);
//            health/maxHealth = 100.0f (008163a4) +0x1a8/+0x1ac, walkRotationalVelocity 0 +0x1b0, walkTimer 0
//            +0x1b4, walkMode 3 (DIRECTION_MOVE) +0x1b8, walkToPart shared_ptr +0x1bc, three zero Vector3s
//            +0x1c4/+0x1d0/+0x1dc, five one-bit flags cleared together (`and byte [+0x1e8], 0xe0`), six limb
//            shared_ptrs +0x1ec..+0x218, world +0x21c = 0, currentState auto_ptr +0x220 = 0; setName("Humanoid")
//            from the literal 0083d7cc.
//   dtor     005d7d20: deletes currentState through HumanoidState slot 6, releases the limb shared_ptrs and
//            walkToPart in reverse order, ~IRenderable 0047d410 on +0x13c, Connector vtable reset, base dtor 005d77d0.
//   flags    bit 0 jump (getter 005d7520), bit 3 sit (005d7530), bit 4 strafe (005d7540, setter 005dc230).
//   limbs    getHead 005d8a10 (+0x1ec "Head"), getTorso 005d8b10 (+0x1f4 "Torso"), getLeftLeg 005d8c10 (+0x1fc),
//            getRightLeg 005d8d10 (+0x204), getLeftArm 005d8e10 (+0x214), getRightArm 005d8f10 (+0x20c).
//   slots    Instance: askSetParent 3 (005d7640, ICF with CharacterAppearance/ModelInstance), onAncestorChanged 4
//            (005db560), onServiceProvider 12 (005db600). Connector 0083d3e0: computeForce 005d80e0, canThrottle
//            0060a2f0 (false), getBody 005d9310. IControllable 0083d3d4: isControllable 00565950 (true).
//            IRenderable 0083d3bc: shouldRender2d/shouldRender3dAdorn 00565950 (true), render2d 005db960,
//            render3dAdorn 005d9c30. ICharacterSubject 0083d388: getCameraIgnorePrimitives 005d7fe0,
//            getContactManager 005d77b0, getIgnorePrims 005db9e0, tellCameraNear 005d9df0,
//            getIntendedMovementVector 005d9bf0, getIntendedRotationAboutYAxis 005d80c0, cameraSetWalkOrientation
//            005dc7f0. ILocation 0083d36c: getLocation vtordisp thunk 005d9300 -> 005d9210.
//            Listener 0083d374: onEvent 005dc740.
// Member names follow the donor; flag `strafe` and the analog names marked below are not original declarations.
#include "v8tree/Instance.h"
#ifdef NATIVE_HUMANOID2008_DONOR_CONNECTOR
// Humanoid2008Parts.cpp only: the native PartInstance.h reaches the donor v8kernel/Connector.h, which cannot share a
// translation unit with Connector2008.h. Same Connector size (vptr + KernelIndex); that unit builds no vtable (no
// constructor) and its one virtual body, getContactManager, does not depend on slot order.
#include "v8kernel/Connector.h"
#else
#include "v8kernel/Connector2008.h"
#endif
#include "util/IControllable.h"
#include "util/IRenderable.h"
#include "util/RunStateOwner.h"
#include "v8datamodel/ICharacterSubject.h"
#include "v8datamodel/Clothing.h"           // IModelModifier (defined there; see the Clothing.h comment)
#include "humanoid/HumanoidState.h"
#include "reflection/signal.h"
#include <boost/shared_ptr.hpp>
#include <memory>
#include <vector>

struct NativeHumanoid2008Layout;

namespace RBX
{
	class World;
	class Body;
	class PartInstance;
	class ModelInstance;
	class ContactManager;
	class JointInstance;

	extern char sHumanoid[];

	class Humanoid : public DescribedCreatable<Humanoid, Instance, sHumanoid>,
					 public Connector,
					 public IControllable,
					 public IRenderable,
					 public ICharacterSubject,
					 public IModelModifier,
					 public Listener<RunService, Stepped>
	{
		friend struct ::NativeHumanoid2008Layout; // tests/NativeHumanoid2008Layout.cpp offset asserts

	private:
		enum WalkMode
		{
			HAS_PART,
			HAS_POINT,
			CLICK_TO_MOVE,
			DIRECTION_MOVE
		};

	private:
		float health;                                        // +0x1a8
		float maxHealth;                                     // +0x1ac
		float walkRotationalVelocity;                        // +0x1b0
		int walkTimer;                                       // +0x1b4
		WalkMode walkMode;                                   // +0x1b8
		boost::shared_ptr<PartInstance> walkToPart;          // +0x1bc
		G3D::Vector3 walkToPoint;                            // +0x1c4
		G3D::Vector3 walkDirection;                          // +0x1d0
		G3D::Vector3 targetPoint;                            // +0x1dc
		bool jump : 1;                                       // +0x1e8 bit 0
		bool imDead : 1;                                     //        bit 1
		bool hadHeadJoint : 1;                               //        bit 2
		bool sit : 1;                                        //        bit 3
		bool strafe : 1;                                     //        bit 4 (analog name)
		mutable boost::shared_ptr<PartInstance> head;        // +0x1ec
		mutable boost::shared_ptr<PartInstance> torso;       // +0x1f4
		mutable boost::shared_ptr<PartInstance> leftLeg;     // +0x1fc
		mutable boost::shared_ptr<PartInstance> rightLeg;    // +0x204
		mutable boost::shared_ptr<PartInstance> rightArm;    // +0x20c
		mutable boost::shared_ptr<PartInstance> leftArm;     // +0x214
		World* world;                                        // +0x21c
		std::auto_ptr<HUMAN::HumanoidState> currentState;    // +0x220

	public:
		Humanoid();                                          // 005db280
		virtual ~Humanoid();                                 // 005d7d20 (scalar deleting 005d8400)

	public:
		float getHealth() const { return health; }           // 005d74b0
		float getMaxHealth() const { return maxHealth; }     // 005d74c0
		G3D::Vector3 getWalkDirection() const { return walkDirection; }        // 005d74d0
		float getWalkRotationalVelocity() const { return walkRotationalVelocity; } // 005d7500
		const G3D::Vector3& getWalkToPoint() const { return walkToPoint; }     // 005d7510
		bool getJump() const { return jump; }                // 005d7520
		bool getSit() const { return sit; }                  // 005d7530
		bool getStrafe() const { return strafe; }            // 005d7540 (analog name)
		const G3D::Vector3& getTargetPoint() const { return targetPoint; }     // 005d7550

		void setHealth(float value);                         // 005dbe70
		void setMaxHealth(float value);                      // 005dbf10
		void takeDamage(float amount);                       // 005dbf40 ("TakeDamage")
		void setWalkDirection(const G3D::Vector3& value);    // 005dbf80
		void setWalkRotationalVelocity(const float& value);  // 005dc090
		void setWalkToPoint(const G3D::Vector3& value);      // 005dc0c0
		void setWalkToPart(PartInstance* value);             // 005dc150
		void setJump(bool value);                            // 005dc270
		void setStrafe(bool value);                          // 005dc230 (analog name)
		void setSit(bool value);                             // 005dc2b0
		void setTargetPoint(const G3D::Vector3& value);      // 005dc2f0
		void setTorso(PartInstance* value);                  // 005dc600
		void moveTo(const G3D::Vector3& worldPosition, PartInstance* part);   // 005dc3d0
		void moveTo2(G3D::Vector3 worldPosition, boost::shared_ptr<Instance> part); // 005dca00 ("MoveTo")
		G3D::Vector3 updateWalkDirection();                  // 005d9c10
		void setLeftLeg(PartInstance* value);                // 005dc480
		void setRightLeg(PartInstance* value);               // 005dc540
		PartInstance* getWalkToPart() const { return walkToPart.get(); }

		PartInstance* getHead() const;                       // 005d8a10
		PartInstance* getTorso() const;                      // 005d8b10
		PartInstance* getLeftLeg() const;                    // 005d8c10
		PartInstance* getRightLeg() const;                   // 005d8d10
		PartInstance* getLeftArm() const;                    // 005d8e10
		PartInstance* getRightArm() const;                   // 005d8f10

		World* getWorld() const { return world; }
		G3D::CoordinateFrame getTopOfHead() const;                            // 005d76a0
		JointInstance* findRightShoulder() const;                             // 005d9010

	public:
		// Dynamic initializers 007f6840 and 007f6870..007f6950 (in this order); names after the donor.
		static Reflection::SignalDesc<Humanoid, void(void)> event_Died;       // 0097a37c
		static Reflection::SignalDesc<Humanoid, void(float)> event_Running;   // 0097a504
		static Reflection::SignalDesc<Humanoid, void(float)> event_Climbing;  // 0097a58c
		static Reflection::SignalDesc<Humanoid, void(bool)> event_Jumping;    // 0097a5fc
		static Reflection::SignalDesc<Humanoid, void(bool)> event_FreeFalling; // 0097a47c
		static Reflection::SignalDesc<Humanoid, void(bool)> event_GettingUp;  // 0097a630
		static Reflection::SignalDesc<Humanoid, void(bool)> event_Strafing;   // 0097a348
		static Reflection::SignalDesc<Humanoid, void(bool)> event_FallingDown; // 0097a2f4
		static Reflection::SignalDesc<Humanoid, void(bool)> event_Seated;     // 0097a558

	public:
		static ModelInstance* getCharacterFromHumanoid(Humanoid* humanoid);   // 005d7670
		static PartInstance* getHeadFromCharacter(const ModelInstance* character); // 005d75a0
		static Humanoid* modelIsCharacter(const Instance* testModel);         // 005d9a20
		static Humanoid* getLocalHumanoidFromContext(const Instance* context); // 005d9bb0
		static void renderWaypoint(Adorn* adorn, const G3D::Vector3& waypoint); // 005d7750

	private:
		// Instance
		virtual bool askSetParent(const Instance* instance) const;            // slot 3, 005d7640
		virtual void onAncestorChanged(const AncestorChanged& event);         // slot 4, 005db560
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 12
		// Connector
		virtual void computeForce(const float dt, bool throttling);           // 005d80e0
		virtual bool canThrottle() const { return false; }                    // 0060a2f0
		virtual Body* getBody(int i);                                         // 005d9310
		// IControllable
		virtual bool isControllable() const { return true; }                  // 00565950
		// IRenderable
		virtual bool shouldRender2d() const { return true; }                  // 00565950
		virtual bool shouldRender3dAdorn() const { return true; }             // 00565950
		virtual void render2d(Adorn* adorn);                                  // 005db960
		virtual void render3dAdorn(Adorn* adorn);                             // 005d9c30
		// ICharacterSubject / ICameraSubject / ILocation
		virtual void getCameraIgnorePrimitives(std::vector<const Primitive*>& primitives)
		{
			getIgnorePrims(primitives);                                       // 005d7fe0
		}
		virtual const G3D::CoordinateFrame getLocation() const;               // 005d9210 (vtordisp thunk 005d9300)
		virtual ContactManager* getContactManager();                          // 005d77b0
		virtual void tellCameraNear(float distance);                          // 005d9df0
		G3D::Vector3 getIntendedMovementVector(bool setWalkMode);             // 005d9a50
		bool hasWalkToPoint(G3D::Vector3& worldPosition) const;               // 005d79b0
		virtual G3D::Vector3 getIntendedMovementVector();                     // 005d9bf0
		virtual float getIntendedRotationAboutYAxis();                        // 005d80c0
		virtual void cameraSetWalkOrientation(float rad, bool noAdjust);      // 005dc7f0
		// Listener<RunService, Stepped>
		virtual void onEvent(const RunService* source, Stepped event);        // 005dc740
	public:
		virtual void getIgnorePrims(std::vector<const Primitive*>& ignore);   // 005db9e0
	};
}
