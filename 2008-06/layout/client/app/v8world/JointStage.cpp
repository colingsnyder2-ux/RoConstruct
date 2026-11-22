#undef _RELEASEASSERT
#include "v8world/JointStage2008.h"
#include "v8world/ClumpStage.h"
#include "v8world/Primitive.h"
#include "v8world/Joint.h"
#include <vector>

namespace RBX
{
	void JointStage::onPrimitiveAdded(Primitive* p)
	{
		p->putInStage(this);
		rbx_static_cast<ClumpStage*>(getDownstream())->onPrimitiveAdded(p);

		std::vector<Joint*> moveJoints;

		typedef std::multimap<Primitive*, Joint*>::iterator Iterator;
		for (Iterator it = jointMap.JointMap::Base::lower_bound(p); it != jointMap.upper_bound(p); ++it)
		{
			Joint* j = it->second;
			Primitive* p0 = j->getPrimitive(0);
			Primitive* p1 = j->getPrimitive(1);
			if (p0->inPipeline() && p1->inPipeline() && p0->downstreamOfStage(this) && p1->downstreamOfStage(this))
				moveJoints.push_back(it->second);
		}

		for (size_t i = 0; i < moveJoints.size(); ++i)
		{
			Joint* j = moveJoints[i];
			incompleteJoints.erase(j);
			removeFromMap(j, j->getPrimitive(0));
			removeFromMap(j, j->getPrimitive(1));
			getDownstreamWS()->onEdgeAdded(j);
		}
	}

	void JointStage::onPrimitiveRemoving(Primitive* p)
	{
		std::vector<Joint*> moveJoints;

		for (Joint* j = p->getFirstJoint(); j; j = p->getNextJoint(j))
		{
			if (j->getJointType() != Joint::ANCHOR_JOINT && j->getJointType() != Joint::FREE_JOINT && j->downstreamOfStage(this))
				moveJoints.push_back(j);
		}

		for (size_t i = 0; i < moveJoints.size(); ++i)
		{
			Joint* j = moveJoints[i];
			getDownstreamWS()->onEdgeRemoving(j);
			insertToListAndMap(j);
		}

		rbx_static_cast<ClumpStage*>(getDownstream())->onPrimitiveRemoving(p);
		p->removeFromStage(this);
	}
}
