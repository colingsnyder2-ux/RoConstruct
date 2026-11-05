#pragma once
#include <boost/scoped_ptr.hpp>
#include "v8world/IWorldStage.h"
#include "v8world/Contact.h"
#include "util/IndexArray.h"
#include "util/Profiling.h"

namespace RBX
{
	class Edge;
	class Joint;
	class World;
	class Assembly;
	
	class CollisionStage : public IWorldStage
	{
	private:
		int numContactsInStage;
		IndexArray<Contact, &Contact::steppingIndexFunc> stepping;
	public:
		boost::scoped_ptr<Profiling::CodeProfiler> profilingCollision;
	  
	private:
		bool getOkToSim(Contact* c, bool& okToStep);
		bool confirmOneClumpHere(Edge*);
		Contact* getContactBetweenPrimitives(Joint*);
		void removeContactFromDownstreamStage(Contact* c);
		void removeContact(Contact* c);
		void updateContact(Contact* c);
		void onJointAdded(Joint* j);
		void onJointRemoved(Joint* j);
	public:
		//CollisionStage(const CollisionStage&);
		CollisionStage(IStage* upstream, World* world);
		virtual ~CollisionStage();
	public:
		virtual StageType getStageType()
		{
			return COLLISION_STAGE;
		}
		virtual void stepWorld(int worldStepId, int uiStepId, bool throttling);
		virtual void onEdgeAdded(Edge* e);
		virtual void onEdgeRemoving(Edge* e);
		virtual int getMetric(MetricType metricType);
		void onAssemblyAdded(Assembly* assembly);
		void onAssemblyRemoving(Assembly* assembly);
		void onPrimitiveCanCollideChanged(Primitive* p);
		void onSleepChanged(const Assembly* assembly);
		void onLosingContact(const G3D::Array<Contact*>& separating);
		//CollisionStage& operator=(const CollisionStage&);
	};
}
