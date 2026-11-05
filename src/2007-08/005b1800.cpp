// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_jointinstance_37f5c4b386b260dd.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/Edge.h", "../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp")
#pragma include_alias(<v8world/Edge.h>, <../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp>)
#pragma include_alias("v8world/Contact.h", "../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp")
#pragma include_alias(<v8world/Contact.h>, <../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp>)
#define _MT 1
#undef _DLL
#pragma include_alias("v8kernel/KernelIndex.h", "../roc_espeon_aug2007_kernelindex_header_d7778b4d74bcf4c0.cpp")
#pragma include_alias("v8kernel/Body.h", "../roc_espeon_aug2007_body_header_b251c002665e01af.cpp")
#pragma include_alias("util/Extents.h", "../roc_espeon_aug2007_extents_inline_58e475d56d206314.cpp")
#pragma include_alias("reflection/object.h", "../roc_espeon_aug2007_describedbase_e64c736f24da029d.cpp")
#pragma include_alias("util/Debug.h", "../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp")
#pragma include_alias(<util/Debug.h>, <../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp>)
#pragma include_alias("util/Events.h", "../roc_espeon_aug2007_datamodel_header_e4d5a36bea2e4f16.cpp")
#pragma include_alias("reflection/reflection.h", "../roc_espeon_aug2007_described_inline_3639f053c7370446.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_header_7a4c998b489b0ddf.cpp")
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
#pragma include_alias("util/IRenderable.h", "../roc_espeon_aug2007_irenderable_header_89bd00a76e9b5599.cpp")
#pragma include_alias(<util/IRenderable.h>, <../roc_espeon_aug2007_irenderable_header_89bd00a76e9b5599.cpp>)
#pragma include_alias("v8datamodel/JointInstance.h", "../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp")
#pragma include_alias(<v8datamodel/JointInstance.h>, <../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp>)
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Feature.h"
#include "v8world/Joint.h"
#include "v8world/SnapJoint.h"
#include "v8world/WeldJoint.h"
#include "v8world/GlueJoint.h"
#include "v8world/RotateJoint.h"
#include "v8world/MotorJoint.h"
#include "util/Debug.h"

static RBX::Reflection::PropDescriptor<RBX::AutoJoint, RBX::PartInstance*> prop_Part0("Part0", "Data", &RBX::AutoJoint::getPart0, &RBX::AutoJoint::setPart0, RBX::Reflection::PropertyDescriptor::LEGACY); 
static RBX::Reflection::PropDescriptor<RBX::AutoJoint, RBX::PartInstance*> prop_Part1("Part1", "Data", &RBX::AutoJoint::getPart1, &RBX::AutoJoint::setPart1, RBX::Reflection::PropertyDescriptor::LEGACY); 

static RBX::Reflection::PropDescriptor<RBX::AutoJoint, G3D::CoordinateFrame> prop_C1("C1", "Data", &RBX::AutoJoint::getC1, &RBX::AutoJoint::setC1, RBX::Reflection::PropertyDescriptor::LEGACY);
static RBX::Reflection::PropDescriptor<RBX::AutoJoint, G3D::CoordinateFrame> prop_C0("C0", "Data", &RBX::AutoJoint::getC0, &RBX::AutoJoint::setC0, RBX::Reflection::PropertyDescriptor::LEGACY);

// TODO: check that Motor::getMaxVelocity gets linked as VelocityMotor::getMaxVelocity
static RBX::Reflection::PropDescriptor<RBX::Motor, float> prop_MaxVelocity("MaxVelocity", "Data", &RBX::Motor::getMaxVelocity, &RBX::Motor::setMaxVelocity, RBX::Reflection::PropertyDescriptor::LEGACY);
static RBX::Reflection::PropDescriptor<RBX::Motor, float> prop_DesiredAngle("DesiredAngle", "Data", &RBX::Motor::getDesiredAngle, &RBX::Motor::setDesiredAngle, RBX::Reflection::PropertyDescriptor::LEGACY);
static RBX::Reflection::PropDescriptor<RBX::Motor, float> prop_CurrentAngle("CurrentAngle", "Data", &RBX::Motor::getCurrentAngle, &RBX::Motor::setCurrentAngle, RBX::Reflection::PropertyDescriptor::LEGACY);

namespace RBX
{
	const char* sJointInstance = "JointInstance";

	JointInstance::JointInstance(Joint* joint)
		: joint(joint)
	{
		joint->association().get<JointInstance*>() = this;
	}

	JointInstance::~JointInstance()
	{
		RBXASSERT(getParent() == NULL);
		RBXASSERT(joint->getWorld() == NULL);

		joint->association().remove<JointInstance*>();
		delete joint;
		joint = NULL;
	}

	bool JointInstance::shouldRender3dAdorn() const
	{
		return PartInstance::showSpanningTree;
	}

// Later rendering implementation uses absent Joint::active; omitted, no stub.
	const char* sAutoJoint = "AutoJoint";

	AutoJoint::AutoJoint(Joint* _joint)
		: DescribedNonCreatable(_joint)
	{
		PartInstance* part0 = PartInstance::fromPrimitive(joint->getPrimitive(0));
		PartInstance* part1 = PartInstance::fromPrimitive(joint->getPrimitive(1));

		part[0] = shared_from(part0);
		part[1] = shared_from(part1);
	}

	AutoJoint::~AutoJoint()
	{
		setPart(0, NULL);
		setPart(1, NULL);
	}

	PartInstance* AutoJoint::getPart0() const
	{
		return part[0].get();
	}

	PartInstance* AutoJoint::getPart1() const
	{
		return part[1].get();
	}

	void AutoJoint::setPart0(PartInstance* value)
	{
		setPart(0, value);
		raisePropertyChanged(prop_Part0);
	}

	void AutoJoint::setPart1(PartInstance* value)
	{
		setPart(1, value);
		raisePropertyChanged(prop_Part1);
	}

	bool AutoJoint::askSetParent(const Instance* instance) const
	{
		return instance->getDescriptor() == Instance::classDescriptor()
				|| instance->getDescriptor() == PartInstance::classDescriptor();
	}

	void AutoJoint::onAncestorChanged(const AncestorChanged& event)
	{
		Instance::onAncestorChanged(event);

		World* oldWorld = joint->getWorld();
		World* wsWorld;

		Instance* parent = getParent();

		if (parent && parent->getDescriptor() == Instance::classDescriptor())
		{
			Workspace* workspace = ServiceProvider::find<Workspace>(this);

			if (workspace)
				wsWorld = workspace->getWorld();
			else
				wsWorld = NULL;
		}
		else
		{
			wsWorld = Workspace::getWorldIfInWorkspace(this);
		}

		if (oldWorld != wsWorld)
		{
			if (oldWorld)
			{
				oldWorld->removeJoint(joint);
				RBXASSERT(!joint->getWorld());
			}

			if (wsWorld)
			{
				wsWorld->insertJoint(joint);
				RBXASSERT(joint->getWorld());
			}
		}
	}

	void AutoJoint::setPart(int i, PartInstance* value)
	{
		if (part[i].get() != value)
		{
			RBX::Primitive* ptr;

			part[i] = RBX::shared_from(value);

			if (value)
				ptr = value->getPrimitive();
			else
				ptr = NULL;

			joint->setPrimitive(i, ptr);
		}
	}

	const G3D::CoordinateFrame& AutoJoint::getC0() const
	{
		return joint->getJointCoord(0);
	}

	void AutoJoint::setC0(const G3D::CoordinateFrame& value)
	{
		joint->setJointCoord(0, value);
		raisePropertyChanged(prop_C0);
	}

	const G3D::CoordinateFrame& AutoJoint::getC1() const
	{
		return joint->getJointCoord(1);
	}

	void AutoJoint::setC1(const G3D::CoordinateFrame& value)
	{
		joint->setJointCoord(1, value);
		raisePropertyChanged(prop_C1);
	}

	const char* sSnap = "Snap";

	Snap::Snap(Joint* joint)
		: DescribedCreatable(joint)
	{
		RBXASSERT(joint->getJointType() == Joint::SNAP_JOINT);
		setName("Snap");
	}

	Snap::Snap()
		: DescribedCreatable(new SnapJoint())
	{
		setName("Snap");
	}

	const char* sWeld = "Weld";

	Weld::Weld(Joint* joint)
		: DescribedCreatable(joint)
	{
		RBXASSERT(joint->getJointType() == Joint::WELD_JOINT);
	}

	Weld::Weld()
		: DescribedCreatable(new WeldJoint())
	{
	}

	const char* sGlue = "Glue";

	Glue::Glue(Joint* joint)
		: DescribedCreatable(joint)
	{
		RBXASSERT(joint->getJointType() == Joint::GLUE_JOINT);
	}

	Glue::Glue()
		: DescribedCreatable(new GlueJoint())
	{
	}

	const char* sRotate = "Rotate";

	Rotate::Rotate(Joint* joint)
		: DescribedCreatable(joint)
	{
		RBXASSERT(joint->getJointType() == Joint::ROTATE_JOINT);
	}

	Rotate::Rotate()
		: DescribedCreatable(new RotateJoint())
	{
	}

	const char* sRotateP = "RotateP";

	RotateP::RotateP(Joint* joint)
		: DescribedCreatable(joint)
	{
		RBXASSERT(joint->getJointType() == Joint::ROTATE_P_JOINT);
	}

	RotateP::RotateP()
		: DescribedCreatable(new RotatePJoint())
	{
	}

	const char* sRotateV = "RotateV";

	RotateV::RotateV(Joint* joint)
		: DescribedCreatable(joint)
	{
		RBXASSERT(joint->getJointType() == Joint::ROTATE_V_JOINT);
	}

	RotateV::RotateV()
		: DescribedCreatable(new RotateVJoint())
	{
	}

	const char* sMotor = "Motor";

	Motor::Motor(Joint* joint)
		: DescribedCreatable(joint)
	{
		RBXASSERT(joint->getJointType() == Joint::MOTOR_JOINT);
	}

	Motor::Motor()
		: DescribedCreatable(new MotorJoint())
	{
		setName("Motor");
	}

	float Motor::getMaxVelocity() const
	{
		return rbx_static_cast<MotorJoint*>(joint)->maxVelocity;
	}

	void Motor::setMaxVelocity(float value)
	{
		if (value != getMaxVelocity())
		{
			rbx_static_cast<MotorJoint*>(joint)->maxVelocity = value;
			raisePropertyChanged(prop_MaxVelocity);
		}
	}

	float Motor::getDesiredAngle() const
	{
		return rbx_static_cast<MotorJoint*>(joint)->desiredAngle;
	}

	void Motor::setDesiredAngle(float value)
	{
		if (value != getDesiredAngle())
		{
			rbx_static_cast<MotorJoint*>(joint)->desiredAngle = value;
			raisePropertyChanged(prop_DesiredAngle);
		}
	}

	float Motor::getCurrentAngle() const
	{
		return rbx_static_cast<MotorJoint*>(joint)->getCurrentAngle();
	}

	void Motor::setCurrentAngle(float value)
	{
		if (value != getCurrentAngle())
		{
			rbx_static_cast<MotorJoint*>(joint)->setCurrentAngle(value);
			raisePropertyChanged(prop_CurrentAngle);
		}
	}
}
