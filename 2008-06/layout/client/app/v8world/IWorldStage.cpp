#include "v8world/IWorldStage.h"

namespace RBX
{
	int IWorldStage::getMetric(MetricType metricType)
	{
		return getDownstreamWS()->getMetric(metricType);
	}
}

#include "v8world/ClumpStage2008.h"
#include "v8world/Joints2008.h"

namespace RBX
{
	void ClumpStage::onEdgeAdded(Edge* e)
	{
		IWorldStage::onEdgeAdded(e);
		if (e->getEdgeType() == Edge::JOINT)
		{
			Joint* joint = static_cast<Joint*>(e);
			Edge* entry = e;
			if (joint->canStepUi())
				set10.insert(entry);
		}
	}

	void ClumpStage::onEdgeRemoving(Edge* e)
	{
		if (e->getEdgeType() == Edge::JOINT)
		{
			Joint* joint = static_cast<Joint*>(e);
			Edge* entry = e;
			if (joint->canStepUi())
				set10.erase(entry);
		}
		IWorldStage::onEdgeRemoving(e);
	}
}
