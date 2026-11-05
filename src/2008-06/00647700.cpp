// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/Clump2.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/Clump2.h"

#include "decomp.h"
#include "v8kernel/Body.h"
#include "v8world/Assembly2.h"
#include "v8world/IPipelined.h"
#include "v8world/Joint.h"
#include "v8world/MotorJoint.h"
#include "v8world/Primitive.h"
#include "v8world/RigidJoint.h"

#include <cstddef>

namespace RBX {

// FUNCTION: WEBSERVICE 0x10117da0
Edge* EdgeIterator::getNextExternalUtil(Primitive* p, Edge* e)
{
	while (e != NULL) {
		Primitive* other = e->getPrimitive(0);

		if (p == other) {
			other = e->getPrimitive(1);
		}

		if (other != NULL && p->getAssembly() != other->getAssembly()) {
			return e;
		}

		e = p->getNextEdge(e);
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x10117df0
bool PrimIterator::isParent(Primitive* parentCandidate, Primitive* child, Joint* joint, SearchType searchType)
{
	if (parentCandidate == NULL || child == NULL) {
		return false;
	}

	bool jointed;

	if (searchType == IN_CLUMP) {
		jointed = RigidJoint::isRigidJoint(joint);
	}
	else {
		jointed = RigidJoint::isRigidJoint(joint) || MotorJoint::isMotorJoint(joint);
	}

	if (jointed) {
		if (child->getBody()->getParent() == parentCandidate->getBody()) {
			bool sameClump = parentCandidate->getClump() == child->getClump();

			return searchType == IN_CLUMP ? sameClump
										  : sameClump || parentCandidate->getAssembly() == child->getAssembly();
		}
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x10117ea0
Primitive* PrimIterator::findParent(Primitive* p, SearchType searchType)
{
	Joint* joint = p->getFirstJoint();

	while (joint != NULL) {
		Primitive* other = p == joint->getPrimitive(0) ? joint->getPrimitive(1) : joint->getPrimitive(0);

		if (isParent(other, p, joint, searchType)) {
			return other;
		}

		joint = p->getNextJoint(joint);
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x10117f00
Primitive* PrimIterator::findFirstChild(Primitive* p, SearchType searchType)
{
	Joint* joint = p->getFirstJoint();

	while (joint != NULL) {
		Primitive* other = p == joint->getPrimitive(0) ? joint->getPrimitive(1) : joint->getPrimitive(0);

		if (isParent(p, other, joint, searchType)) {
			return other;
		}

		joint = p->getNextJoint(joint);
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x10117f60
Primitive* PrimIterator::findNextSibling(Primitive* parent, Primitive* sibling, SearchType searchType)
{
	bool found = false;

	for (Joint* joint = parent->getFirstJoint(); joint != NULL; joint = parent->getNextJoint(joint)) {
		Primitive* other = parent == joint->getPrimitive(0) ? joint->getPrimitive(1) : joint->getPrimitive(0);

		if (isParent(parent, other, joint, searchType)) {
			if (found) {
				return other;
			}

			if (other == sibling) {
				found = true;
			}
		}
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x10117fc0
Primitive* PrimIterator::findNextRelative(Primitive* parent, Primitive* p, SearchType searchType)
{
	if (parent == NULL) {
		return NULL;
	}

	Primitive* sibling = findNextSibling(parent, p, searchType);

	if (sibling != NULL) {
		return sibling;
	}

	Primitive* grandparent = findParent(parent, searchType);

	return findNextRelative(grandparent, parent, searchType);
}

// FUNCTION: WEBSERVICE 0x10118000
PrimIterator& PrimIterator::operator++()
{
	SearchType type = searchType;
	Primitive* current = primitive;

	Primitive* next = findFirstChild(current, type);

	if (next == NULL) {
		Primitive* parent = findParent(current, type);

		primitive = findNextRelative(parent, current, type);
	}
	else {
		primitive = next;
	}

	return *this;
}

// FUNCTION: WEBSERVICE 0x10118040
void EdgeIterator::findEdgeOnNextPrimitive()
{
	while (edge == NULL) {
		Primitive* next = *++PrimIterator::begin(primitive, PrimIterator::IN_ASSEMBLY);

		if ((primitive = next) == NULL) {
			return;
		}

		edge = getNextExternalUtil(next, next->getFirstEdge());
	}
}

// FUNCTION: WEBSERVICE 0x101180c0
EdgeIterator& EdgeIterator::operator++()
{
	Primitive* current = primitive;

	edge = getNextExternalUtil(current, current->getNextEdge(edge));

	if (edge == NULL) {
		findEdgeOnNextPrimitive();
	}

	return *this;
}

// FUNCTION: WEBSERVICE 0x101180f0
EdgeIterator EdgeIterator::begin(Primitive* p)
{
	EdgeIterator answer(p, getNextExternalUtil(p, p->getFirstEdge()));

	if (answer.edge == NULL) {
		answer.findEdgeOnNextPrimitive();
	}

	return answer;
}

} // namespace RBX
