// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::PrimIterator / RBX::EdgeIterator (inactive), the v8world clump-iterator unit 006473e0..0064775f
// (the original Clump.cpp tail in the openrbx donor: tools/openrbx/Client/App/v8world/Clump2.cpp). Declarations:
// native-headers/v8world/AssemblyLayout.h (NATIVE_CLUMP_DECL part); flags and includes follow native-classes/Clump.cpp.
// Identity: registry names ?getNextExternalUtil@EdgeIterator 006473e0, ?findParent@PrimIterator 006474e0,
// ?findFirstChild@PrimIterator 00647540, ?findNextRelative@PrimIterator 00647600, ??EPrimIterator 00647640,
// ?findEdgeOnNextPrimitive@EdgeIterator 00647680, ??EEdgeIterator 00647700, ?begin@EdgeIterator 00647730; the
// placeholders func_00647430 (called with (parentCandidate, child, joint, searchType) by findParent / findFirstChild /
// 006475a0) and func_006475a0 (called by findNextRelative 00647600 and findEdgeOnNextPrimitive 00647680) are the donor
// isParent and findNextSibling. Primitive calls: getFirstJoint 005e7b90, getNextJoint 005e7ba0, getFirstEdge 005e7b00,
// getNextEdge 005e7b20, the unchecked getAssembly 005e7560 (Primitive2008.h getAssemblyNoCheck).
#include <G3D/Array.h>
#include <G3D/CoordinateFrame.h>
#include "v8world/Primitive2008.h"
#include "v8kernel/Body2008.h"
#include "v8world/Joints2008.h"
#define NATIVE_CLUMP_DECL // the native 2008 RBX::Clump / RBX::Assembly of v8world/AssemblyLayout.h
#include "v8world/AssemblyLayout.h"

namespace RBX
{
	// 006473e0 ?getNextExternalUtil@EdgeIterator@RBX@@CAPAVEdge@2@PAVPrimitive@2@PAV32@@Z
	Edge* EdgeIterator::getNextExternalUtil(Primitive* p, Edge* e)
	{
		while (e != NULL)
		{
			Primitive* other = e->getPrimitive(0);
			if (p == other)
				other = e->getPrimitive(1);

			if (other != NULL && p->getAssemblyNoCheck() != other->getAssemblyNoCheck())
				return e;

			e = p->getNextEdge(e);
		}
		return NULL;
	}

	// 00647430 PrimIterator::isParent (func_00647430). It calls RigidJoint::isRigidJoint 00599300
	// (?isRigidJoint@RigidJoint@RBX@@SA_NPAVEdge@2@@Z) and MotorJoint::isMotorJoint 00599330
	// (?isMotorJoint@MotorJoint@RBX@@SA_NPAVEdge@2@@Z), declared inline in native-headers/v8world/Joints2008.h
	// (batch 36). Target shape: NULL checks of both primitives, joint->active (+0x24), isRigidJoint
	// then (IN_ASSEMBLY only) isMotorJoint, child body (+0xa0) parent (+0x14) == parentCandidate body, clump (+0x5c)
	// compare, then (IN_ASSEMBLY) the unchecked getAssembly 005e7560 of parentCandidate before child's.
	bool PrimIterator::isParent(Primitive* parentCandidate, Primitive* child, Joint* joint, SearchType searchType)
	{
		if (parentCandidate == NULL || child == NULL || !joint->getActive())
			return false;

		bool jointed;
		if (searchType == IN_CLUMP)
			jointed = RigidJoint::isRigidJoint(joint);
		else
			jointed = RigidJoint::isRigidJoint(joint) || MotorJoint::isMotorJoint(joint);

		if (jointed && child->getBody()->getParent() == parentCandidate->getBody())
		{
			bool sameClump = parentCandidate->getClump() == child->getClump();
			return searchType == IN_CLUMP
				? sameClump
				: sameClump || parentCandidate->getAssemblyNoCheck() == child->getAssemblyNoCheck();
		}
		return false;
	}

	// 006474e0 ?findParent@PrimIterator@RBX@@SAPAVPrimitive@2@PAV32@W4SearchType@12@@Z
	Primitive* PrimIterator::findParent(Primitive* p, SearchType searchType)
	{
		Joint* joint = p->getFirstJoint();
		while (joint != NULL)
		{
			Primitive* other = p == joint->getPrimitive(0) ? joint->getPrimitive(1) : joint->getPrimitive(0);
			if (isParent(other, p, joint, searchType))
				return other;

			joint = p->getNextJoint(joint);
		}
		return NULL;
	}

	// 00647540 ?findFirstChild@PrimIterator@RBX@@CAPAVPrimitive@2@PAV32@W4SearchType@12@@Z
	Primitive* PrimIterator::findFirstChild(Primitive* p, SearchType searchType)
	{
		Joint* joint = p->getFirstJoint();
		while (joint != NULL)
		{
			Primitive* other = p == joint->getPrimitive(0) ? joint->getPrimitive(1) : joint->getPrimitive(0);
			if (isParent(p, other, joint, searchType))
				return other;

			joint = p->getNextJoint(joint);
		}
		return NULL;
	}

	// 006475a0 (func_006475a0) PrimIterator::findNextSibling: defined in native-classes/Clump.cpp (byte-identical,
	// relocs masked); not repeated here, which would be a duplicate definition in the same link.

	// 00647600 ?findNextRelative@PrimIterator@RBX@@CAPAVPrimitive@2@PAV32@0W4SearchType@12@@Z
	Primitive* PrimIterator::findNextRelative(Primitive* parent, Primitive* p, SearchType searchType)
	{
		if (parent == NULL)
			return NULL;

		Primitive* sibling = findNextSibling(parent, p, searchType);
		if (sibling != NULL)
			return sibling;

		Primitive* grandparent = findParent(parent, searchType);
		return findNextRelative(grandparent, parent, searchType);
	}

	// 00647640 ??EPrimIterator@RBX@@QAEAAV01@XZ
	PrimIterator& PrimIterator::operator++()
	{
		SearchType type = searchType;
		Primitive* current = primitive;

		Primitive* next = findFirstChild(current, type);
		if (next == NULL)
		{
			Primitive* parent = findParent(current, type);
			primitive = findNextRelative(parent, current, type);
		}
		else
			primitive = next;

		return *this;
	}

	// 00647680 ?findEdgeOnNextPrimitive@EdgeIterator@RBX@@AAEXXZ
	void EdgeIterator::findEdgeOnNextPrimitive()
	{
		while (edge == NULL)
		{
			Primitive* next = *++PrimIterator::begin(primitive, PrimIterator::IN_ASSEMBLY);
			primitive = next;
			if (next == NULL)
				return;

			edge = getNextExternalUtil(next, next->getFirstEdge());
		}
	}

	// 00647700 ??EEdgeIterator@RBX@@QAEAAV01@XZ
	EdgeIterator& EdgeIterator::operator++()
	{
		Primitive* current = primitive;
		edge = getNextExternalUtil(current, current->getNextEdge(edge));
		if (edge == NULL)
			findEdgeOnNextPrimitive();
		return *this;
	}

	// 00647730 ?begin@EdgeIterator@RBX@@SA?AV12@PAVPrimitive@2@@Z
	EdgeIterator EdgeIterator::begin(Primitive* p)
	{
		EdgeIterator answer(p, getNextExternalUtil(p, p->getFirstEdge()));
		if (answer.edge == NULL)
			answer.findEdgeOnNextPrimitive();
		return answer;
	}
}
