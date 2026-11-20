// 2008-06 native RBX::Body (inactive): rows of the original Body unit (00613e80..00614bc7) against the Body / Cofm /
// SimBody layouts of native-headers/v8kernel/Body2008.h (SimBody 0xb4: constructor 00658ae0, step 00658fb0, Kernel
// insertBody 005fb0e0). Verified by tests/record_native_body_primitive2008.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include <boost/thread/once.hpp>
#include <limits.h>
#include "v8kernel/Body2008.h"

namespace RBX
{
	Body* Body::worldBody;                       // 0097bec4

	static boost::once_flag worldBodyFlag = BOOST_ONCE_INIT;   // 0097bed8 (call_once flag of getWorldBody)

	// 006149c0
	Body::Body()
		: leafBodyIndex(-1),
		  numConnectors(0),
		  unreadFlag(false),
		  root(NULL),
		  parent(NULL),
		  index(-1),
		  cofm(NULL),
		  simBody(NULL),
		  canThrottle(true),
		  link(NULL),
		  moment(G3D::Matrix3::zero()),
		  mass(0.0f),
		  stateIndex(getNextStateIndex())
	{
		root = this;
		simBody = new SimBody(this);
	}

	// 00613ef0
	Body* Body::calcRoot()
	{
		return parent ? parent->calcRoot() : this;
	}

	// 00613f20
	int Body::getNextStateIndex()
	{
		static int p;                            // 0095a898
		if (++p == INT_MAX)
			p = 1;
		return p;
	}

	// 00613f40
	void Body::advanceStateIndex()
	{
		stateIndex = getNextStateIndex();
	}

	// 00613f70
	void Body::makeCofmDirty()
	{
		if (!cofm || !cofm->getIsDirty())
		{
			if (getParent())
			{
				getParent()->makeCofmDirty();
			}
			else
			{
				if (simBody)
					simBody->makeDirty();
			}
			if (cofm)
				cofm->makeDirty();
		}
	}

	// 00613fb0
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

	// 00614040
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

	// 006140b0
	void Body::setMass(float _mass)
	{
		if (mass != _mass)
		{
			makeCofmDirty();
			mass = _mass;
		}
	}

	// 00614110
	void Body::setMoment(const G3D::Matrix3& _momentInBody)
	{
		if (moment != _momentInBody)
		{
			makeCofmDirty();
			moment = _momentInBody;
		}
	}

	// 00614200
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

	// 006142d0
	void Body::setMeInParent(const G3D::CoordinateFrame& _meInParent)
	{
		if (link)
		{
			link->setBody(NULL);
			link = NULL;
		}
		if (getParent())
		{
			meInParent = _meInParent;
			makeCofmDirty();
			root->advanceStateIndex();
		}
	}

	// 00614380
	void Body::setMeInParent(Link* _link)
	{
		if (link && link != _link)
			link->setBody(NULL);
		if (getParent())
		{
			link = _link;
			link->setBody(this);
			makeCofmDirty();
			root->advanceStateIndex();
		}
	}

	// 00614400
	void Body::setCoordinateFrame(const G3D::CoordinateFrame& worldCord)
	{
		setPv(PV(worldCord, getVelocity()));
	}

	// 00614480
	G3D::Vector3 Body::getBranchCofmPos() const
	{
		return cofm ? getCoordinateFrame().pointToWorldSpace(cofm->getCofmInBody()) : getCoordinateFrame().translation;
	}

	// 006144e0
	G3D::CoordinateFrame Body::getBranchCofmCoordinateFrame() const
	{
		return G3D::CoordinateFrame(getPV().position.rotation, getBranchCofmPos());
	}

	// 00614530
	void Body::resetRoot(Body* newRoot)
	{
		root = newRoot;
		for (int i = 0; i < children.size(); i++)
			children[i]->resetRoot(newRoot);
	}

	// 00614560
	G3D::Matrix3 Body::getIWorldAtPoint(const G3D::Vector3& point) const
	{
		return Math::getIWorldAtPoint(getPos(), point, getIWorld(), getMass());
	}

	// 006145e0
	G3D::Matrix3 Body::getBranchIWorldAtPoint(const G3D::Vector3& point) const
	{
		return Math::getIWorldAtPoint(getBranchCofmPos(), point, getBranchIWorld(), getBranchMass());
	}

	// 00614670
	float Body::kineticEnergy() const
	{
		// named result (the direct return schedules the matrix-row products differently; see the recorder)
		float calc = (pv.velocity.rotational.dot(getIWorld() * pv.velocity.rotational)
			+ pv.velocity.linear.dot(pv.velocity.linear) * mass) / 2;
		return calc;
	}

	// 00614760
	void Body::onChildRemoved(Body* child)
	{
		children.fastRemove(child);
		if (numChildren() == 0)
		{
			delete cofm;
			cofm = NULL;
		}
		makeCofmDirty();
	}

	// 006147f0
	void Body::onChildAdded(Body* child)
	{
		makeCofmDirty();
		children.fastAppend(child);
		if (!cofm)
			cofm = new Cofm(this);
	}

	// 006148b0
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
				newParent->onChildAdded(this);
			else
				simBody = new SimBody(this);
			Body* myRoot = getParent() ? getParent()->calcRoot() : this;
			myRoot->advanceStateIndex();
			resetRoot(myRoot);
		}
	}

	// 00614ac0
	Body::~Body()
	{
		if (parent)
			setParent(NULL);
		delete simBody;
		simBody = NULL;
	}

	// 00614b40 (boost::call_once target of getWorldBody)
	void Body::initWorldBody()
	{
		worldBody = new Body();
	}

	// 00614bb0
	Body* Body::getWorldBody()
	{
		boost::call_once(&initWorldBody, worldBodyFlag);
		return worldBody;
	}
}
