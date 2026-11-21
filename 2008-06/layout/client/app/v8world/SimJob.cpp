#undef _RELEASEASSERT
#include "v8world/SimJob2008.h"
#include <algorithm> // std::find for util/StlExtra.h (it does not include it)
#include "util/StlExtra.h" // fastRemoveShort 005e5200 (registry: fastRemoveShort<Assembly*>, folded)

namespace RBX
{
	SimJob::SimJob()
	{
	}

	AssemblySimJob::AssemblySimJob(Assembly* assembly)
		: assembly(assembly)
	{
	}

	void Mechanism::stopTracking()
	{
		if (simJob)
		{
			fastRemoveShort(simJob->mechanisms, this);
			simJob = NULL;
		}
	}

	void Mechanism::setSimJob(SimJob* job)
	{
		stopTracking();
		if (job)
		{
			job->mechanisms.push_back(this);
			simJob = job;
		}
	}

	void SimJob::transferMechanisms(SimJob* from, SimJob* to)
	{
		while (!from->mechanisms.empty())
		{
			from->mechanisms.back()->setSimJob(to);
		}
	}
}

template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Mechanism *> >;
template class std::list<RBX::SimJob *,std::allocator<RBX::SimJob *> >;
template class std::vector<RBX::Mechanism *,std::allocator<RBX::Mechanism *> >;
