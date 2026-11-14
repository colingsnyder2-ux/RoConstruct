// 2008-06 native RBX::SimJobStage (inactive); evidence in native-headers/v8world/SimJobStage2008.h.
// Verified by tests/record_native_kernel_stages.py. Rows built here: onEdgeAdded 0064d060, onEdgeRemoving 0064d090.
// The constructor 0064d300 (with the inline destructor, the scalar deleting destructor 0064d380 and the vtable
// 0084b174) is built from native-classes/SimJobStage2008Ctor.cpp: it news the 2008 Kernel (Kernel2008.h), which cannot
// share a unit with the donor v8world/Edge.h (IPipelined.h includes the donor v8kernel/Kernel.h). The insert 0064d0f0
// is built here through the 2008 Assembly layout view (v8world/AssemblyLayout.h, +0x40 SimJob back-link). Not built:
// the erase 0064d180 needs SimJobStage2008.h / SimJob2008.h declarations for the neighbour-job member 004cb480
// (thiscall on the stage, folded COMDAT) and the cdecl mechanism transfer 005e53a0 (SimJob unit); 0064d200 / 0064d2a0
// and 0064d3d0 / 0064d410 need a 2008 Assembly (IPipelined slots, 005e6110 / 005e6160), Kernel 005fb0e0, Mechanism.
// >>> native-status (generated) -- do not edit >>>
// SimJobStage2008 | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by king_originala (+1) (gpt-6.1-sol)
// <<< native-status | src 85b1689e | roc native-status --write
#include "v8world/SimJobStage2008.h"
#include "v8world/SimJob2008.h"
#include "v8world/Edge.h"
#include "v8world/AssemblyLayout.h" // 2008 Assembly +0x40 SimJob back-link (no native 2008 Assembly declaration)

namespace RBX
{
#ifdef NATIVE_KERNEL_STAGES_PENDING
	// 005cb9d0 (folded `mov eax, 6`); needs the 2008 StageType (generated v8kernel/IStage.h).
	IStage::StageType SimJobStage::getStageType()
	{
		return SIMJOB_STAGE;
	}
#endif

	// 0064d060
	void SimJobStage::onEdgeAdded(Edge* e)
	{
		e->putInStage(this);
		e->putInKernel(getKernel());
	}

	// 0064d090
	void SimJobStage::onEdgeRemoving(Edge* e)
	{
		e->removeFromKernel();
		e->removeFromStage(this);
	}

	// 0064d0f0 (analog name): points the job's assembly (SimJob slot 2) back at the job (+0x40), then links the job at
	// the end of simJobs (push_back: inline _Buynode 0064d0b0, _Incsize 005f26c0) and keeps --end() in the job (+0x1c).
	void SimJobStage::insertSimJob(SimJob* job)
	{
		if (job->getAssembly())
		{
			AssemblyLayout::fields(job->getAssembly())->simJob = job;
		}
		simJobs.push_back(job);
		job->stageIterator = --simJobs.end();
	}

	// Parked (not credited): the prover finds no candidate for these 5-byte tail-jmp bodies (registry names for
	// 0064d1e0 / 0064d1f0 are placeholders and a lone `jmp rel32` has no unique byte match).
	// 0064d1e0 (`jmp 0064d0f0`: tail call to the insert above)
	void SimJobStage::addSimJob(SimJob* job)
	{
		insertSimJob(job);
	}

	// 0064d1f0 (`jmp 0064d180`: tail call to the erase, not built here; see the file comment)
	void SimJobStage::removeSimJob(SimJob* job)
	{
		eraseSimJob(job);
	}
}
