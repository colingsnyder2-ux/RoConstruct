#pragma once
#include "v8kernel/IStage.h"

namespace RBX
{
	class World;
	class Edge;

	class __declspec(novtable) IWorldStage : public IStage
	{
	public:
		enum MetricType
		{
			NUM_CONTACTSTAGE_CONTACTS,
			NUM_STEPPING_CONTACTS,
			NUM_TOUCHING_CONTACTS,
			MAX_TREE_DEPTH
		};

	private:
		World* world;
  
	public:
		//IWorldStage(const IWorldStage&);
		IWorldStage(IStage* upstream, IStage* downstream, World* world)
			: IStage(upstream, downstream),
			  world(world)
		{
		}
	public:
		IWorldStage* getUpstreamWS()
		{
			return rbx_static_cast<IWorldStage*>(getUpstream());
		}
		IWorldStage* getDownstreamWS()
		{
			return rbx_static_cast<IWorldStage*>(getDownstream());
		}
		World* getWorld() { return world; }
		virtual void onEdgeAdded(Edge* e);
		virtual void onEdgeRemoving(Edge* e);
		virtual int getMetric(MetricType metricType);
	public:
		virtual ~IWorldStage() {}
	public:
		//IWorldStage& operator=(const IWorldStage&);
	};
}
