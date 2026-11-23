// =============================================================================
// JointInstance.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/JointInstance.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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

static RBX::Reflection::RefPropDescriptor<RBX::AutoJoint, RBX::PartInstance> prop_Part0(
	"Part0",
	"Data",
	&RBX::AutoJoint::getPart0,
	&RBX::AutoJoint::setPart0,
	RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::RefPropDescriptor<RBX::AutoJoint, RBX::PartInstance> prop_Part1(
	"Part1",
	"Data",
	&RBX::AutoJoint::getPart1,
	&RBX::AutoJoint::setPart1,
	RBX::Reflection::PropertyDescriptor::STANDARD);

namespace RBX
{
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
}
