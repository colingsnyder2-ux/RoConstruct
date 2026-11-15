// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
#undef _RELEASEASSERT
// 2008-06 RBX::JointInstance IRenderable rows of the v8datamodel/JointInstance.cpp unit (inactive), built against the
// committed native v8datamodel/JointInstance.h (read-only; the getset factories of the same unit are in
// AppUnit5E0JointReflection.cpp): shouldRender3dAdorn 005e27a0.
//
// The 2008 JointInstance carries the AutoJoint parts (boost::weak_ptr<PartInstance> at +0x140 / +0x148, joint at
// +0x150; see native v8datamodel/JointInstance.h): part getters 005e2a10 / 005e2a70, askSetParent 005e3790 and
// render3dAdorn 005e2af0 (IRenderable +0x130 this; Primitive embedded in PartInstance at +0x228).
#include "v8datamodel/JointInstance.h"

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
}
