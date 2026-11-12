// from server: 100% by auto
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
// FUNCTION: ROBLOX 0x005f4390
SleepInfo::SleepInfo() : state(Sim::WAKE_PENDING), sleepCount(0)
{
}

// FUNCTION: WEBSERVICE 0x1015b610 FOLDED
// FUNCTION: ROBLOX 0x00751160 FOLDED
SleepInfo::~SleepInfo()
{
}

// FUNCTION: WEBSERVICE 0x101029c0
// FUNCTION: ROBLOX 0x005f43c0
PrimIterator Assembly::assemblyPrimBegin() const
{
	return PrimIterator::begin(rootPrimitive, PrimIterator::IN_ASSEMBLY);
}

// FUNCTION: WEBSERVICE 0x101029e0
// FUNCTION: ROBLOX 0x005f43e0
PrimIterator Assembly::assemblyPrimEnd() const
{
	return PrimIterator::end(PrimIterator::IN_ASSEMBLY);
}

// FUNCTION: WEBSERVICE 0x10102a00
// FUNCTION: ROBLOX 0x005f4400
EdgeIterator Assembly::externalEdgeBegin() const
{
	return EdgeIterator::begin(rootPrimitive);
}

// FUNCTION: WEBSERVICE 0x10102a20
// FUNCTION: ROBLOX 0x005f4420
EdgeIterator Assembly::externalEdgeEnd() const
{
	return EdgeIterator::end();
}

// FUNCTION: WEBSERVICE 0x10102a60
// FUNCTION: ROBLOX 0x005f4460
Sim::AssemblyState Assembly::getSleepStatus() const
{
	const Assembly* root = this;

	while (root->parent != NULL) {
		root = root->parent;
	}

	return root->sleepInfo != NULL ? root->sleepInfo->state : Sim::ANCHORED;
}

// FUNCTION: WEBSERVICE 0x10102a80
// FUNCTION: ROBLOX 0x005f4480
bool lessAssembly(const Assembly* a0, const Assembly* a1)
{
	if (a0 == a1) {
		return false;
	}

	if (a0->getClumpPrimitive() == a1->getClumpPrimitive()) {
		return false;
	}

	return Guid::compare(&a0->getClumpPrimitive()->getGuid(), &a1->getClumpPrimitive()->getGuid()) == -1;
}

// FUNCTION: WEBSERVICE 0x10102ac0 FOLDED
// FUNCTION: ROBLOX 0x005f44c0 FOLDED
Assembly* Assembly::getRootAssembly()
{
	return parent != NULL ? parent->getRootAssembly() : this;
}

// FUNCTION: WEBSERVICE 0x10102ac0 FOLDED
// FUNCTION: ROBLOX 0x005f44c0 FOLDED
const Assembly* Assembly::getRootAssemblyConst() const
{
	return parent != NULL ? parent->getRootAssemblyConst() : this;
}

// FUNCTION: WEBSERVICE 0x10102ad0
// FUNCTION: ROBLOX 0x005f44d0
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
// FUNCTION: ROBLOX 0x005f4510
void Assembly::putInKernel(Kernel* kernel)
{
	putInPipeline(kernel);
	kernel->insertBody(rootPrimitive->getBody());
}

// FUNCTION: WEBSERVICE 0x10102b40
// FUNCTION: ROBLOX 0x005f4540
void Assembly::removeFromKernel()
{
	getKernel()->removeBody(rootPrimitive->getBody());
	IPipelined::removeFromKernel();
}

// FUNCTION: WEBSERVICE 0x10102b60 FOLDED
// FUNCTION: ROBLOX 0x005f4560 FOLDED
Primitive* Assembly::getAssemblyPrimitive()
{
	return getRootAssembly()->rootPrimitive;
}

// FUNCTION: WEBSERVICE 0x10102b60 FOLDED
// FUNCTION: ROBLOX 0x005f4560 FOLDED
const Primitive* Assembly::getAssemblyPrimitiveConst() const
{
	return getRootAssemblyConst()->rootPrimitive;
}

// FUNCTION: WEBSERVICE 0x10102b80
// FUNCTION: ROBLOX 0x005f4580
bool Assembly::getAnchored() const
{
	return getRootAssemblyConst()->rootPrimitive->getAnchorObject() != NULL;
}

// FUNCTION: WEBSERVICE 0x10102ba0
// FUNCTION: ROBLOX 0x006b3220
Mechanism* Assembly::getMechanism()
{
	return mechanism;
}

// FUNCTION: WEBSERVICE 0x10102bb0
// FUNCTION: ROBLOX 0x005f45a0
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
// FUNCTION: ROBLOX 0x005f45e0
void Assembly::notifyMoved()
{
	for (PrimIterator it = PrimIterator::begin(rootPrimitive, PrimIterator::IN_ASSEMBLY); *it != NULL; ++it) {
		(*it)->getOwner()->notifyMoved();
	}
}

// FUNCTION: WEBSERVICE 0x10102c20
// FUNCTION: ROBLOX 0x005f4610
Assembly* Assembly::otherAssembly(Edge* edge) const
{
	Assembly* assembly0 = edge->getPrimitive(0)->getAssembly();
	Assembly* assembly1 = edge->getPrimitive(1)->getAssembly();

	return assembly0 != this ? assembly0 : assembly1;
}

// FUNCTION: WEBSERVICE 0x10102d50
// FUNCTION: ROBLOX 0x005f46a0
void Assembly::onPrimitivesChanged()
{
	maxRadius.setDirty();
	canSleep.setDirty();

	if (parent != NULL) {
		parent->onPrimitivesChanged();
	}
}

// FUNCTION: WEBSERVICE 0x10102d70
// FUNCTION: ROBLOX 0x005f46c0
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
// FUNCTION: ROBLOX 0x005f4730
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
// FUNCTION: ROBLOX 0x005f47b0
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

// FUNCTION: WEBSERVICE 0x10102f00 FOLDED
// FUNCTION: ROBLOX 0x005f4850 FOLDED
MotorJoint* Assembly::getMotor(unsigned int index)
{
	unsigned int i = index;

	return const_cast<MotorJoint*>(getMotorImp(i));
}

// FUNCTION: WEBSERVICE 0x10102f00 FOLDED
// FUNCTION: ROBLOX 0x005f4850 FOLDED
const MotorJoint* Assembly::getMotorConst(unsigned int index) const
{
	unsigned int i = index;

	return getMotorImp(i);
}

// FUNCTION: WEBSERVICE 0x10102f20
// FUNCTION: ROBLOX 0x005f4870
void Assembly::stepUi(int uiStepId)
{
	unsigned int count = numMotors();

	for (unsigned int i = 0; i < count; i++) {
		unsigned int index = i;
		const_cast<MotorJoint*>(getMotorImp(index))->stepUi(uiStepId);
	}
}

// FUNCTION: WEBSERVICE 0x10102f60
// FUNCTION: ROBLOX 0x005f48b0
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
// FUNCTION: ROBLOX 0x005f49b0
void Assembly::onPrimitiveCanSleepChanged(Primitive* p)
{
	canSleep.setDirty();
}

// FUNCTION: WEBSERVICE 0x101034e0
// FUNCTION: ROBLOX 0x005f4e30
Assembly::Assembly(Primitive* root)
	: sleepInfo(NULL), rootPrimitive(root), parent(NULL), mechanism(NULL), maxRadius(this, &Assembly::computeMaxRadius),
	  canSleep(this, &Assembly::computeCanSleep)
{
	root->setClump(static_cast<Clump*>(this));
}

// FUNCTION: WEBSERVICE 0x10103750
// FUNCTION: ROBLOX 0x005f50a0
void Assembly::addChild(Assembly* child)
{
	children.push_back(child);
	std::sort(children.begin(), children.end(), lessAssembly);
}

// FUNCTION: WEBSERVICE 0x101037b0
// FUNCTION: ROBLOX 0x005f5100
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
// FUNCTION: ROBLOX 0x005f51f0
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
// FUNCTION: ROBLOX 0x005f5260
void Assembly::addMotorChild(Primitive* parent, MotorJoint* m, Primitive* child)
{
	Clump* clump = parent->getClump();

	child->setClumpDepth(parent->getClumpDepth() + 1);
	child->getClump()->setParent(clump);
	child->getBody()->setParent(parent->getBody());
	child->getBody()->setMeInParent(m->resetLink());
}

// FUNCTION: WEBSERVICE 0x10103960
// FUNCTION: ROBLOX 0x005f52b0
void Assembly::addGroundChild(Primitive* p)
{
	Clump* clump = p->getClump();

	p->setClumpDepth(1);
	p->getBody()->setParent(NULL);
	clump->setParent(NULL);
}

} // namespace RBX
