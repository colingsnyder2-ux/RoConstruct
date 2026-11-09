// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs roc_espeon_aug2007_body_trivial_5449b42182b29fed.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8kernel/KernelIndex.h", "../roc_espeon_aug2007_kernelindex_header_d7778b4d74bcf4c0.cpp")
#define _MT 1
#define _DLL 1
#pragma include_alias("v8kernel/Body.h", "../roc_espeon_aug2007_body_header_b251c002665e01af.cpp")
#pragma include_alias("util/Extents.h", "../roc_espeon_aug2007_extents_inline_58e475d56d206314.cpp")
#pragma include_alias("reflection/object.h", "../roc_espeon_aug2007_describedbase_e64c736f24da029d.cpp")
#pragma include_alias("util/Debug.h", "../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp")
#pragma include_alias("util/Events.h", "../roc_espeon_aug2007_ctor_notifier_131e539308ae6945.cpp")
#pragma include_alias("reflection/reflection.h", "../roc_espeon_aug2007_described_inline_3639f053c7370446.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_header_7a4c998b489b0ddf.cpp")
#pragma include_alias("v8world/Primitive.h", "../roc_espeon_aug2007_primitive_trivial_header_ac300ff64c6fc5e6.cpp")
#include "v8kernel/Body.h"
#include "v8kernel/SimBody.h"
#include "util/Debug.h"
using namespace RBX;

Body::Body()
	:index(-1),
	canThrottle(true),
	cofm(NULL),
	root(NULL),
	parent(NULL),
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
	RBXASSERT(numChildren() == 0);
	if (parent)
		setParent(NULL);
	RBXASSERT(!parent);
	RBXASSERT(index == -1);
	RBXASSERT(simBody);
	delete simBody;
	simBody = NULL;
	RBXASSERT(!cofm);
	RBXASSERT(root == this);
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
	RBXASSERT(newRoot == calcRoot());
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
		// TODO: this match is super fake, i dont know roblox managed to create this cursed assertion
		#if defined(_DEBUG) || defined(_RELEASEASSERT)
		if (Debugable::assertAction == Debugable::CrashOnAssert)
		{
			if (parent)
				parent->validateParentCofmDirty();
			RBXASSERT(getRootSimBody()->getDirty());
		}
		#endif
	}
	else
	{
		if (getParent())
		{
			RBXASSERT(!simBody);
			getParent()->makeCofmDirty();
		}
		else
		{
			RBXASSERT(root == this);
			if (simBody)
				simBody->makeDirty();
		}
		if (cofm)
		{
			cofm->makeDirty();
			RBXASSERT(numChildren() > 0);
		}
		else
		{
			RBXASSERT(!numChildren());
		}
	}
}

void Body::onChildAdded(RBX::Body* child)
{
	makeCofmDirty();
	children.fastAppend(child);
	if (!cofm)
	{
		RBXASSERT(numChildren() == 1);
		cofm = new Cofm(this);
	}
}

void Body::onChildRemoved(RBX::Body* child)
{
	RBXASSERT(cofm);
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

void Body::step(float dt, bool throttling)
{
	RBXASSERT(!getParent());
	RBXASSERT(simBody);

	if (throttling && canThrottle)
	{
		simBody->resetAccumulators();
	}
	else
	{
		simBody->step(dt);

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
	RBXASSERT(!newParent || newParent->getParent() != this);
	RBXASSERT(newParent != this);

	if (parent != newParent)
	{

		if (getParent())
		{
			RBXASSERT(root == getParent()->getRoot());
			RBXASSERT(!simBody);
			parent->onChildRemoved(this);
		}
		else
		{
			RBXASSERT(root = this);
			RBXASSERT(simBody);
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
		resetRoot(myRoot);
	}
}

Body* Body::getWorldBody()
{
	static Body b = Body();
	return &b;
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
		return meInParent;
	}
	else
	{
		RBXASSERT(parent);
		return parent->getMeInDescendant(descendant) * meInParent;
	}
}

void Body::setPv(const PV& _pv)
{
	if (parent)
	{
		RBXASSERT(0);
	}
	else
	{
		pv = _pv;
		if (simBody)
			simBody->makeDirty();
		advanceStateIndex();
	}
	RBXASSERT(Math::longestVector3Component(pv.position.translation) < 1000000.0);
	RBXASSERT(Math::isOrthonormal(pv.position.rotation));
	RBXASSERT(!Math::isNanInfDenormVector3(pv.position.translation));
	RBXASSERT(!Math::isNanInfDenormVector3(pv.velocity.linear));
	RBXASSERT(!Math::isNanInfDenormVector3(pv.velocity.rotational));
}

void Body::setCoordinateFrame(const G3D::CoordinateFrame& worldCord)
{
	updatePV();
	setPv(PV::PV(worldCord, pv.velocity));
}

void Body::setMeInParent(const G3D::CoordinateFrame& _meInParent)
{
	RBXASSERT(Math::longestVector3Component(_meInParent.translation) < 1000000.0);


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