// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs roc_espeon_aug2007_character_balance_27892af76571a2d5.cpp

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
#pragma include_alias("util/UIEvent.h", "../roc_espeon_aug2007_uievent_viewport_header_04331f71cbc5bc08.cpp")
#pragma include_alias(<util/UIEvent.h>, <../roc_espeon_aug2007_uievent_viewport_header_04331f71cbc5bc08.cpp>)
#pragma include_alias("v8datamodel/Workspace.h", "../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp")
#pragma include_alias(<v8datamodel/Workspace.h>, <../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp>)
#pragma include_alias("v8datamodel/ICharacterSubject.h", "../roc_espeon_aug2007_character_state_f342eee04d017582.cpp")
#pragma include_alias(<v8datamodel/ICharacterSubject.h>, <../roc_espeon_aug2007_character_state_f342eee04d017582.cpp>)
#pragma include_alias("humanoid/Humanoid.h", "../roc_espeon_aug2007_humanoid_state_f78ef0aa0660622a.cpp")
#pragma include_alias(<humanoid/Humanoid.h>, <../roc_espeon_aug2007_humanoid_state_f78ef0aa0660622a.cpp>)
#pragma include_alias("humanoid/Running.h", "../roc_espeon_aug2007_running_balance_hook_875f0bb95aec50f5.cpp")
#pragma include_alias(<humanoid/Running.h>, <../roc_espeon_aug2007_running_balance_hook_875f0bb95aec50f5.cpp>)
#pragma include_alias("humanoid/Balancing.h", "../roc_espeon_aug2007_balancing_balance_hook_37ced1d1de755090.cpp")
#pragma include_alias(<humanoid/Balancing.h>, <../roc_espeon_aug2007_balancing_balance_hook_37ced1d1de755090.cpp>)
#pragma include_alias("humanoid/FallingDown.h", "../roc_espeon_aug2007_fallingdown_state_7499778b68c8dff0.cpp")
#pragma include_alias(<humanoid/FallingDown.h>, <../roc_espeon_aug2007_fallingdown_state_7499778b68c8dff0.cpp>)
#pragma include_alias("humanoid/Flying.h", "../roc_espeon_aug2007_flying_balance_hook_a9eee8e762225c01.cpp")
#pragma include_alias(<humanoid/Flying.h>, <../roc_espeon_aug2007_flying_balance_hook_a9eee8e762225c01.cpp>)
#pragma include_alias("humanoid/Freefall.h", "../roc_espeon_aug2007_freefall_state_671ebe3411c8030d.cpp")
#pragma include_alias(<humanoid/Freefall.h>, <../roc_espeon_aug2007_freefall_state_671ebe3411c8030d.cpp>)
#pragma include_alias("humanoid/GettingUp.h", "../roc_espeon_aug2007_gettingup_balance_hook_972ad7ec2ed27c84.cpp")
#pragma include_alias(<humanoid/GettingUp.h>, <../roc_espeon_aug2007_gettingup_balance_hook_972ad7ec2ed27c84.cpp>)
#pragma include_alias("humanoid/Jumping.h", "../roc_espeon_aug2007_jumping_state_9af9b1e45a772018.cpp")
#pragma include_alias(<humanoid/Jumping.h>, <../roc_espeon_aug2007_jumping_state_9af9b1e45a772018.cpp>)
#pragma include_alias("humanoid/Seated.h", "../roc_espeon_aug2007_seated_state_df5e271a3b8e21cd.cpp")
#pragma include_alias(<humanoid/Seated.h>, <../roc_espeon_aug2007_seated_state_df5e271a3b8e21cd.cpp>)

#include "humanoid/Humanoid.h"
#include "humanoid/Running.h"
#include "humanoid/FallingDown.h"
#include "v8datamodel/Tool.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8world/World.h"
#include "Network/Players.h"
#include "AppDraw/DrawAdorn.h"

namespace RBX
{
	Reflection::PropDescriptor<Humanoid, G3D::Vector3> propWalkToPoint("WalkToPoint", "Control", &Humanoid::getWalkToPoint, &Humanoid::setWalkToPoint, Reflection::PropertyDescriptor::STREAMING);
	Reflection::PropDescriptor<Humanoid, G3D::Vector3> propWalkDirection("WalkDirection", "Control", &Humanoid::getWalkDirection, &Humanoid::setWalkDirection, Reflection::PropertyDescriptor::STREAMING);
	Reflection::PropDescriptor<Humanoid, bool> propJump("Jump", "Control", &Humanoid::getJump, &Humanoid::setJump, Reflection::PropertyDescriptor::STREAMING);
	Reflection::PropDescriptor<Humanoid, G3D::Vector3> propTargetPoint("TargetPoint", "Control", &Humanoid::getTargetPoint, &Humanoid::setTargetPoint, Reflection::PropertyDescriptor::STREAMING);
	Reflection::PropDescriptor<Humanoid, bool> propSit("Sit", "Control", &Humanoid::getSit, &Humanoid::setSit, Reflection::PropertyDescriptor::STREAMING);

	Reflection::BoundFuncDesc<Humanoid, void(G3D::Vector3, boost::shared_ptr<Instance>), 2> func_MoveTo(&Humanoid::moveTo2, "MoveTo", "location", "part", Reflection::FunctionDescriptor::AnyCaller);

	Reflection::RefPropDescriptor<Humanoid, PartInstance> propTorso("Torso", "Data", &Humanoid::getTorso, &Humanoid::setTorso, Reflection::PropertyDescriptor::STANDARD);
	Reflection::RefPropDescriptor<Humanoid, PartInstance> propLeftLeg("LeftLeg", "Data", &Humanoid::getLeftLeg, &Humanoid::setLeftLeg, Reflection::PropertyDescriptor::STANDARD);
	Reflection::RefPropDescriptor<Humanoid, PartInstance> propRightLeg("RightLeg", "Data", &Humanoid::getRightLeg, &Humanoid::setRightLeg, Reflection::PropertyDescriptor::STANDARD);
	Reflection::RefPropDescriptor<Humanoid, PartInstance> propWalkToPart("WalkToPart", "Control", &Humanoid::getWalkToPart, &Humanoid::setWalkToPart, Reflection::PropertyDescriptor::STREAMING);

	Humanoid::Humanoid()
		: health(100.0f),
		  maxHealth(100.0f),
		  walkMode(DIRECTION_MOVE),
		  walkTimer(0),
		  jump(false),
		  imDead(false),
		  hadHeadJoint(false),
		  sit(false),
		  world(NULL)
	{
		setName("Humanoid");
	}

	Humanoid::~Humanoid() 
	{
		RBXASSERT(!world);
	}

	PartInstance* Humanoid::getHeadFromCharacter(const ModelInstance* character)
	{
		return character ? dynamic_cast<PartInstance*>(character->findFirstChildByName("Head")) : NULL;
	}

	G3D::CoordinateFrame Humanoid::getTopOfHead() const
	{
		return G3D::CoordinateFrame(G3D::Vector3(0.0f, 0.5f, 0.0f));
	}

	void Humanoid::renderWaypoint(Adorn* adorn, const G3D::Vector3& waypoint)
	{
		DrawAdorn::cylinder(adorn, G3D::CoordinateFrame(waypoint), 1, 0.2f, 1.0f, G3D::Color3::green());
	}

	ContactManager* Humanoid::getContactManager()
	{
		World* world = Workspace::getWorldIfInWorkspace(this);
		return world ? &world->getContactManager() : NULL;
	}

	PartInstance* Humanoid::getLocalHeadFromContext(const Instance* context)
	{
		return getHeadFromCharacter(Network::Players::findLocalCharacter(context));
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


	bool Humanoid::hasWalkToPoint(G3D::Vector3& worldPosition) const
	{
		if (walkToPart && Workspace::findWorkspace(this) && Workspace::contextInWorkspace(walkToPart.get()))
		{
			worldPosition = walkToPart->getCoordinateFrame().pointToWorldSpace(walkToPoint);
			return true;
		}
		else
		{
			return false;
		}
	}

	G3D::CoordinateFrame Humanoid::getRightArmGrip() const
	{
		G3D::CoordinateFrame cframe;
		cframe.lookAt(G3D::Vector3(0.0f, -1.0f, 0.0f), G3D::Vector3(0.0f, 0.0f, -1.0f));
		cframe.translation = G3D::Vector3(0.0f, -1.0f, 0.0f);

		return cframe;
	}

	PartInstance* Humanoid::findRightArm() const
	{
		return getParent() ? rbx_static_cast<PartInstance*>(getParent()->findFirstChildByName("Right Arm")) : NULL;
	}

	JointInstance* Humanoid::findRightShoulder() const
	{
		PartInstance* torso = getTorso();
		return torso ? rbx_static_cast<JointInstance*>(torso->findFirstChildByName("Right Shoulder")) : NULL;
	}

	void Humanoid::computeForce(const float dt, bool throttling)
	{
		if (currentState.get())
			currentState->onComputeForce(dt);
	}

	void Humanoid::onAncestorChanged(const AncestorChanged& event)
	{
		World* worldInWorkspace = Workspace::getWorldIfInWorkspace(this);
		if (worldInWorkspace != world)
		{
			currentState.reset();
			if (world)
			{
				world->getKernel().removeConnector2ndPass(this);
			}

			world = worldInWorkspace;
			if (world)
			{
				setState(new Running(this));
				world->getKernel().insertConnector2ndPass(this);
			}
		}

		Instance::onAncestorChanged(event);
	}

	

	Humanoid* Humanoid::modelIsCharacter(const Instance* testModel)
	{
		return testModel ? testModel->findFirstChildOfType<Humanoid>() : NULL;
	}

	Humanoid* Humanoid::getLocalHumanoidFromContext(const Instance* context)
	{
		ModelInstance* character = Network::Players::findLocalCharacter(context);
		return character ? character->findFirstChildOfType<Humanoid>() : NULL;
	}

	void Humanoid::render3dAdorn(Adorn* adorn)
	{
		if (walkMode == CLICK_TO_MOVE)
		{
			if (this == modelIsCharacter(Network::Players::findLocalCharacter(this)) && Workspace::findWorkspace(this))
			{
				G3D::Vector3 worldPosition;
				if (hasWalkToPoint(worldPosition))
					renderWaypoint(adorn, worldPosition);
			}
		}
	}

	PartInstance* Humanoid::getHead() const
	{
		if (!head && getParent())
			head = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Head"));

		return head.get();
	}

	PartInstance* Humanoid::getTorso() const
	{
		if (!torso && getParent())
			torso = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Torso"));

		return torso.get();
	}

	PartInstance* Humanoid::getLeftLeg() const
	{
		if (!leftLeg && getParent())
			leftLeg = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Left Leg"));

		return leftLeg.get();
	}

	PartInstance* Humanoid::getRightLeg() const
	{
		if (!rightLeg && getParent())
			rightLeg = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Right Leg"));

		return rightLeg.get();
	}

	PartInstance* Humanoid::getLeftArm() const
	{
		if (!leftArm && getParent())
			leftArm = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Left Arm"));

		return leftArm.get();
	}

	PartInstance* Humanoid::getRightArm() const
	{
		if (!rightArm && getParent())
			rightArm = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Right Arm"));

		return rightArm.get();
	}

	Primitive* Humanoid::getHeadPrimitive()
	{
		PartInstance* part = getHead();
		return part ? part->getPrimitive() : NULL;
	}

	Primitive* Humanoid::getTorsoPrimitive() const
	{
		PartInstance* part = getTorso();
		return part ? part->getPrimitive() : NULL;
	}

	Primitive* Humanoid::getLeftLegPrimitive()
	{
		PartInstance* part = getLeftLeg();
		return part ? part->getPrimitive() : NULL;
	}

	Primitive* Humanoid::getRightLegPrimitive()
	{
		PartInstance* part = getRightLeg();
		return part ? part->getPrimitive() : NULL;
	}

	Body* Humanoid::getTorsoBody()
	{
		PartInstance* part = getTorso();
		return part ? part->getPrimitive()->getBody() : NULL;
	}

	Body* Humanoid::getRootBody()
	{
		Body* body = getTorsoBody();
		return body ? body->getRoot() : NULL;
	}

	float Humanoid::getTorsoHeading() const
	{
		if (Primitive* primitive = getTorsoPrimitive())
		{
			return Math::getHeading(primitive->getCoordinateFrame().lookVector());
		}
		else
		{
			return 0.0f;
		}
	}

	void Humanoid::checkForJointDeath()
	{
		if (Primitive* headPrimitive = getHeadPrimitive())
		{
			if (Primitive* torsoPrimitive = getTorsoPrimitive())
			{
				for (Joint* current = headPrimitive->getFirstJoint(); current != NULL; current = headPrimitive->getNextJoint(current))
				{
					if (current->otherPrimitive(headPrimitive) == torsoPrimitive)
					{
						hadHeadJoint = true;
						return;
					}
				}
			}
		}

		if (hadHeadJoint)
		{
			propHealth.setValue(this, 0.0f);
		}
	}

	void Humanoid::onEvent(const RunService* source, Stepped event)
	{
		if (currentState.get())
		{
			if (getParent())
			{
				State* prevState = currentState.get();
				PVInstance* parent = static_cast<PVInstance*>(getParent());

				setState(prevState->onStep(*parent->getTopPVController()));
			}

			if (getTorsoPrimitive())
			{
				getTorsoPrimitive()->setCanSleep(currentState->canSleep());
			}
		}

		checkForJointDeath();

		if (walkTimer > 0)
		{
			walkTimer--;
			if (walkTimer == 0)
				walkMode = DIRECTION_MOVE;
		}
	}

	const G3D::CoordinateFrame Humanoid::getLocation() const
	{
		return getHead() ? getHead()->getCoordinateFrame() : G3D::CoordinateFrame();
	}

	G3D::Vector3 Humanoid::getIntendedMovementVector()
	{
		return getIntendedMovementVector(false);
	}

	G3D::Vector3 Humanoid::updateWalkDirection()
	{
		return getIntendedMovementVector(true);
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

	static void breakJoints(Instance* instance)
	{
		PartInstance* part = dynamic_cast<PartInstance*>(instance);
		if (!part)
			instance->for_eachChild(&breakJoints);
		else
			part->destroyJoints();
	}

	void Humanoid::onChangedHealth(const Reflection::PropertyDescriptor&)
	{
		health = G3D::clamp(health, 0.0f, maxHealth);

		if (health == 0.0f && !imDead)
		{
			imDead = true;
			setState(new FallingDown(this, Math::inf()));

			if (getParent())
				getParent()->for_eachChild(breakJoints);

			event_Died.fire(this);
		}
	}

	void Humanoid::setState(State* value)
	{
		if (value != currentState.get())
			currentState.reset(value);
	}

	void Humanoid::moveTo(const G3D::Vector3& worldPosition, PartInstance* part)
	{
		if (part)
		{
			G3D::Vector3 local = part->getCoordinateFrame().pointToObjectSpace(worldPosition);

			walkToPoint = local + G3D::Vector3::unitX();
			walkToPart.reset();

			setWalkToPart(part);
			setWalkToPoint(local);
		}
	}

	void Humanoid::moveTo2(G3D::Vector3 worldPosition, boost::shared_ptr<Instance> part)
	{
		PartInstance* p = dynamic_cast<PartInstance*>(part.get());
		if (!p)
			throw std::runtime_error("Argument error: A Part is required");

		moveTo(worldPosition, p);
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

	void Humanoid::setWalkToPart(PartInstance* value)
	{
		if (walkToPart.get() != value)
		{
			walkToPart = shared_from(value);
			raisePropertyChanged(propWalkToPart);
		}

		walkMode = (walkMode == HAS_POINT) ? CLICK_TO_MOVE : HAS_PART;
		walkTimer = (walkMode == CLICK_TO_MOVE) ? 240 : 0;
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

	void Humanoid::setTargetPoint(const G3D::Vector3& value)
	{
		if (value != targetPoint)
		{
			targetPoint = value;
			raisePropertyChanged(propTargetPoint);
		}
	}

	void Humanoid::setLeftLeg(PartInstance* value)
	{
		if (leftLeg.get() != value)
		{
			leftLeg = shared_from(value);
			raisePropertyChanged(propLeftLeg);
		}
	}

	void Humanoid::setRightLeg(PartInstance* value)
	{
		if (rightLeg.get() != value)
		{
			rightLeg = shared_from(value);
			raisePropertyChanged(propRightLeg);
		}
	}

	void Humanoid::setTorso(PartInstance* value)
	{
		if (torso.get() != value)
		{
			torso = shared_from(value);
			raisePropertyChanged(propTorso);
		}
	}

	void Humanoid::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		Notifier<RunService, Stepped>::disconnect(ServiceProvider::create<RunService>(oldProvider), this);
		
		Instance::onServiceProvider(oldProvider, newProvider);

		Notifier<RunService, Stepped>::connect(ServiceProvider::create<RunService>(newProvider), this);

		if (newProvider && !oldProvider)
			onLocalHumanoidEnteringWorkspace();
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
				const G3D::CoordinateFrame& torsoCoord = torso->getCoordinateFrame();
				const G3D::Vector3& torsoPosition = torsoCoord.translation;

				G3D::Vector3 delta;
				delta.x = worldPosition.x - torsoPosition.x;
				delta.z = worldPosition.z - torsoPosition.z;
				delta.y = 0.0f;

				if (delta.magnitude() < 2.0f)
				{
					if (setWalkMode)
						walkMode = DIRECTION_MOVE;

					result = G3D::Vector3::zero();
				}
				else
				{
					result = delta.direction();
				}
			}
		}

		return result;
	}

	static void collectAllDescendantCharacterPrims(boost::shared_ptr<Instance> descendent, std::vector<Primitive*>& primitives)
	{
		if (PartInstance* part = dynamic_cast<PartInstance*>(descendent.get()))
		{
			primitives.push_back(part->getPrimitive());
		}
	}

	void Humanoid::getIgnorePrims(std::vector<const Primitive*>& ignore)
	{
		if (ModelInstance* character = getCharacterFromHumanoid(this))
			character->visitDescendents(boost::bind(&collectAllDescendantCharacterPrims, _1, boost::ref((std::vector<Primitive*>&)ignore)));
	}

	void Humanoid::tellCameraNear(float distance)
	{
		std::vector<Primitive*> primitives;
		if (ModelInstance* character = getCharacterFromHumanoid(this))
			character->visitDescendents(boost::bind(&collectAllDescendantCharacterPrims, _1, boost::ref(primitives)));

		float alphaModifier = 1.0f;
		if (distance < 3.0f)
		{
			alphaModifier = 0.0f;
		}
		else if (distance < 6.0f)
		{
			alphaModifier = 0.5f;
		}

		for (size_t i = 0; i < primitives.size(); i++)
		{
			PartInstance* part = PartInstance::fromPrimitive(primitives[i]);

			if (!dynamic_cast<Tool*>(part->getParent()))
			{
				part->setAlphaModifier(alphaModifier);
			}
		}
	}

	
    
	boost::shared_ptr<AutoJoint> newJoint(bool animated)
	{
		if (animated)
		{
			boost::shared_ptr<Motor> m = Creatable<Instance>::create<Motor>();
			m->setMaxVelocity(0.1f);
			return m;
		}
		else
		{
			boost::shared_ptr<Snap> s = Creatable<Instance>::create<Snap>();
			return s;
		}
	}

	void Humanoid::buildJoints()
	{
		ModelInstance* character = getCharacterFromHumanoid(this);
		RBXASSERT(character);

		if (!character)
			return;

		PartInstance* head = getHead();
		PartInstance* torso = getTorso();
		PartInstance* rightArm = getRightArm();
		PartInstance* leftArm = getLeftArm();
		PartInstance* rightLeg = getRightLeg();
		PartInstance* leftLeg = getLeftLeg();

		RBXASSERT(head && torso && rightArm && leftArm && rightLeg && leftLeg);

		if (!torso)
			return;

		head->getPrimitive()->getBody()->setCanThrottle(false);
		torso->getPrimitive()->getBody()->setCanThrottle(false);
		rightArm->getPrimitive()->getBody()->setCanThrottle(false);
		leftArm->getPrimitive()->getBody()->setCanThrottle(false);
		rightLeg->getPrimitive()->getBody()->setCanThrottle(false);
		leftLeg->getPrimitive()->getBody()->setCanThrottle(false);

		boost::shared_ptr<AutoJoint> rightShoulder = newJoint(true);
		boost::shared_ptr<AutoJoint> leftShoulder = newJoint(true);
		boost::shared_ptr<AutoJoint> rightHip = newJoint(true);
		boost::shared_ptr<AutoJoint> leftHip = newJoint(true);
		boost::shared_ptr<AutoJoint> neck = newJoint(false);

		rightShoulder->setName("Right Shoulder");
		leftShoulder->setName("Left Shoulder");
		rightHip->setName("Right Hip");
		leftHip->setName("Left Hip");
		neck->setName("Neck");

		rightShoulder->setPart0(torso);
		leftShoulder->setPart0(torso);
		rightHip->setPart0(torso);
		leftHip->setPart0(torso);
		neck->setPart0(torso);

		rightShoulder->setPart1(rightArm);
		leftShoulder->setPart1(leftArm);
		rightHip->setPart1(rightLeg);
		leftHip->setPart1(leftLeg);
		neck->setPart1(head);

		G3D::Matrix3 xPos = normalIdToMatrix3(NORM_X);
		G3D::Matrix3 xNeg = normalIdToMatrix3(NORM_X_NEG);
		G3D::Matrix3 yPos = normalIdToMatrix3(NORM_Y);

		G3D::CoordinateFrame rightShoulderP(xPos, G3D::Vector3(1.0f, 0.5f, 0.0f));
		G3D::CoordinateFrame leftShoulderP(xNeg, G3D::Vector3(-1.0f, 0.5f, 0.0f));
		G3D::CoordinateFrame rightHipP(xPos, G3D::Vector3(1.0f, -1.0f, 0.0f));
		G3D::CoordinateFrame leftHipP(xNeg, G3D::Vector3(-1.0f, -1.0f, 0.0f));
		G3D::CoordinateFrame neckP(yPos, G3D::Vector3(0.0f, 1.0f, 0.0f));

		G3D::CoordinateFrame rightArmP(xPos, G3D::Vector3(-0.5f, 0.5f, 0.0f));
		G3D::CoordinateFrame leftArmP(xNeg, G3D::Vector3(0.5f, 0.5f, 0.0f));
		G3D::CoordinateFrame rightLegP(xPos, G3D::Vector3(0.5f, 1.0f, 0.0f));
		G3D::CoordinateFrame leftLegP(xNeg, G3D::Vector3(-0.5f, 1.0f, 0.0f));
		G3D::CoordinateFrame headP(yPos, G3D::Vector3(0.0f, -0.5f, 0.0f));

		rightShoulder->setC0(rightShoulderP);
		leftShoulder->setC0(leftShoulderP);
		rightHip->setC0(rightHipP);
		leftHip->setC0(leftHipP);
		neck->setC0(neckP);

		rightShoulder->setC1(rightArmP);
		leftShoulder->setC1(leftArmP);
		rightHip->setC1(rightLegP);
		leftHip->setC1(leftLegP);
		neck->setC1(headP);

		rightShoulder->setParent(torso);
		leftShoulder->setParent(torso);
		rightHip->setParent(torso);
		leftHip->setParent(torso);
		neck->setParent(torso);
	}
}

namespace RBX { bool Humanoid::hasMovementIntent() const { return currentState.get() ? currentState->hasMovementIntent() : false; } }
