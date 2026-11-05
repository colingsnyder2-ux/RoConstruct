#pragma float_control(precise, off)
#include "v8kernel/Body.h"
#include "v8kernel/SimBody.h"
#include "util/Debug.h"
using namespace RBX;

Body::Body()
	:unknown0x4(-1),
	unknown0x8(NULL),
	unknown0xc(false),
	index(-1),
	canThrottle(true),
	cofm(NULL),
	root(NULL),
	parent(NULL),
	link(NULL),
	simBody(NULL),
	stateIndex(getNextStateIndex()),
	moment(G3D::Matrix3::identity()),
	mass(0.0f)
{
	root = this;
	simBody = new SimBody(this);
}

Body::~Body()
{
	if (parent)
		setParent(NULL);
	delete simBody;
	simBody = NULL;
}

void Body::updatePV() const
{
	RBXASSERT((parent != NULL) || (getRootConst() == this));

	if (parent && this->stateIndex != getRootConst()->getStateIndex())
	{
		Body* tempParent = getParent();
		tempParent->updatePV();
		PV& tempPV = tempParent->pv;
		this->pv = tempPV.pvAtLocalCoord(getMeInParent());
		this->stateIndex = root->getStateIndex();
	}
}

void Body::resetRoot(RBX::Body* newRoot)
{
	root = newRoot;
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->resetRoot(newRoot);
	}
}

float Body::kineticEnergy() const
{
	float calc = (pv.velocity.rotational.dot(getIWorld() * pv.velocity.rotational) + pv.velocity.linear.dot(pv.velocity.linear) * mass) / 2;
	return calc;

}

int Body::getNextStateIndex()
{
	static int p;
	if (++p == INT_MAX)
		p = 1;
	return p;
}

void Body::advanceStateIndex()
{
	stateIndex = getNextStateIndex();
}

bool Body::validateParentCofmDirty()
{
	RBXASSERT(cofm);
	RBXASSERT(cofm->getIsDirty());
	if (getParent())
		getParent()->validateParentCofmDirty();
	return true;
}

void Body::makeCofmDirty()
{
	if (cofm && cofm->getIsDirty())
	{
	}
	else
	{
		if (getParent())
			getParent()->makeCofmDirty();
		else if (simBody)
			simBody->makeDirty();
		if (cofm)
			cofm->makeDirty();
	}
}

void Body::onChildAdded(RBX::Body* child)
{
	makeCofmDirty();
	children.fastAppend(child);
	if (!cofm)
	{
		                             ;
		cofm = new Cofm(this);
	}
}

void Body::onChildRemoved(RBX::Body* child)
{
	children.fastRemove(child);
	if (numChildren() == 0)
	{
		delete cofm;
		cofm = NULL;
	}
	makeCofmDirty();
}

void Body::setMass(float _mass)
{
	if (mass != _mass)
	{
		makeCofmDirty();
		mass = _mass;
	}
}

void Body::step(bool throttling)
{
	if (throttling && canThrottle)
	{
		simBody->resetAccumulators();
	}
	else
	{
		simBody->step();
		pv = cofm == NULL ? simBody->pv : simBody->getOwnerPV();
		advanceStateIndex();
	}
}

void Body::setVelocity(const Velocity& worldVelocity)
{
	if (!getParent())
	{
		pv.velocity = worldVelocity;
		advanceStateIndex();
		if (simBody)
			simBody->makeDirty();
	}
}

void Body::setParent(Body* newParent)
{
	if (parent != newParent)
	{
		if (link)
		{
			link->setBody(NULL);
			link = NULL;
		}

		if (getParent())
		{
			parent->onChildRemoved(this);
		}
		else
		{
			delete simBody;
			simBody = NULL;
		}

		parent = newParent;

		if (newParent)
		{
			newParent->onChildAdded(this);
		}
		else
		{
			simBody = new SimBody(this);
		}
		Body* myRoot = getParent() ? getParent()->calcRoot() : this;
		myRoot->advanceStateIndex();
		root = myRoot;
		for (int i = 0; i < children.size(); i++)
			children[i]->resetRoot(myRoot);
	}
}

static Body* gWorldBody = NULL;   // 2008: the global Body* at 0x97bec4

static void initialize()           // 00614b40 ?initialize@@YAXXZ
{
	gWorldBody = new Body();
}

Body* Body::getWorldBody()
{
	if (!gWorldBody)
		initialize();
	return gWorldBody;
}

G3D::CoordinateFrame Body::getMeInDescendant(const Body* descendant) const
{
	if (descendant == this)
	{
		return G3D::CoordinateFrame();
	}
	else if (descendant == parent)
	{
		RBXASSERT(parent);
		return getLink() ? getLink()->getChildInParent() : meInParent;
	}
	else
	{
		RBXASSERT(parent);
		return parent->getMeInDescendant(descendant) * meInParent;
	}
}

void Body::setPv(const PV& _pv)
{
	if (!parent)
	{
		pv = _pv;
		if (simBody)
			simBody->makeDirty();
		advanceStateIndex();
	}
}

void Body::setCoordinateFrame(const G3D::CoordinateFrame& worldCord)
{
	updatePV();
	setPv(PV::PV(worldCord, pv.velocity));
}

void Body::setMeInParent(const G3D::CoordinateFrame& _meInParent)
{
	RBXASSERT(Math::longestVector3Component(_meInParent.translation) < 1000000.0);

	if (getLink())
	{
		RBXASSERT(0);
		getLink()->setBody(NULL);
		link = NULL;
	}

	if (getParent())
	{
		meInParent = _meInParent;
		makeCofmDirty();
		root->advanceStateIndex();
	}
	else
	{
		RBXASSERT(0);
	}
}

void Body::setMeInParent(RBX::Link* value)
{
	if (link && link != value)
		link->setBody(NULL);
	if (getParent())
	{
		link = value;
		value->setBody(this);
		makeCofmDirty();
		root->advanceStateIndex();
	}
}

G3D::Vector3 Body::getBranchCofmPos() const
{
	return cofm ? pv.position.pointToWorldSpace(getPos()) : getCoordinateFrame().translation;
}

G3D::CoordinateFrame Body::getBranchCofmCoordinateFrame() const
{
	return G3D::CoordinateFrame(getPV().position.rotation, getBranchCofmPos());
}

G3D::Matrix3 Body::getIWorldAtPoint(const G3D::Vector3& point) const
{
	float _mass = mass;
	updatePV(); //supposed to be inlined probably
	G3D::Matrix3 iBody = moment;
	G3D::Matrix3& iWorldAtCofm = Math::momentToWorldSpace(iBody, pv.position.rotation);
	return Math::getIWorldAtPoint(getPV().position.translation, point, iWorldAtCofm, _mass);
}

G3D::Matrix3 Body::getBranchIWorldAtPoint(const G3D::Vector3& point) const
{
	float _mass = getBranchMass();
	updatePV(); //more probably inlined updatePV calls
	G3D::Matrix3 _moment = cofm ? cofm->getMoment() : moment;
	G3D::Matrix3& iWorldAtCofm = Math::momentToWorldSpace(_moment, pv.position.rotation);
	return Math::getIWorldAtPoint(getBranchCofmPos(), point, iWorldAtCofm, _mass);
}

void Body::matchDummy()
{
	accumulateForceAtBranchCofm(G3D::Vector3(1.3f,1.2f,1.7f));
	accumulateTorque(G3D::Vector3(6.3f,4.2f,9.7f));
	setMoment(G3D::Matrix3());
	resetAccumulators();
	mass = getBranchMass();
	index = getBranchForce().z + getBranchTorque().y + getBranchIBodyV3().x;
}