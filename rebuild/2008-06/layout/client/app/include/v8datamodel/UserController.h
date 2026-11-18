#pragma once
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
