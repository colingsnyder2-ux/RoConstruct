// from server: 50% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs v8world/AssemblyStage.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/AssemblyStage.h"
#include "v8world/CollisionStage.h"
#include "v8world/Assembly.h"
#include "v8world/Joint.h"

namespace RBX
{
#pragma warning (push)
#pragma warning (disable : 4355) // warning C4355: 'this' : used in base member initializer list
	AssemblyStage::AssemblyStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new CollisionStage(this, world), world)
	{
	}
#pragma warning (pop)

	AssemblyStage::~AssemblyStage()
	{
		RBXASSERT(assemblies.empty());
		RBXASSERT(joints.empty());
	}

	void AssemblyStage::stepUi(int uiStepId)
	{
		typedef std::set<Joint*>::iterator JointIterator;
		for (JointIterator it = joints.begin(); it != joints.end(); it++)
		{
			Joint* j = *it;
			j->stepUi(uiStepId);
		}

		typedef std::set<Assembly*>::iterator AssemblyIterator;
		for (AssemblyIterator it = assemblies.begin(); it != assemblies.end(); it++)
		{
			Assembly* a = *it;
			a->stepUi(uiStepId);
		}
	}

	void AssemblyStage::onJointAdded(Joint* j)
	{
		bool inserted = joints.insert(j).second;
		RBXASSERT(inserted);
	}

	void AssemblyStage::onJointRemoving(Joint* j)
	{
		size_t removed = joints.erase(j);
		RBXASSERT(removed == 1);
	}

	void AssemblyStage::onEdgeAdded(Edge* e)
	{
		IWorldStage::onEdgeAdded(e);

		if (e->getEdgeType() == Edge::JOINT)
		{
			Joint* j = rbx_static_cast<Joint*>(e);
			onJointAdded(j);
		}
	}

	void AssemblyStage::onEdgeRemoving(Edge* e)
	{
		if (e->getEdgeType() == Edge::JOINT)
		{
			Joint* j = rbx_static_cast<Joint*>(e);
			onJointRemoving(j);
		}

		IWorldStage::onEdgeRemoving(e);
	}

	void AssemblyStage::onAssemblyAdded(Assembly* assembly)
	{
		assembly->putInStage(this);

		bool inserted = assemblies.insert(assembly).second;
		RBXASSERT(inserted);

		if (!assembly->getAnchored())
			rbx_static_cast<CollisionStage*>(getDownstreamWS())->onAssemblyAdded(assembly);
	}

	void AssemblyStage::onAssemblyRemoving(Assembly* assembly)
	{
		if (assembly->downstreamOfStage(this))
			rbx_static_cast<CollisionStage*>(getDownstreamWS())->onAssemblyRemoving(assembly);

		RBXASSERT(assembly->inStage(this));

		size_t removed = assemblies.erase(assembly);
		RBXASSERT(removed == 1);

		assembly->removeFromStage(this);
	}
}
