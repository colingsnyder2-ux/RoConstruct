// 2008-06 native RBX::ControllerService and controllers (inactive); evidence in
// native-headers/v8datamodel/UserController.h. Verified by tests/record_native_user_controller.py.
// Unit profile: document-swap flags plus /fp:fast (x87 constant folding in chaseTarget/updateTarget and the keyboard
// getValue bodies).
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// UserController | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src c0b8003f | roc native-status --write
#include "v8datamodel/UserController.h"
#include "v8datamodel/PVInstance.h"
#include "util/Math.h"
#include <G3D/Vector3.h>

namespace RBX
{
	char sControllerService[] = "ControllerService"; // 009510b4

	// Template members the shared headers only declare (same definitions as TimerService.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

#pragma warning (push)
#pragma warning (disable : 4355) // warning C4355: 'this' : used in base member initializer list

	ControllerService::ControllerService()
		: playerController(NULL),
		  hardwareDevice(NULL),
		  keyboardPrimaryController(new KeyboardPrimaryController(this)),
		  keyboardSecondaryController(new KeyboardSecondaryController(this)),
		  nullController(new NullController)
	{
	}

#pragma warning (pop)

	G3D::ReferenceCountedPointer<Controller> ControllerService::getController(Controller::ControllerType type, const PVInstance* controlledInstance)
	{
		switch (type)
		{
		case Controller::PLAYER_CONTROLLER:
			return new PlayerController(this, controlledInstance);

		case Controller::PRIMARY_CONTROLLER:
			return keyboardPrimaryController;

		case Controller::SECONDARY_CONTROLLER:
			return keyboardSecondaryController;

		case Controller::AI_CHASE_CONTROLLER:
			return new AIChaseController(controlledInstance);

		case Controller::AI_FLEE_CONTROLLER:
			return new AIFleeController(controlledInstance);

		default:
			return nullController;
		}
	}

	const UserInputBase* HardwareController::getHardwareDevice() const
	{
		return controllerService ? controllerService->getHardwareDevice() : NULL;
	}

#ifdef NATIVE_USER_CONTROLLER_PENDING
	// Both bodies inline UserInputBase::altKeyDown (keyDown RALT/LALT through the cached device) and call an
	// out-of-line ctrlKeyDown (0045aec0) on a re-fetched device; the out-of-line altKeyDown copy 005ca390 of this
	// unit shows alt/ctrl were inline header members in 2008 (the donor util/UserInputBase.h declares them out of
	// line): pending on that header.
	float KeyboardPrimaryController::getValue(Controller::InputType inputType) const
	{
		if (!getHardwareDevice())
			return 0.0f;
		const UserInputBase* hardware = getHardwareDevice();

		switch (inputType)
		{
		case Controller::UP_DOWN_INPUT:
			return hardware->keyDown(SDLK_SPACE) ? 1.0f : 0.0f;
		case Controller::BUTTON_1_INPUT:
			return hardware->keyDown(SDLK_1) ? 1.0f : 0.0f;
		case Controller::BUTTON_2_INPUT:
			return hardware->keyDown(SDLK_2) ? 1.0f : 0.0f;
		case Controller::BUTTON_3_INPUT:
			return hardware->keyDown(SDLK_3) ? 1.0f : 0.0f;
		case Controller::BUTTON_4_INPUT:
			return hardware->keyDown(SDLK_4) ? 1.0f : 0.0f;
		case Controller::BUTTON_3_4_INPUT:
			return hardware->keyDown(SDLK_3) ? 1.0f : (getHardwareDevice()->keyDown(SDLK_4) ? -1.0f : 0.0f);
		default:
			break;
		}

		if (hardware->altKeyDown())
			return 0.0f;
		if (getHardwareDevice()->ctrlKeyDown())
			return 0.0f;

		bool forward = getHardwareDevice()->keyDown(SDLK_u);
		bool backward = getHardwareDevice()->keyDown(SDLK_j);
		bool left = getHardwareDevice()->keyDown(SDLK_h);
		bool right = getHardwareDevice()->keyDown(SDLK_k);

		switch (inputType)
		{
		case Controller::RIGHT_LEFT_INPUT:
			return left ? 1.0f : (right ? -1.0f : 0.0f);
		case Controller::BACK_FORWARD_INPUT:
			return forward ? 1.0f : (backward ? -1.0f : 0.0f);
		case Controller::LEFT_TRACK_INPUT:
			if ((forward && !left) || (right && !backward) || (forward && right))
				return 1.0f;
			if ((backward && !right) || (left && !forward) || (backward && left))
				return -1.0f;
			return 0.0f;
		case Controller::RIGHT_TRACK_INPUT:
			if ((forward && !right) || (left && !backward) || (forward && left))
				return 1.0f;
			if ((backward && !left) || (right && !forward) || (backward && right))
				return -1.0f;
			return 0.0f;
		default:
			return 0.0f;
		}
	}

	float KeyboardSecondaryController::getValue(Controller::InputType inputType) const
	{
		if (!getHardwareDevice())
			return 0.0f;
		const UserInputBase* hardware = getHardwareDevice();

		switch (inputType)
		{
		case Controller::UP_DOWN_INPUT:
			return hardware->keyDown(SDLK_RSHIFT) ? 1.0f : 0.0f;
		default:
			break;
		}

		if (hardware->altKeyDown())
			return 0.0f;
		if (getHardwareDevice()->ctrlKeyDown())
			return 0.0f;

		bool forward = getHardwareDevice()->keyDown(SDLK_w);
		bool backward = getHardwareDevice()->keyDown(SDLK_s);
		bool left = getHardwareDevice()->keyDown(SDLK_a);
		bool right = getHardwareDevice()->keyDown(SDLK_d);

		switch (inputType)
		{
		case Controller::RIGHT_LEFT_INPUT:
			return left ? 1.0f : (right ? -1.0f : 0.0f);
		case Controller::BACK_FORWARD_INPUT:
			return forward ? 1.0f : (backward ? -1.0f : 0.0f);
		case Controller::LEFT_TRACK_INPUT:
			if ((forward && !left) || (right && !backward) || (forward && right))
				return 1.0f;
			if ((backward && !right) || (left && !forward) || (backward && left))
				return -1.0f;
			return 0.0f;
		case Controller::RIGHT_TRACK_INPUT:
			if ((forward && !right) || (left && !backward) || (forward && left))
				return 1.0f;
			if ((backward && !left) || (right && !forward) || (backward && right))
				return -1.0f;
			return 0.0f;
		default:
			return 0.0f;
		}
	}
#endif

	AIController::AIController(const PVInstance* controlledInstance)
		: SteppingController(controlledInstance),
		  retargetTime(0.0f)
	{
		for (int i = 0; i < Controller::NUM_INPUT_TYPES; i++)
		{
			buffer[i] = 0.0f;
		}

		buffer[Controller::CONSTANT_INPUT] = 1.0f;
	}

	AIController::~AIController() {}

	float AIController::getValue(Controller::InputType inputType) const
	{
		return buffer[inputType];
	}

	void AIController::chaseTarget(const G3D::Vector3& localChasePoint)
	{
		float chaseAngle = atan2f(-localChasePoint.x, -localChasePoint.z);
		float leftInput, rightInput;

		if (chaseAngle > Math::pi() * 144.0f/360.0f)
		{
			leftInput = -0.9f;
			rightInput = 0.9f;
		}
		else if (chaseAngle < Math::pi() * -144.0f/360.0f)
		{
			leftInput = 0.9f;
			rightInput = -0.9f;
		}
		else if (chaseAngle > Math::pi() * 54.0/360.0)
		{
			leftInput = 0.0f;
			rightInput = 0.9f;
		}
		else if (chaseAngle < Math::pi() * -54.0/360.0)
		{
			leftInput = 0.9f;
			rightInput = 0.0f;
		}
		else
		{
			leftInput = 0.9f;
			rightInput = 0.9f;
		}

		buffer[Controller::LEFT_TRACK_INPUT] = leftInput;
		buffer[Controller::RIGHT_TRACK_INPUT] = rightInput;
		buffer[Controller::RIGHT_LEFT_INPUT] = chaseAngle * (1.0f/Math::pi());
		buffer[Controller::BACK_FORWARD_INPUT] = localChasePoint.z < 0.0f ? 0.9f : 0.0f;
	}

	G3D::Vector3 AIController::getLocalTargetPosition() const
	{
		G3D::Vector3 result;

		boost::shared_ptr<const PVInstance> lockPV = controlledInstance.lock();
		boost::shared_ptr<const PVInstance> lockTarget = target.lock();

		if (lockPV && lockTarget)
		{
			G3D::CoordinateFrame controlledCoord = lockPV->getLocation();
			G3D::Vector3 targetLoc = lockTarget->getLocation().translation;

			result = controlledCoord.pointToObjectSpace(targetLoc);
		}

		return result;
	}

	void AIController::updateTarget(Controller::ControllerType excludeType, float time)
	{
		if (time < retargetTime)
			return;

		retargetTime = time + G3D::uniformRandom(1.0f, 3.0f);

		boost::shared_ptr<const PVInstance> pvLock = controlledInstance.lock();
		if (!pvLock)
			return;

		const PVInstance* pvRoot = pvLock->getTypedRoot<PVInstance>();
		if (!pvRoot)
			return;

		float bestDistance = 1e+20f;
		G3D::CoordinateFrame controlledCoord = pvLock->getLocation();

		for (size_t i = 0; i < pvRoot->numChildren(); i++)
		{
			// The donor's Instance::queryTypedChild<PVInstance>((int)i), which the native Instance.h does not declare.
			const PVInstance* current = dynamic_cast<const PVInstance*>((*pvRoot->children)[(int)i].get());

			if (current && current != pvLock.get() && current->isChaseable() &&
				current->getTopPVController()->getControllerType() != excludeType)
			{
				float distance = (current->getLocation().translation - controlledCoord.translation).magnitude();
				if (distance < bestDistance)
				{
					bestDistance = distance;
					target = shared_from(current);
				}
			}
		}
	}

	void AIChaseController::updateBuffer(float time)
	{
		updateTarget(Controller::AI_CHASE_CONTROLLER, time);

		if (!target.expired())
		{
			chaseTarget(getLocalTargetPosition());
		}
		else
		{
			buffer[Controller::LEFT_TRACK_INPUT] = -1.0f;
			buffer[Controller::RIGHT_TRACK_INPUT] = 1.0f;
			buffer[Controller::RIGHT_LEFT_INPUT] = 1.0f;
		}
	}

	// 005cb0e0 (exact under the unit profile /fp:fast; /fp:precise breaks chaseTarget 005ca430).
	void AIFleeController::updateBuffer(float time)
	{
		updateTarget(Controller::AI_FLEE_CONTROLLER, time);

		if (!target.expired())
		{
			chaseTarget(-getLocalTargetPosition());
		}
	}

	SteppingController::SteppingController(const PVInstance* _controlledInstance)
		: runService(shared_from(ServiceProvider::create<RunService>(_controlledInstance))),
		  controlledInstance(shared_from(_controlledInstance))
	{
		Notifier<RunService, Heartbeat>::connect(runService, this);
	}

	SteppingController::~SteppingController()
	{
		Notifier<RunService, Heartbeat>::disconnect(runService, this);
	}

	PlayerController::PlayerController(ControllerService* _controllerService, const PVInstance* _controlledInstance)
		: SteppingController(_controlledInstance),
		  controllerService(shared_from(_controllerService)),
		  stepsRotating(0)
	{
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::ComputeProp<G3D::ReferenceCountedPointer<RBX::Controller>,RBX::PVInstance>;
template class boost::shared_ptr<RBX::PVInstance const >;
template class boost::weak_ptr<RBX::ControllerService>;

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sControllerService>();
