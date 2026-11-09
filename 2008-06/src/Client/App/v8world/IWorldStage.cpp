#include "v8world/IWorldStage.h"
#include "v8world/Edge.h"

namespace RBX
{
	void IWorldStage::onEdgeAdded(Edge* e)
	{
		                            ;
		e->putInPipeline(this);
		getDownstreamWS()->onEdgeAdded(e);
	}

	void IWorldStage::onEdgeRemoving(Edge* e)
	{
		                            ;
		getDownstreamWS()->onEdgeRemoving(e);
		e->removeFromStage(this);
	}

	int IWorldStage::getMetric(MetricType metricType)
	{
		                            ;
		return getDownstreamWS()->getMetric(metricType);
	}
}
