// 2008-06 native RBX::SimJob / AssemblySimJob (inactive); evidence in native-headers/v8world/SimJob2008.h.
// Verified by tests/record_native_kernel_stages.py. Rows: SimJob() 005e50f0, ~SimJob 005e5150, the scalar deleting
// destructor 005e5190 (vtable 0083f72c is emitted here), AssemblySimJob(assembly) 005e51e0 (vtable 0083f73c; its
// slots 1 / 2 fold into 0074eed0).
// >>> native-status (generated) -- do not edit >>>
// SimJob2008 | 2008-06 | draft (no current byte proof)
// 0/3 mapped addresses byte-exact | 3 unproved | no mapped strings | by tester (+2) (mixed 3)
// <<< native-status | src 812bdd77 | roc native-status --write
#undef _RELEASEASSERT
#include "v8world/SimJob2008.h"
#include <algorithm> // std::find for util/StlExtra.h (it does not include it)
#include "util/StlExtra.h" // fastRemoveShort 005e5200 (registry: fastRemoveShort<Assembly*>, folded)

namespace RBX
{
	// 005e50f0
	SimJob::SimJob()
	{
	}

	// 005e5150
	SimJob::~SimJob()
	{
	}

	// 005e51e0
	AssemblySimJob::AssemblySimJob(Assembly* assembly)
		: assembly(assembly)
	{
	}

	// 005e5320 (analog name)
	void Mechanism::stopTracking()
	{
		if (simJob)
		{
			fastRemoveShort(simJob->mechanisms, this);
			simJob = NULL;
		}
	}

	// 005e5350 (analog name)
	void Mechanism::setSimJob(SimJob* job)
	{
		stopTracking();
		if (job)
		{
			job->mechanisms.push_back(this);
			simJob = job;
		}
	}

	// 005e53a0 (cdecl; analog name)
	void SimJob::transferMechanisms(SimJob* from, SimJob* to)
	{
		while (from->mechanisms.size() > 0)
		{
			from->mechanisms.back()->setSimJob(to);
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Mechanism *> >;
template class std::list<RBX::SimJob *,std::allocator<RBX::SimJob *> >;
template class std::vector<RBX::Mechanism *,std::allocator<RBX::Mechanism *> >;
