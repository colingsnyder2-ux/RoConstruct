// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_native_app_workspace_9a810c9c100cc9f3.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/Edge.h", "../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp")
#pragma include_alias(<v8world/Edge.h>, <../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp>)
#pragma include_alias("v8world/Contact.h", "../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp")
#pragma include_alias(<v8world/Contact.h>, <../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp>)
#define _MT 1
#define _DLL 1
#pragma include_alias("v8kernel/KernelIndex.h", "../roc_espeon_aug2007_kernelindex_header_d7778b4d74bcf4c0.cpp")
#pragma include_alias("v8kernel/Body.h", "../roc_espeon_aug2007_body_header_b251c002665e01af.cpp")
#pragma include_alias("util/Extents.h", "../roc_espeon_aug2007_extents_inline_58e475d56d206314.cpp")
#pragma include_alias("reflection/object.h", "../roc_espeon_aug2007_describedbase_e64c736f24da029d.cpp")
#pragma include_alias("util/Debug.h", "../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp")
#pragma include_alias(<util/Debug.h>, <../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp>)
#pragma include_alias("util/Events.h", "../roc_espeon_aug2007_datamodel_header_e4d5a36bea2e4f16.cpp")
#pragma include_alias("reflection/reflection.h", "../roc_espeon_aug2007_described_arg_header_14221fd67bb3ca43.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_flags_header_a6acc69782cd7c29.cpp")
#pragma include_alias("v8world/Primitive.h", "../roc_espeon_aug2007_primitive_trivial_header_ac300ff64c6fc5e6.cpp")
#pragma include_alias("v8datamodel/DataModel.h", "../roc_espeon_aug2007_datamodel_mutex_header_321a3c67de644a82.cpp")
#pragma include_alias("v8tree/Verb.h", "../roc_espeon_aug2007_datamodel_header_c06d28d1a6b724f6.cpp")
#pragma include_alias("util/Evaluator.h", "../roc_espeon_aug2007_datamodel_header_4ba4cf67c400aa66.cpp")
#pragma include_alias(<boost/signals/signal_template.hpp>, <../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp>)
#pragma include_alias("boost/signals/signal_template.hpp", "../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp")
#include "roc_espeon_boost133_header_d432d72f8740aec3.cpp"
#include "roc_espeon_boost133_header_d9eb4711b7fc841c.cpp"
#include "roc_espeon_boost133_signals_header_be197e98651271fa.cpp"

#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp>)
#pragma include_alias("v8world/IPipelined.h", "../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp")
#pragma include_alias(<v8world/IPipelined.h>, <../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp>)
#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp>)
#pragma include_alias("util/IRenderable.h", "../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp")
#pragma include_alias(<util/IRenderable.h>, <../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp>)
#pragma include_alias("v8datamodel/JointInstance.h", "../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp")
#pragma include_alias(<v8datamodel/JointInstance.h>, <../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp>)
#pragma include_alias("v8world/IMoving.h", "../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp")
#pragma include_alias(<v8world/IMoving.h>, <../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp>)
#pragma include_alias("v8kernel/IStage.h", "../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp")
#pragma include_alias(<v8kernel/IStage.h>, <../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp>)
#pragma include_alias("reflection/function.h", "../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp")
#pragma include_alias(<reflection/function.h>, <../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp>)
#pragma include_alias("reflection/member.h", "../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp")
#pragma include_alias(<reflection/member.h>, <../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp>)
#pragma include_alias("reflection/property.h", "../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp")
#pragma include_alias(<reflection/property.h>, <../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp>)
#pragma include_alias("reflection/signal.h", "../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp")
#pragma include_alias(<reflection/signal.h>, <../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp>)
#pragma include_alias("script/Script.h", "../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp")
#pragma include_alias(<script/Script.h>, <../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp>)
#pragma include_alias("util/ICameraSubject.h", "../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp")
#pragma include_alias(<util/ICameraSubject.h>, <../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp>)
#pragma include_alias("util/IControllable.h", "../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp")
#pragma include_alias(<util/IControllable.h>, <../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp>)
#pragma include_alias("util/ILocation.h", "../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp")
#pragma include_alias(<util/ILocation.h>, <../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp>)
#pragma include_alias("v8datamodel/ICameraOwner.h", "../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp")
#pragma include_alias(<v8datamodel/ICameraOwner.h>, <../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp>)
#pragma include_alias("v8datamodel/ICharacterSubject.h", "../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp")
#pragma include_alias(<v8datamodel/ICharacterSubject.h>, <../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp>)
#pragma include_alias("v8datamodel/IPrimaryPart.h", "../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp")
#pragma include_alias(<v8datamodel/IPrimaryPart.h>, <../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp>)
#pragma include_alias("v8datamodel/PVInstance.h", "../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp")
#pragma include_alias(<v8datamodel/PVInstance.h>, <../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp>)
#pragma include_alias("v8tree/Service.h", "../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp")
#pragma include_alias(<v8tree/Service.h>, <../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp>)
#pragma include_alias("util/UIEvent.h", "../roc_espeon_aug2007_uievent_header_3f3774ebe50da7af.cpp")
#pragma include_alias(<util/UIEvent.h>, <../roc_espeon_aug2007_uievent_header_3f3774ebe50da7af.cpp>)
#pragma include_alias("v8datamodel/Workspace.h", "../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp")
#pragma include_alias(<v8datamodel/Workspace.h>, <../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp>)
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/UserController.h"
#include "util/Math.h"
#include <G3D/Vector3.h>

namespace RBX
{

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

		RBXASSERT(lockPV);

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
			const PVInstance* current = pvRoot->queryTypedChild<PVInstance>((int)i);

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

	const UserInputBase* PlayerController::getHardwareDevice() const
	{
		RBXASSERT(!controllerService.expired());
		return controllerService.expired() ? NULL : controllerService.lock()->getHardwareDevice();
	}
}
