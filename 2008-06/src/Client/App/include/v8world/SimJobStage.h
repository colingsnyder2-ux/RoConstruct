#pragma once
#include <list>
#include "v8world/IWorldStage.h"
#include "v8world/Mechanism.h"

namespace RBX
{
	class Assembly;
	class World;
	class Edge;

	class SimJobStage : public IWorldStage
	{
		std::list<SimJob*> jobs;
	public:
		SimJobStage(IStage* upstream, World* world);
		virtual ~SimJobStage();
		virtual StageType getStageType() { return SIMJOB_STAGE; }
		virtual void onEdgeAdded(Edge* e);
		virtual void onEdgeRemoving(Edge* e);
		void onAssemblyAdded(Assembly* a);
		void onAssemblyRemoving(Assembly* a);
		void notifyMovingPrimitives();
		void insertJob(SimJob* job);
		void removeJob(SimJob* job);

		template<typename Class>
		void reportJobs(Class& callback, MechanismTracker& tracker, const SimJob* ignore)
		{
			if (jobs.empty()) return;
			SimJob* start = tracker.tracking() ? tracker.getJob() : jobs.front();
			std::list<SimJob*>::iterator it = start->jobIterator;
			do
			{
				SimJob* current = *it;
				if (++it == jobs.end()) it = jobs.begin();
				if (current != ignore && !callback(*current))
				{
					tracker.setJob(*it);
					return;
				}
			} while (*it != start);
			tracker.setJob(start);
		}
	};
	typedef char SimJobStageSize[sizeof(SimJobStage)==44?1:-1];
}
