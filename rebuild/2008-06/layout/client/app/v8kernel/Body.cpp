// =============================================================================
// Body.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8kernel/Body.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8kernel/Body2008.h"
#include "../../../../native-classes/PVFrameOps.h"

namespace RBX
{
	void Body::updatePV() const
	{
		if (parent)
		{
			const Body* rootNow = root;              // root read once per state-index read (edi in the target)
			rootNow->updatePV();
			if (stateIndex != rootNow->stateIndex)
			{
				parent->updatePV();
				const G3D::CoordinateFrame& meInParentNow = link ? link->getChildInParent() : meInParent;
				recoveredPVLocalFrame(parent->getPV(), meInParentNow, pv);
				const Body* rootAfter = root;
				rootAfter->updatePV();
				stateIndex = rootAfter->stateIndex;
			}
		}
	}
}

#include <boost/thread/once.hpp>
#include <limits.h>

namespace RBX
{
	Body* Body::worldBody;                       // 0097bec4

	static boost::once_flag worldBodyFlag = BOOST_ONCE_INIT;   // 0097bed8 (call_once flag of getWorldBody)

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

	Body* Body::calcRoot()
	{
		return parent ? parent->calcRoot() : this;
	}

	int Body::getNextStateIndex()
	{
		// INFERRED: initializer 1 from the client image, whose .data word at 0095a898 is 01 00 00 00 (the donor has no
		static int p = 1;                        // 0095a898
		if (++p == INT_MAX)
			p = 1;
		return p;
	}

	void Body::advanceStateIndex()
	{
		stateIndex = getNextStateIndex();
	}

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

	void Body::setMass(float _mass)
	{
		if (mass != _mass)
		{
			makeCofmDirty();
			mass = _mass;
		}
	}

	void Body::setMoment(const G3D::Matrix3& _momentInBody)
	{
		if (moment != _momentInBody)
		{
			makeCofmDirty();
			moment = _momentInBody;
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

	void Body::setCoordinateFrame(const G3D::CoordinateFrame& worldCord)
	{
		setPv(PV(worldCord, getVelocity()));
	}

	G3D::Vector3 Body::getBranchCofmPos() const
	{
		return cofm ? getCoordinateFrame().pointToWorldSpace(cofm->getCofmInBody()) : getCoordinateFrame().translation;
	}

	G3D::CoordinateFrame Body::getBranchCofmCoordinateFrame() const
	{
		return G3D::CoordinateFrame(getPV().position.rotation, getBranchCofmPos());
	}

	void Body::resetRoot(Body* newRoot)
	{
		root = newRoot;
		for (int i = 0; i < children.size(); i++)
			children[i]->resetRoot(newRoot);
	}

	G3D::Matrix3 Body::getIWorldAtPoint(const G3D::Vector3& point) const
	{
		return Math::getIWorldAtPoint(getPos(), point, getIWorld(), getMass());
	}

	G3D::Matrix3 Body::getBranchIWorldAtPoint(const G3D::Vector3& point) const
	{
		return Math::getIWorldAtPoint(getBranchCofmPos(), point, getBranchIWorld(), getBranchMass());
	}

	float Body::kineticEnergy() const
	{
		// named result (the direct return schedules the matrix-row products differently; see the recorder)
		float calc = (pv.velocity.rotational.dot(getIWorld() * pv.velocity.rotational)
			+ pv.velocity.linear.dot(pv.velocity.linear) * mass) / 2;
		return calc;
	}

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

	void Body::onChildAdded(Body* child)
	{
		makeCofmDirty();
		children.fastAppend(child);
		if (!cofm)
			cofm = new Cofm(this);
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
				newParent->onChildAdded(this);
			else
				simBody = new SimBody(this);
			Body* myRoot = getParent() ? getParent()->calcRoot() : this;
			myRoot->advanceStateIndex();
			resetRoot(myRoot);
		}
	}

	Body::~Body()
	{
		if (parent)
			setParent(NULL);
		delete simBody;
		simBody = NULL;
	}

	void Body::initWorldBody()
	{
		worldBody = new Body();
	}

	Body* Body::getWorldBody()
	{
		boost::call_once(&initWorldBody, worldBodyFlag);
		return worldBody;
	}
}
