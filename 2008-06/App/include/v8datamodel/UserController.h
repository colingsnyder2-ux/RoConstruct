#pragma once
// >>> native-status (generated) -- do not edit >>>
// UserController | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 50d100ac | roc native-status --write
// 2008-06 native RBX::ControllerService and the user/AI controllers (inactive). Shape after the donor
// tools/rbxgs/Client/App/include/v8datamodel/UserController.h; every base, field and virtual below is read from the
// 2008-06 binary (verified by tests/record_native_user_controller.py):
//   ControllerService  vtable 0083a2bc .?AVControllerService@RBX@@ -> DescribedCreatable<ControllerService, Instance,
//              sControllerService> (name mangled $1?sControllerService@2@3PADA: a non-const char array in .data at
//              009510b4) and the empty Service (mdisp 0x130).
//              size 0x144: the creator 0045c580 allocates 0x144 and calls the constructor 005cb9e0, which calls the
//              DescribedCreatable constructor 005cb880, zeroes hardwareDevice +0x130 and playerController +0x134 and
//              stores new(0x10) KeyboardPrimaryController +0x138, new(0x10) KeyboardSecondaryController +0x13c and
//              new(0xc) NullController +0x140 (ReferenceCountedPointer::setPointer 00598fa0); destructor 005cbbb0
//              releases them in reverse order (deleting 005cbcf0, eight ??_E thunks 005cbb30..005cbba0).
//              getController 005cbd10: PLAYER new(0x2c), AI_CHASE/AI_FLEE new(0x64), PRIMARY/SECONDARY/default the
//              stored pointers.
//   Controller (donor v8world/Controller.h, used unchanged): the binary keeps no vtable for .?AVController@RBX@@ or
//              .?AVHardwareController@RBX@@; the inlined constructors/destructors (NullController deleting destructor
//              004729b0, constructor 005cb9e0, ~SteppingController 005cb140) store only G3D::ReferenceCountedObject's
//              vtable 0081e1e0 and the final class's, which the donor declarations reproduce (the intermediate
//              Controller vptr store is dropped by the compiler).
//   HardwareController  ControllerService* +0x0c (getHardwareDevice 005ca370 reads [this+0xc]->hardwareDevice +0x130;
//              defined in the unit, inlined at most call sites, one out-of-line call in KeyboardPrimary getValue).
//   Keyboard getValue bodies inline UserInputBase::altKeyDown (keyDown RALT/LALT) and call ctrlKeyDown 0045aec0: they
//              are exact only with altKeyDown inline in util/UserInputBase.h (NATIVE_USER_CONTROLLER_PENDING).
//   KeyboardPrimaryController 0x10 (vtable 00839fa4: getValue 005ca500, getControllerType 1, hasIntelligence /
//              isUserController 00565950 return true); KeyboardSecondaryController 0x10 (00839fbc, getValue 005ca760).
//   SteppingController  vtable 0083a0c8 (Listener<RunService, Heartbeat> mdisp 0x0c, vtable 0083a0bc); constructor
//              005cb2f0: runService shared_ptr +0x10 (ServiceProvider::create<RunService> 00492e00, shared_from
//              00618a40), controlledInstance weak_ptr +0x18, then connects to RunService +0x130 (addListener
//              004218a0); destructor 005cb140 disconnects (removeListener 005e5a80). Size 0x20.
//   PlayerController  0x2c (getController new(0x2c)); controllerService weak_ptr +0x20, stepsRotating +0x28
//              (constructor 005cb3e0, destructor 005cb4b0); vtable 0083a114, onEvent 005cb530.
//   AIController  0x64 (new(0x64)); retargetTime +0x20, buffer[NUM_INPUT_TYPES] +0x24, target weak_ptr +0x5c
//              (constructor 005cb820, destructor 005cb210, getValue 005ca420 reads +0x24 + 4*type).
//   AIChaseController / AIFleeController  0x64; constructors 005cb990 / 005cb9b0; vtables 0083a1fc / 0083a224.
#include "v8tree/Service.h"
#include "v8world/Controller.h"
#include "util/UserInputBase.h"
#include "util/RunStateOwner.h"

struct NativeUserControllerLayout;

namespace RBX
{
	class PVInstance;

	extern char sControllerService[];

	class ControllerService : public DescribedCreatable<ControllerService, Instance, sControllerService>, public Service
	{
		friend struct ::NativeUserControllerLayout; // tests/NativeUserControllerLayout.cpp offset asserts

	private:
		UserInputBase* hardwareDevice;                                      // +0x130
		G3D::ReferenceCountedPointer<Controller> playerController;          // +0x134
		G3D::ReferenceCountedPointer<Controller> keyboardPrimaryController; // +0x138
		G3D::ReferenceCountedPointer<Controller> keyboardSecondaryController; // +0x13c
		G3D::ReferenceCountedPointer<Controller> nullController;            // +0x140

	public:
		ControllerService();                                                // 005cb9e0
		G3D::ReferenceCountedPointer<Controller> getController(Controller::ControllerType type, const PVInstance* controlledInstance); // 005cbd10

		const UserInputBase* getHardwareDevice() const
		{
			return hardwareDevice;
		}

		UserInputBase* getHardwareDevice()
		{
			return hardwareDevice;
		}

		void setHardwareDevice(UserInputBase*);
	};

	class HardwareController : public Controller
	{
		friend struct ::NativeUserControllerLayout;

	private:
		ControllerService* controllerService;                               // +0x0c

	protected:
		HardwareController(ControllerService* service)
			: controllerService(service)
		{
		}

		const UserInputBase* getHardwareDevice() const;                     // 005ca370

		virtual bool hasIntelligence() const
		{
			return true;
		}

		virtual bool isUserController() const
		{
			return true;
		}
	};

	class KeyboardPrimaryController : public HardwareController
	{
	public:
		KeyboardPrimaryController(ControllerService* service)
			: HardwareController(service)
		{
		}

		virtual float getValue(Controller::InputType) const;               // 005ca500

		virtual Controller::ControllerType getControllerType() const
		{
			return Controller::PRIMARY_CONTROLLER;
		}
	};

	class KeyboardSecondaryController : public HardwareController
	{
	public:
		KeyboardSecondaryController(ControllerService* service)
			: HardwareController(service)
		{
		}

		virtual float getValue(Controller::InputType) const;               // 005ca760

		virtual Controller::ControllerType getControllerType() const
		{
			return Controller::SECONDARY_CONTROLLER;
		}
	};

	class SteppingController : public Controller, public Listener<RunService, Heartbeat>
	{
		friend struct ::NativeUserControllerLayout;

	private:
		boost::shared_ptr<RunService> runService;                           // +0x10
	protected:
		boost::weak_ptr<const PVInstance> controlledInstance;               // +0x18

	protected:
		SteppingController(const PVInstance* _controlledInstance);          // 005cb2f0
		virtual ~SteppingController();                                      // 005cb140
	};

	class PlayerController : public SteppingController
	{
		friend struct ::NativeUserControllerLayout;

	private:
		boost::weak_ptr<ControllerService> controllerService;               // +0x20
		int stepsRotating;                                                  // +0x28

	private:
		const UserInputBase* getHardwareDevice() const;

		virtual bool hasIntelligence() const
		{
			return true;
		}

		virtual bool isUserController() const
		{
			return true;
		}

		virtual Controller::ControllerType getControllerType() const
		{
			return PLAYER_CONTROLLER;
		}

		virtual void onEvent(const RunService*, Heartbeat);                // 005cb530
	public:
		PlayerController(ControllerService* _controllerService, const PVInstance* _controlledInstance); // 005cb3e0
	};

	class AIController : public SteppingController
	{
		friend struct ::NativeUserControllerLayout;

	private:
		float retargetTime;                                                 // +0x20
	protected:
		float buffer[Controller::NUM_INPUT_TYPES];                          // +0x24
		boost::weak_ptr<const PVInstance> target;                           // +0x5c

	protected:
		AIController(const PVInstance* controlledInstance);                 // 005cb820
		virtual ~AIController();                                            // 005cb210
		void updateTarget(Controller::ControllerType excludeType, float time); // 005cadc0
		G3D::Vector3 getLocalTargetPosition() const;                        // 005cac20
		void chaseTarget(const G3D::Vector3& localChasePoint);              // 005ca430

		virtual bool hasIntelligence() const
		{
			return true;
		}

		virtual bool isUserController() const
		{
			return false;
		}

		virtual float getValue(Controller::InputType inputType) const;      // 005ca420
		virtual void updateBuffer(float) = 0;

		virtual void onEvent(const RunService* source, Heartbeat event)     // 005cb280
		{
			updateBuffer(event.time);
		}
	};

	class AIChaseController : public AIController
	{
	protected:
		virtual void updateBuffer(float time);                              // 005cb080
	public:
		AIChaseController(const PVInstance* controlledInstance)             // 005cb990
			: AIController(controlledInstance)
		{
		}

		virtual Controller::ControllerType getControllerType() const
		{
			return AI_CHASE_CONTROLLER;
		}
	};

	class AIFleeController : public AIController
	{
	protected:
		virtual void updateBuffer(float time);                              // 005cb0e0
	public:
		AIFleeController(const PVInstance* controlledInstance)              // 005cb9b0
			: AIController(controlledInstance)
		{
		}

		virtual Controller::ControllerType getControllerType() const
		{
			return AI_FLEE_CONTROLLER;
		}
	};
}
