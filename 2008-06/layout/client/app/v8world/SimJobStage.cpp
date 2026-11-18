#include <algorithm>
#include "v8world/SimJobStage2008.h"
#include "v8world/SimJob2008.h"
#include "v8world/Edge.h"
#define NATIVE_IPIPELINED2008_DONOR // the donor IPipelined (v8world/Edge.h) has the 2008 layout (IPipelined2008.h)
#define NATIVE_CLUMP_DECL            // the native 2008 RBX::Clump / RBX::Assembly (+0x40 SimJob back-link)
#include "v8world/AssemblyLayout.h"

namespace RBX
{
	IStage::StageType SimJobStage::getStageType()
	{
		return SIMJOB_STAGE;
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

	void SimJobStage::insertSimJob(SimJob* job)
	{
		if (job->getAssembly())
		{
			job->getAssembly()->setSimJob(job);
		}
		simJobs.push_back(job);
		job->stageIterator = --simJobs.end();
	}

	void SimJobStage::addSimJob(SimJob* job)
	{
		insertSimJob(job);
	}

	void SimJobStage::eraseSimJob(SimJob* job)
	{
		SimJob* other = (simJobs.size() > 1) ? getNextSimJob(job) : NULL;
		SimJob::transferMechanisms(job, other);
		simJobs.erase(job->stageIterator);
		if (job->getAssembly())
		{
			job->getAssembly()->setSimJob(NULL);
		}
	}

	void SimJobStage::removeSimJob(SimJob* job)
	{
		eraseSimJob(job);
	}

	void SimJobStage::addAssembly(Assembly* a)
	{
		a->putInStage(this);
		a->putInKernel(getKernel());
		getKernel()->insertBody(a->getBody());
		insertSimJob(new AssemblySimJob(a));
	}

	void SimJobStage::removeAssembly(Assembly* a)
	{
		SimJob* job = a->getSimJob();
		eraseSimJob(job);
		delete job;
		getKernel()->removeBody(a->getBody());
		a->removeFromKernel();
		a->removeFromStage(this);
	}

	static void notifyJobMovingPrimitives(SimJob* job)
	{
		if (job->getAssembly())
		{
			job->getAssembly()->notifyMoved();
		}
	}

	void SimJobStage::notifyMovingPrimitives()
	{
		std::for_each(simJobs.begin(), simJobs.end(), notifyJobMovingPrimitives);
	}
}
