#include "v8world/SimJobStage.h"
#include "v8world/Assembly.h"
#include "v8world/Edge.h"
#include "v8kernel/Kernel.h"

namespace RBX
{
#pragma warning (push)
#pragma warning (disable : 4355)
	SimJobStage::SimJobStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new Kernel(this), world) {}
#pragma warning (pop)
	SimJobStage::~SimJobStage() { RBXASSERT(jobs.empty()); }

	// 0064d0f0 / 0064d180: association, saved iterator, observer transfer.
	// Externally registered jobs remain caller-owned.
	void SimJobStage::insertJob(SimJob* job)
	{
		if (job->getAssembly()) job->getAssembly()->setJob(job);
		jobs.push_back(job);
		job->jobIterator = --jobs.end();
	}

	void SimJobStage::removeJob(SimJob* job)
	{
		std::list<SimJob*>::iterator next = job->jobIterator;
		if (++next == jobs.end()) next = jobs.begin();
		MechanismTracker::transferTrackers(job, jobs.size() > 1 ? *next : NULL);
		jobs.erase(job->jobIterator);
		if (job->getAssembly()) job->getAssembly()->setJob(NULL);
	}

	// 0064d200 / 0064d2a0 own the ordinary assembly job, not a donor group.
	void SimJobStage::onAssemblyAdded(Assembly* a)
	{
		a->putInStage(this);
		a->putInKernel(getKernel());
		insertJob(new AssemblyJob(a));
	}

	void SimJobStage::onAssemblyRemoving(Assembly* a)
	{
		SimJob* job = a->getJob();
		removeJob(job);
		delete job;
		a->removeFromKernel();
		a->removeFromStage(this);
	}

	void SimJobStage::notifyMovingPrimitives()
	{
		for (std::list<SimJob*>::iterator it = jobs.begin(); it != jobs.end(); ++it)
			if ((*it)->getAssembly()) (*it)->getAssembly()->notifyMoved();
	}

	void SimJobStage::onEdgeAdded(Edge* e)
	{
		e->putInStage(this);
		e->putInKernel(getKernel());
	}

	void SimJobStage::onEdgeRemoving(Edge* e)
	{
		e->removeFromKernel();
		e->removeFromStage(this);
	}
}
