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
// 2008-06 native header port of rbxgs App/include/v8world/JointStage.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
