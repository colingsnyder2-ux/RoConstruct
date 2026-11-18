#undef _RELEASEASSERT
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8world/World.h"

namespace RBX
{
	bool JointInstance::shouldRender3dAdorn() const
	{
		return PartInstance::showSpanningTree;
	}

	PartInstance* JointInstance::getPart0() const
	{
		return part[0].lock().get();
	}

	PartInstance* JointInstance::getPart1() const
	{
		return part[1].lock().get();
	}

	bool JointInstance::askSetParent(const Instance* instance) const
	{
		return instance->getDescriptor() == Instance::classDescriptor()
			|| instance->getDescriptor() == PartInstance::classDescriptor();
	}

	void JointInstance::render3dAdorn(Adorn* adorn)
	{
		if (Joint::getJointType(joint) >= Joint::ANCHOR_JOINT)
		{
			G3D::Color3 color3;

			Primitive* prim0 = getPart0() ? getPart0()->getPrimitive() : NULL;
			Primitive* prim1 = getPart1() ? getPart1()->getPrimitive() : NULL;

			G3D::Vector3 vec0 = prim0
				? prim0->getCoordinateFrame().translation
				: G3D::Vector3::zero();

			G3D::Vector3 vec1 = prim1
				? prim1->getCoordinateFrame().translation
				: G3D::Vector3::zero();

			if (joint->getActive())
				color3 = G3D::Color3::green();
			else
				color3 = G3D::Color3::red();

			adorn->setObjectToWorldMatrix(G3D::CoordinateFrame());

			G3D::Color4 color4(color3);
			adorn->lineSegment(
				G3D::LineSegment::fromTwoPoints(vec0, vec1),
				color4,
				20.0);
		}
	}

	JointInstance::JointInstance(Joint* joint)
		: joint(joint)
	{
		joint->setJointOwner(this);

		PartInstance* part0 = PartInstance::fromPrimitive(joint->getPrimitive(0));
		PartInstance* part1 = PartInstance::fromPrimitive(joint->getPrimitive(1));

		part[0] = shared_from(part0);
		part[1] = shared_from(part1);
	}

	JointInstance::~JointInstance()
	{
		setPart(0, NULL);
		setPart(1, NULL);

		joint->setJointOwner(NULL);
		delete joint;
		joint = NULL;
	}

	void JointInstance::setPart(int i, PartInstance* value)
	{
		if (part[i].lock().get() != value)
		{
			Primitive* ptr;

			part[i] = shared_from(value);

			if (value)
				ptr = value->getPrimitive();
			else
				ptr = NULL;

			joint->setPrimitive(i, ptr);
		}
	}

	void JointInstance::onAncestorChanged(const AncestorChanged& event)
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
				oldWorld->removeJoint(joint);

			if (wsWorld)
				wsWorld->insertJoint(joint);
		}
	}
}

#include "v8world/GlueJoint.h"
#include "v8world/RotateJoint.h"

#define NATIVE_MOTOR_JOINT_DONOR_BASE
#include "v8world/Joints2008.h"

static RBX::Reflection::PropDescriptor<RBX::Motor, float> prop_MaxVelocity("MaxVelocity", "Data", &RBX::Motor::getMaxVelocity, &RBX::Motor::setMaxVelocity, RBX::Reflection::PropertyDescriptor::STANDARD);

namespace RBX {
Glue::Glue(Joint* joint) : DescribedCreatable<Glue, AutoJoint, sGlue>(joint) { }
Glue::Glue() : DescribedCreatable<Glue, AutoJoint, sGlue>(new GlueJoint()) { }
Rotate::Rotate(Joint* joint) : DescribedCreatable<Rotate, AutoJoint, sRotate>(joint) { }
Rotate::Rotate() : DescribedCreatable<Rotate, AutoJoint, sRotate>(new RotateJoint()) { }
RotateP::RotateP(Joint* joint)
    : DescribedCreatable<RotateP, AutoJoint, sRotateP>(joint)
{
}
RotateV::RotateV(Joint* joint) : DescribedCreatable<RotateV, AutoJoint, sRotateV>(joint)
{
}
Motor::Motor(Joint* joint) : DescribedCreatable<Motor, AutoJoint, sMotor>(joint) { }

float Motor::getMaxVelocity() const
{
	return static_cast<MotorJoint*>(joint)->maxVelocity;
}

void Motor::setMaxVelocity(float value)
{
	if (value != getMaxVelocity())
	{
		static_cast<MotorJoint*>(joint)->maxVelocity = value;
		raisePropertyChanged(prop_MaxVelocity);
	}
}
}
