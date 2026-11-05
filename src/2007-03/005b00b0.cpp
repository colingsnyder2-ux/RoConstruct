// from server: 82% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8kernel/Body.cpp

// Candidate translation unit (score above; library headers required).
#include "v8kernel/Body.h"

#include "decomp.h"
#include "util/Math.h"
#include "v8kernel/Link.h"
#include "v8kernel/SimBody.h"

#include <cstddef>

namespace RBX {

// FUNCTION: WEBSERVICE 0x1009ad20
void Body::updatePV() const
{
	if (parent != NULL && stateIndex != root->getStateIndex()) {
		const PV& parentPv = parent->getPV();

		pv = parentPv.pvAtLocalCoord(link != NULL ? link->getChildInParent() : meInParent);

		stateIndex = root->getStateIndex();
	}
}

// FUNCTION: WEBSERVICE 0x101049f0
int Body::getNextStateIndex()
{
	static int p = 1;

	p = p + 1;

	if (p == 0x7fffffff) {
		p = 1;
	}

	return p;
}

// FUNCTION: WEBSERVICE 0x10104a10
void Body::advanceStateIndex()
{
	stateIndex = getNextStateIndex();
}

// FUNCTION: WEBSERVICE 0x10104a40
void Body::makeCofmDirty()
{
	if (cofm == NULL || !cofm->getIsDirty()) {

		if (parent != NULL) {

			parent->makeCofmDirty();
		}
		else {

			if (simBody != NULL) {
				simBody->makeDirty();
			}
		}

		if (cofm != NULL) {
			cofm->makeDirty();
		}
	}
}

// FUNCTION: WEBSERVICE 0x10104a80
void Body::step(float dt, bool throttling)
{
	if (throttling && canThrottle) {
		simBody->resetAccumulators();
		return;
	}

	simBody->step(dt);

	pv = cofm == NULL ? simBody->getPV() : simBody->getOwnerPV();

	stateIndex = getNextStateIndex();
}

// FUNCTION: WEBSERVICE 0x10104b50
void Body::setPv(const PV& _pv)
{
	if (parent == NULL) {

		pv = _pv;

		if (simBody != NULL) {
			simBody->makeDirty();
		}

		advanceStateIndex();
	}
}

// FUNCTION: WEBSERVICE 0x10104be0
void Body::setVelocity(const Velocity& worldVelocity)
{
	if (parent == NULL) {
		pv.velocity = worldVelocity;
		advanceStateIndex();

		if (simBody != NULL) {
			simBody->makeDirty();
		}
	}
}

// FUNCTION: WEBSERVICE 0x10104c60
void Body::setMass(float _mass)
{
	if (mass != _mass) {
		makeCofmDirty();

		mass = _mass;
	}
}

// FUNCTION: WEBSERVICE 0x10104cc0
void Body::setMoment(const Matrix3& _momentInBody)
{
	if (moment != _momentInBody) {
		makeCofmDirty();

		moment = _momentInBody;
	}
}

// FUNCTION: WEBSERVICE 0x10104db0
void Body::setMeInParent(const CoordinateFrame& _meInParent)
{
	if (link != NULL) {

		link->setBody(NULL);
		link = NULL;
	}

	if (parent != NULL) {
		meInParent = _meInParent;
		makeCofmDirty();
		root->advanceStateIndex();
	}
}

// FUNCTION: WEBSERVICE 0x10104e60
void Body::setMeInParent(Link* _link)
{
	if (link != NULL && link != _link) {
		link->setBody(NULL);
	}

	if (parent != NULL) {
		link = _link;
		_link->setBody(this);
		makeCofmDirty();
		root->advanceStateIndex();
	}
}

// FUNCTION: WEBSERVICE 0x10104ee0
void Body::setCoordinateFrame(const CoordinateFrame& worldCoord)
{
	setPv(PV(worldCoord, getPV().velocity));
}

// FUNCTION: WEBSERVICE 0x10104f60
Vector3 Body::getBranchCofmPos() const
{
	return cofm != NULL ? getPV().position.pointToWorldSpace(cofm->getCofmInBody()) : getPV().position.translation;
}

// FUNCTION: WEBSERVICE 0x10104fc0
CoordinateFrame Body::getBranchCofmCoordinateFrame() const
{
	return CoordinateFrame(getCoordinateFrame().rotation, getBranchCofmPos());
}

// FUNCTION: WEBSERVICE 0x10105010
void Body::resetRoot(Body* newRoot)
{
	root = newRoot;

	for (int i = 0; i < numChildren(); ++i) {
		getChild(i)->resetRoot(newRoot);
	}
}

// FUNCTION: WEBSERVICE 0x10105040
Matrix3 Body::getIWorldAtPoint(const Vector3& point) const
{
	return Math::getIWorldAtPoint(getPV().position.translation, point, getIWorld(), getMass());
}

// FUNCTION: WEBSERVICE 0x101050c0
Matrix3 Body::getBranchIWorldAtPoint(const Vector3& point) const
{
	return Math::getIWorldAtPoint(getBranchCofmPos(), point, getBranchIWorld(), getBranchMass());
}

// FUNCTION: WEBSERVICE 0x10105150
float Body::kineticEnergy() const
{
	return ((getIWorld() * pv.velocity.rotational).dot(pv.velocity.rotational) +
			pv.velocity.linear.dot(pv.velocity.linear) * mass) *
		   0.5f;
}

// FUNCTION: WEBSERVICE 0x10105240
void Body::onChildRemoved(Body* child)
{
	children.fastRemove(child);

	if (numChildren() == 0) {
		delete cofm;
		cofm = NULL;
	}

	makeCofmDirty();
}

// FUNCTION: WEBSERVICE 0x101052d0
void Body::onChildAdded(Body* child)
{
	makeCofmDirty();

	children.fastAppend(child);

	if (cofm == NULL) {
		cofm = new Cofm(this);
	}
}

// FUNCTION: WEBSERVICE 0x10105390
void Body::setParent(Body* newParent)
{
	if (parent != newParent) {

		if (link != NULL) {
			link->setBody(NULL);
			link = NULL;
		}

		if (parent != NULL) {
			parent->onChildRemoved(this);
		}
		else {
			delete simBody;
			simBody = NULL;
		}

		parent = newParent;

		if (newParent != NULL) {
			newParent->onChildAdded(this);
		}
		else {
			simBody = new SimBody(this);
		}

		Body* newRoot = calcRoot();

		newRoot->advanceStateIndex();

		resetRoot(newRoot);
	}
}

// FUNCTION: WEBSERVICE 0x101054a0
Body::Body()
	: root(NULL), parent(NULL), index(-1), cofm(NULL), simBody(NULL), canThrottle(true), link(NULL),
	  moment(Matrix3::identity()), mass(0.0f), stateIndex(getNextStateIndex())
{
	root = this;
	simBody = new SimBody(this);
}

// FUNCTION: WEBSERVICE 0x101055a0
Body::~Body()
{
	if (parent != NULL) {
		setParent(NULL);
	}

	delete simBody;
	simBody = NULL;
}

// FUNCTION: WEBSERVICE 0x10105620
Body* Body::getWorldBody()
{
	static Body b;

	return &b;
}

} // namespace RBX
