// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
#undef _RELEASEASSERT
// 2008-06 RBX::JointInstance IRenderable rows of the v8datamodel/JointInstance.cpp unit (inactive), built against the
// committed native v8datamodel/JointInstance.h (read-only; the getset factories of the same unit are in
// AppUnit5E0JointReflection.cpp): shouldRender3dAdorn 005e27a0.
//
// The 2008 JointInstance carries the AutoJoint parts (boost::weak_ptr<PartInstance> at +0x140 / +0x148, joint at
// +0x150; see native v8datamodel/JointInstance.h): part getters 005e2a10 / 005e2a70, askSetParent 005e3790 and
// render3dAdorn 005e2af0 (IRenderable +0x130 this; Primitive embedded in PartInstance at +0x228).
// Lifecycle rows: setPart 005e2cd0, JointInstance(Joint*) 005e3870, ~JointInstance 005e2e10 (both byte-identical with
// relocations masked; the identity registry names the +0 vtable 0083e354 ??_7JointInstance@RBX@@6B@, while this
// compile gives that unqualified name to the IRenderable vtable at +0x130, 0083e2bc, as VelocityMotor's 00842cbc), and
// onAncestorChanged 005e3a80 (the 2008 KERNEL_STAGE value through the opt-in kernel-stages IStage).
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8world/World.h"

namespace RBX
{
	// 005e27a0: reads PartInstance::showSpanningTree (00975f8f).
	bool JointInstance::shouldRender3dAdorn() const
	{
		return PartInstance::showSpanningTree;
	}

	// 005e2a10: locks part[0] (+0x140) through weak_ptr::lock 005cab00 and returns the raw pointer.
	PartInstance* JointInstance::getPart0() const
	{
		return part[0].lock().get();
	}

	// 005e2a70: the same for part[1] (+0x148).
	PartInstance* JointInstance::getPart1() const
	{
		return part[1].lock().get();
	}

	// 005e3790: parent must be a plain Instance (0040ad80) or a PartInstance (0059c7f0), compared through the
	// out-of-line descriptor operator== 0056fe10.
	bool JointInstance::askSetParent(const Instance* instance) const
	{
		return instance->getDescriptor() == Instance::classDescriptor()
			|| instance->getDescriptor() == PartInstance::classDescriptor();
	}

	// 005e2af0: assembly joints (Joint::getJointType(e) >= ANCHOR_JOINT, inline in 2008) draw a 20-wide line between
	// the two part positions, green (005148e0) when active and red (005148b0, folded with Vector3::unitX) otherwise.
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

	// 005e3870: DescribedNonCreatable() (005e37d0, ICF-shared), IRenderable, the part[] weak_ptr pair (eh vector
	// constructor 005e27d0 / 005576e0), joint +0x150, Joint::setJointOwner 006454a0 (IJointOwner base at +0x140), then
	// both parts from the joint primitives (+0xc / +0x10, PartInstance::fromPrimitive 00599f80, shared_from 00618a40).
	// Donor: tools/rbxgs v8datamodel/JointInstance.cpp JointInstance(Joint*) plus the AutoJoint(Joint*) part setup.
	JointInstance::JointInstance(Joint* joint)
		: joint(joint)
	{
		joint->setJointOwner(this);

		PartInstance* part0 = PartInstance::fromPrimitive(joint->getPrimitive(0));
		PartInstance* part1 = PartInstance::fromPrimitive(joint->getPrimitive(1));

		part[0] = shared_from(part0);
		part[1] = shared_from(part1);
	}

	// 005e2e10: setPart(0 / 1, NULL) 005e2cd0, Joint::setJointOwner(NULL) 006454a0, delete joint (slot 0), joint = NULL;
	// then ~weak_ptr[2] (005576e0), ~IRenderable 0047d410 and ~Instance 0055a540.
	JointInstance::~JointInstance()
	{
		setPart(0, NULL);
		setPart(1, NULL);

		joint->setJointOwner(NULL);
		delete joint;
		joint = NULL;
	}

	// 005e2cd0: compares the locked part (weak_ptr::lock 005cab00) with value; on a change stores shared_from(value)
	// 00618a40 and calls Joint::setPrimitive (slot 4) with the embedded Primitive (PartInstance +0x228) or NULL.
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

	// 005e3a80: Instance::onAncestorChanged 0055acc0; old world through IPipelined::getWorld (inline: currentStage +0x4,
	// IStage slot 1 == KERNEL_STAGE 7 -> upstream +0x4, IWorldStage world +0xc); a parent that is a plain Instance
	// (0040ad80, descriptor compare 0056fe10) uses ServiceProvider::find<Workspace> 00491e50 and its world (+0x2e4),
	// anything else Workspace::getWorldIfInWorkspace 005a3390; then World::removeJoint 005ea3a0 / insertJoint 005ea320.
	// Built with the 2008 StageType values of the opt-in kernel-stages IStage (native-flags): the donor
	// v8kernel/IStage.h numbers KERNEL_STAGE 8, while the inline donor getWorld must compare with 7 (005e3aa9
	// `cmp eax, 7`; ji03 found every other byte and relocation of the default build matching).
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
