#pragma once
#include <set>
#include <g3d/array.h>
#include "v8world/IWorldStage.h"

namespace RBX
{
	class Contact;
	class Assembly;
	class SleepStage;

	class SeparateStage : public IWorldStage
	{
	private:
		G3D::Array<Contact*> separating;
		std::set<Contact*> inContact;
	  
	private:
		SleepStage* getSleepStage();
	public:
		//SeparateStage(const SeparateStage&);
		SeparateStage(IStage* upstream, World* world);
		virtual ~SeparateStage();
	public:
		virtual StageType getStageType()
		{
			return SEPARATE_STAGE;
		}
		virtual void stepWorld(int worldStepId, int uiStepId, bool throttling);
		virtual void onEdgeAdded(Edge* e);
		virtual void onEdgeRemoving(Edge* e);
		virtual int getMetric(MetricType metricType);
		void onAssemblyAdded(Assembly* assembly);
		void onAssemblyRemoving(Assembly* assembly);
		//SeparateStage& operator=(const SeparateStage&);
	};
}
