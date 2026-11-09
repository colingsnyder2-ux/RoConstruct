#pragma once
#include <set>
#include <map>
#include "v8world/IPipelined.h"
#include "v8world/IWorldStage.h"

namespace RBX
{
	class Joint;
	class Primitive;
	class ClumpStage;
	class Edge;
	class World;

	class JointStage : public IWorldStage
	{
	private:
		std::set<Joint*> incompleteJoints;
		std::multimap<Primitive*, Joint*> jointMap;
	  
	private:
		ClumpStage* getClumpStage();
		void moveEdgeToDownstream(Edge* e);
		void removeEdgeFromDownstream(Edge* e);
		void moveJointToDownstream(Joint* j);
		void removeJointFromDownstream(Joint* j);
		bool jointInList(Joint* j);
		void removeFromList(Joint* j);
		void insertToList(Joint* j);
		bool pairInMap(Joint* j, Primitive* p);
		void insertToMap(Joint* j, Primitive* p);
		void removeFromMap(Joint* j, Primitive* p);
		bool edgeHasPrimitivesDownstream(Edge* e);
		bool acceptsJoint(Joint* j);
		void addLocally(Joint* j);
	public:
		//JointStage(const JointStage&);
		JointStage(IStage* upstream, World* world);
		virtual ~JointStage();
	public:
		virtual IStage::StageType getStageType()
		{
			return JOINT_STAGE;
		}
		virtual void onEdgeAdded(Edge* e);
		virtual void onEdgeRemoving(Edge* e);
		void onPrimitiveAdded(Primitive* p);
		void onPrimitiveRemoving(Primitive* p);
		void onJointPrimitiveNulling(Joint* j, Primitive* nulling);
		void onJointPrimitiveSet(Joint* j, Primitive* p);
		//JointStage& operator=(const JointStage&);
	};
}
