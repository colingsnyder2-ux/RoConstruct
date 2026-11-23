// =============================================================================
// SimJob.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8world/SimJob.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
