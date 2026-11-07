// 2008-06 native RBX::Body (inactive): rows of the original Body unit (00613ef0..00614bc7) that need only the Body /
// Cofm layout of native-headers/v8kernel/Body2008.h. Rows that touch SimBody fields (setPv, setVelocity, setMass,
// setMoment, makeCofmDirty, step, setMeInParent, onChildAdded/Removed, setParent) or allocate a SimBody (Body())
// are not built: the 0xb4 SimBody layout is not derived. Verified by tests/record_native_body_primitive2008.py.
#include <boost/thread/once.hpp>
#include "v8kernel/Body2008.h"

namespace RBX
{
	Body* Body::worldBody;                       // 0097bec4
	int Body::nextStateIndex;                    // 0095a898

	static boost::once_flag worldBodyFlag = BOOST_ONCE_INIT;   // 0097bed8 (call_once flag of getWorldBody)

	// 00613ef0
	Body* Body::calcRoot()
	{
		return parent ? parent->calcRoot() : this;
	}

	// 00613f20
	int Body::getNextStateIndex()
	{
		nextStateIndex++;
		if (nextStateIndex == 0x7fffffff)
			nextStateIndex = 1;
		return nextStateIndex;
	}

	// 00613f40
	void Body::advanceStateIndex()
	{
		stateIndex = getNextStateIndex();
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
