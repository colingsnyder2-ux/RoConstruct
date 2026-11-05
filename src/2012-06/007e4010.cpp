// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/Assembly2.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/Assembly2.h"

#include "decomp.h"
#include "util/Math.h"
#include "util/StlExtra.h"
#include "v8kernel/Body.h"
#include "v8kernel/Kernel.h"
#include "v8world/Clump2.h"
#include "v8world/IMoving.h"
#include "v8world/Joint.h"
#include "v8world/MotorJoint.h"
#include "v8world/Primitive.h"
#include "v8world/RigidJoint.h"

#include <cstddef>

namespace RBX {

// FUNCTION: WEBSERVICE 0x10102990
SleepInfo::SleepInfo() : state(Sim::WAKE_PENDING), sleepCount(0)
{
}

// FUNCTION: WEBSERVICE 0x1015b610 FOLDED
SleepInfo::~SleepInfo()
{
}

// FUNCTION: WEBSERVICE 0x101029c0
PrimIterator Assembly::assemblyPrimBegin() const
{
	return PrimIterator::begin(rootPrimitive, PrimIterator::IN_ASSEMBLY);
}

// FUNCTION: WEBSERVICE 0x101029e0
PrimIterator Assembly::assemblyPrimEnd() const
{
	return PrimIterator::end(PrimIterator::IN_ASSEMBLY);
}

// FUNCTION: WEBSERVICE 0x10102a00
EdgeIterator Assembly::externalEdgeBegin() const
{
	return EdgeIterator::begin(rootPrimitive);
}

// FUNCTION: WEBSERVICE 0x10102a20
EdgeIterator Assembly::externalEdgeEnd() const
{
	return EdgeIterator::end();
}

// FUNCTION: WEBSERVICE 0x10102a60
Sim::AssemblyState Assembly::getSleepStatus() const
{
	const Assembly* root = this;

	while (root->parent != NULL) {
		root = root->parent;
	}

	return root->sleepInfo != NULL ? root->sleepInfo->state : Sim::ANCHORED;
}

// FUNCTION: WEBSERVICE 0x10102a80
bool lessAssembly(const Assembly* a0, const Assembly* a1)
{
	if (a0 == a1) {
		return false;
	}

	if (a0->getRootPrimitive() == a1->getRootPrimitive()) {
		return false;
	}

	return Guid::compare(&a0->getRootPrimitive()->getGuid(), &a1->getRootPrimitive()->getGuid()) == -1;
}

// FUNCTION: WEBSERVICE 0x10102ac0 FOLDED
Assembly* Assembly::getRootAssembly()
{
	return parent != NULL ? parent->getRootAssembly() : this;
}

// FUNCTION: WEBSERVICE 0x10102ac0 FOLDED
const Assembly* Assembly::getRootAssemblyConst() const
{
	return parent != NULL ? parent->getRootAssemblyConst() : this;
}

// FUNCTION: WEBSERVICE 0x10102ad0
Joint* Assembly::getJointToParent(Primitive* p)
{
	Joint* joint = p->getFirstJoint();

	while (joint != NULL) {
		if (joint->getActive()) {
			Primitive* other = joint->getPrimitive(0);

			if (p == other) {
				other = joint->getPrimitive(1);
			}

			if (other == NULL || p->getBody()->getParent() == other->getBody()) {
				return joint;
			}
		}

		joint = p->getNextJoint(joint);
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x10102b10
void Assembly::putInKernel(Kernel* kernel)
{
	putInPipeline(kernel);
	kernel->insertBody(rootPrimitive->getBody());
}

// FUNCTION: WEBSERVICE 0x10102b40
void Assembly::removeFromKernel()
{
	getKernel()->removeBody(rootPrimitive->getBody());
	IPipelined::removeFromKernel();
}

// FUNCTION: WEBSERVICE 0x10102b60 FOLDED
Primitive* Assembly::getAssemblyPrimitive()
{
	return getRootAssembly()->rootPrimitive;
}

// FUNCTION: WEBSERVICE 0x10102b60 FOLDED
const Primitive* Assembly::getAssemblyPrimitiveConst() const
{
	return getRootAssemblyConst()->rootPrimitive;
}

// FUNCTION: WEBSERVICE 0x10102b80
bool Assembly::getAnchored() const
{
	return getRootAssemblyConst()->rootPrimitive->getAnchorObject() != NULL;
}

// FUNCTION: WEBSERVICE 0x10102ba0
Mechanism* Assembly::getMechanism()
{
	return mechanism;
}

// FUNCTION: WEBSERVICE 0x10102bb0
bool Assembly::computeCanSleep() const
{
	for (PrimIterator it = PrimIterator::begin(rootPrimitive, PrimIterator::IN_ASSEMBLY); *it != NULL; ++it) {
		if (!(*it)->getCanSleep()) {
			return false;
		}
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x10102bf0
void Assembly::notifyMoved()
{
	for (PrimIterator it = PrimIterator::begin(rootPrimitive, PrimIterator::IN_ASSEMBLY); *it != NULL; ++it) {
		(*it)->getOwner()->notifyMoved();
	}
}

// FUNCTION: WEBSERVICE 0x10102c20
Assembly* Assembly::otherAssembly(Edge* edge) const
{
	Assembly* assembly0 = edge->getPrimitive(0)->getAssembly();
	Assembly* assembly1 = edge->getPrimitive(1)->getAssembly();

	return assembly0 != this ? assembly0 : assembly1;
}

// FUNCTION: WEBSERVICE 0x10102d50
void Assembly::onPrimitivesChanged()
{
	maxRadius.setDirty();
	canSleep.setDirty();

	if (parent != NULL) {
		parent->onPrimitivesChanged();
	}
}

// FUNCTION: WEBSERVICE 0x10102d70
void Assembly::addRigidChild(Primitive* parent, RigidJoint* r, Primitive* child)
{
	Clump* clump = parent->getClump();

	child->setClump(clump);
	child->setClumpDepth(parent->getClumpDepth() + 1);
	child->getBody()->setParent(parent->getBody());
	child->getBody()->setMeInParent(r->getChildInParent(parent, child));

	clump->onPrimitivesChanged();
}

// FUNCTION: WEBSERVICE 0x10102de0
unsigned int Assembly::numMotors() const
{
	unsigned int answer = 0;

	if (MotorJoint::isMotorJoint(getJointToParent(rootPrimitive))) {
		answer = 1;
	}

	for (unsigned int i = 0; i < children.size(); i++) {
		answer += children[i]->numMotors();
	}

	return answer;
}

// FUNCTION: WEBSERVICE 0x10102e60
const MotorJoint* Assembly::getMotorImp(unsigned int& motorId) const
{
	Joint* joint = getJointToParent(rootPrimitive);

	if (MotorJoint::isMotorJoint(joint)) {
		if (motorId == 0) {
			return static_cast<MotorJoint*>(joint);
		}

		motorId--;
	}

	for (unsigned int i = 0; i < children.size(); i++) {
		const MotorJoint* motor = children[i]->getMotorImp(motorId);

		if (motor != NULL) {
			return motor;
		}
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x10102f00
MotorJoint* Assembly::getMotor(unsigned int index)
{
	unsigned int i = index;

	return const_cast<MotorJoint*>(getMotorImp(i));
}

// FUNCTION: WEBSERVICE 0x10102f20
void Assembly::stepUi(int uiStepId)
{
	unsigned int count = numMotors();

	for (unsigned int i = 0; i < count; i++) {
		unsigned int index = i;
		const_cast<MotorJoint*>(getMotorImp(index))->stepUi(uiStepId);
	}
}

// FUNCTION: WEBSERVICE 0x10102f60
float Assembly::computeMaxRadius() const
{
	float answer = 0;
	Vector3 offsetCenter = rootPrimitive->getBody()->getBranchCofmPos();

	for (PrimIterator it = PrimIterator::begin(rootPrimitive, PrimIterator::IN_ASSEMBLY); *it != NULL; ++it) {
		Primitive* primitive = *it;

		Vector3 offset = primitive->getBody()->getCoordinateFrame().translation - offsetCenter;
		Vector3 extent = Math::vector3Abs(offset);

		answer = G3D::max(answer, (extent + primitive->getGeometry()->getGridSize() * 0.5f).magnitude());
	}

	return answer;
}

// FUNCTION: WEBSERVICE 0x10103060
void Assembly::onPrimitiveCanSleepChanged(Primitive* p)
{
	canSleep.setDirty();
}

// FUNCTION: WEBSERVICE 0x101034e0
Assembly::Assembly(Primitive* root)
	: sleepInfo(NULL), rootPrimitive(root), parent(NULL), mechanism(NULL), maxRadius(this, &Assembly::computeMaxRadius),
	  canSleep(this, &Assembly::computeCanSleep)
{
	root->setClump(static_cast<Clump*>(this));
}

// FUNCTION: WEBSERVICE 0x10103750
void Assembly::addChild(Assembly* child)
{
	children.push_back(child);
	std::sort(children.begin(), children.end(), lessAssembly);
}

// FUNCTION: WEBSERVICE 0x101037b0
Assembly::~Assembly()
{
	for (PrimIterator it = PrimIterator::begin(rootPrimitive, PrimIterator::IN_CLUMP); *it != NULL; ++it) {
		Primitive* primitive = *it;

		primitive->setClump(NULL);
		primitive->setClumpDepth(-1);
	}

	if (parent != NULL) {
		fastRemoveShort(parent->children, this);
	}

	parent = NULL;

	for (unsigned int i = 0; i < children.size(); i++) {
		children[i]->parent = NULL;
	}
}

// FUNCTION: WEBSERVICE 0x101038a0
void Assembly::setParent(Assembly* newParent)
{
	if (newParent != parent) {
		if (parent != NULL) {
			fastRemoveShort(parent->children, this);
			parent->onPrimitivesChanged();
		}

		parent = newParent;

		if (parent != NULL) {
			parent->addChild(this);
		}

		onPrimitivesChanged();
	}
}

// FUNCTION: WEBSERVICE 0x10103910
void Assembly::addMotorChild(Primitive* parent, MotorJoint* m, Primitive* child)
{
	Clump* clump = parent->getClump();

	child->setClumpDepth(parent->getClumpDepth() + 1);
	child->getClump()->setParent(clump);
	child->getBody()->setParent(parent->getBody());
	child->getBody()->setMeInParent(m->resetLink());
}

// FUNCTION: WEBSERVICE 0x10103960
void Assembly::addGroundChild(Primitive* p)
{
	Clump* clump = p->getClump();

	p->setClumpDepth(1);
	p->getBody()->setParent(NULL);
	clump->setParent(NULL);
}

} // namespace RBX
