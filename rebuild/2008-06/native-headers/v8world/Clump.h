#pragma once
#include <boost/noncopyable.hpp>
#include <set>
#include "util/ComputeProp.h"
#include "util/RunningAverage.h"

namespace RBX
{
	class Assembly;
	class Primitive;
	class Anchor;
	class RigidJoint;
	class Edge;
	class Kernel;
	class Body;

	namespace Sim
	{
		enum AssemblyState;
	}

	class SpanLink
	{
	public:
		Primitive* parent;
		RigidJoint* joint;
  
	public:
		SpanLink(Primitive* parent, RigidJoint* joint)
			: parent(parent),
			  joint(joint)
		{
		}
		SpanLink()
			: parent(NULL),
			  joint(NULL)
		{
		}
	public:
		Primitive* child() const;
  
	public:
		static Primitive* isSpanningJoint(RigidJoint* r);
		static bool isDownstreamSpanningJoint(Primitive* p, RigidJoint* r);
		static bool isUpstreamSpanningJoint(Primitive*, RigidJoint*);
		static bool spansToChild(RigidJoint*, Primitive*);
		static SpanLink bestSpanLink(const SpanLink& s0, const SpanLink& s1);
	};

	class Clump : public boost::noncopyable
	{
	private:
		Sim::AssemblyState sleepStatus;
		RunningAverageState runningAverageState;
		Assembly* assembly;
		Primitive* rootPrimitive;
		Anchor* anchor;
		bool canSleep;
		std::set<Primitive*> primitives;
		std::set<RigidJoint*> inconsistentJoints;
		ComputeProp<float, Clump> MaxRadius;
	private:
		static Primitive* tempChild;
  
	private:
		float computeMaxRadius() const;
		Body* getRootBody() const;
		bool computeCanSleep();
		bool containsPrimitive(Primitive* p) const;
		void setParent(Primitive* p, Primitive* newParent);
		void setSpanParent(Primitive* onTree, RigidJoint* stop);
		void renumberSpanTree(Primitive* onTree);
		SpanLink findBestOutsideLink(Primitive* treeRoot, Primitive* current);
		bool inSpanTree(Primitive* p, Primitive* treeRoot);
		bool okSpanTree(Primitive*, RigidJoint*);
	public:
		//Clump(const Clump&);
		Clump(Primitive*);
		~Clump();
	public:
		const Primitive* getRootPrimitive() const
		{
			return rootPrimitive;
		}
		Primitive* getRootPrimitive()
		{
			return rootPrimitive;
		}
		const Assembly* getRootAssembly() const;
		Assembly* getRootAssembly();
		Assembly* getAssembly() const
		{
			return assembly;
		}
		void setAssembly(Assembly* a)
		{
			assembly = a;
		}
		void addPrimitive(Primitive* p, Primitive* parent, RigidJoint* j);
		void removePrimitive(Primitive* p);
		void removeAllPrimitives();
		void getRigidJoints(std::set<RigidJoint*>& internalRigids, std::set<RigidJoint*>& externalRigids);
		void addAnchor(Anchor* a);
		Anchor* removeAnchor();
		bool getAnchored() const
		{
			return anchor != NULL;
		}
		bool getCanSleep() const
		{
			return canSleep;
		}
		Sim::AssemblyState getSleepStatus()
		{
			return sleepStatus;
		}
		bool moving();
		void putInKernel(Kernel* kernel);
		void removeFromKernel(Kernel* kernel);
		bool calcShouldSleep();
		bool okNeighborSleep();
		bool forceNeighborAwake();
		std::set<RigidJoint*>& getInconsistents()
		{
			return inconsistentJoints;
		}
		void addInconsistent(RigidJoint* r);
		void removeInconsistent(RigidJoint* r);
		bool containsInconsistent(RigidJoint* r);
		bool spanningTreeAdjust(RigidJoint* removing);
		void setSleepStatus(Sim::AssemblyState _set);
		void onPrimitiveCanSleepChanged(Primitive* p);
		Clump* otherClump(Edge* e) const;
		int size()
		{
			return (int)primitives.size(); // guess
		}
		std::set<Primitive*>::const_iterator clumpPrimBegin() const
		{
			return primitives.begin();
		}
		std::set<Primitive*>::const_iterator clumpPrimEnd() const
		{
			return primitives.end();
		}
		//Clump& operator=(const Clump&);
  
	private:
		static float sleepTolerance();
	};
}
// 2008-06 native header port of rbxgs App/include/v8world/Clump.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
