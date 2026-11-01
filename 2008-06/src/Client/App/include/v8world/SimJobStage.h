#pragma once
#include <list>
#include "v8world/IWorldStage.h"

namespace RBX
{
	class Mechanism;
	class MechanismTracker;
	class Assembly;
	class World;
	class Edge;

	class SimJobStage : public IWorldStage
	{
	private:
		std::list<Mechanism*> mechanisms;
	  
	private:
		void combineMechanisms(Edge* e);
		void insertMechanism(Mechanism* m);
		void destroyMechanism(Mechanism* m);
		void splitMechanisms(Assembly*, Assembly*);
		bool validateEdge(Edge* e);
	public:
		Mechanism* nextMechanism(std::list<Mechanism*>& list, const Mechanism* current);
	public:
		SimJobStage(IStage* upstream, World* world);
		virtual ~SimJobStage();
	public:
		virtual StageType getStageType()
		{
			return SIMJOB_STAGE;
		}
		virtual void onEdgeAdded(Edge* e);
		virtual void onEdgeRemoving(Edge* e);
		void onAssemblyAdded(Assembly* a);
		void onAssemblyRemoving(Assembly* a);
		void notifyMovingPrimitives();

		template<typename Class>
		void reportMechanisms(Class& callback, MechanismTracker& tracker, const Mechanism* ignore);
	};
}

// rebuild overlay: SimJobStage::reportMechanisms rbxgs declares but never defines
#include "v8world/Mechanism.h"
namespace RBX
{
	template<typename Class>
	void SimJobStage::reportMechanisms(Class& callback, MechanismTracker& tracker, const Mechanism* ignore)
	{
		if (mechanisms.empty())
			return;
		Mechanism* start = tracker.tracking() ? tracker.getMechanism() : mechanisms.front();
		Mechanism* current = start;
		do
		{
			if (current != ignore && !callback(*current))
			{
				tracker.setMechanism(nextMechanism(mechanisms, current));  // reporter is full: resume after this one
				return;
			}
			current = nextMechanism(mechanisms, current);
		} while (current != start);
		tracker.setMechanism(start);
	}
}
