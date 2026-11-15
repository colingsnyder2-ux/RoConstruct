// 2008-06 native RBX::SimJobStage (inactive); evidence in native-headers/v8world/SimJobStage2008.h.
// Verified by tests/record_native_kernel_stages.py. Rows built here: onEdgeAdded 0064d060, onEdgeRemoving 0064d090.
// The constructor 0064d300 (with the inline destructor, the scalar deleting destructor 0064d380 and the vtable
// 0084b174) is built from native-classes/SimJobStage2008Ctor.cpp: it news the 2008 Kernel (Kernel2008.h), which cannot
// share a unit with the donor v8world/Edge.h (IPipelined.h includes the donor v8kernel/Kernel.h). The insert 0064d0f0
// and the erase 0064d180 are built here through the native 2008 Clump / Assembly (v8world/AssemblyLayout.h,
// NATIVE_CLUMP_DECL: +0x40 SimJob back-link); the erase calls the neighbour-job member 004cb480 (SimJobStage2008.h, inline) and the cdecl mechanism
// transfer SimJob::transferMechanisms 005e53a0 (SimJob2008.cpp). 0064d200 / 0064d2a0 (add / remove an assembly) are
// built below (the native Clump supplies getBody 005e6160 and getSimJob 005e6110). Also built: notifyMovingPrimitives 0064d3d0. 0064d410 is JointBuilder::canJoin (registry), not this unit.
// >>> native-status (generated) -- do not edit >>>
// SimJobStage2008 | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by king_originala (+1) (gpt-6.1-sol)
// <<< native-status | src 85b1689e | roc native-status --write
#include <algorithm>
#include "v8world/SimJobStage2008.h"
#include "v8world/SimJob2008.h"
#include "v8world/Edge.h"
#define NATIVE_IPIPELINED2008_DONOR // the donor IPipelined (v8world/Edge.h) has the 2008 layout (IPipelined2008.h)
#define NATIVE_CLUMP_DECL            // the native 2008 RBX::Clump / RBX::Assembly (+0x40 SimJob back-link)
#include "v8world/AssemblyLayout.h"

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
			job->getAssembly()->setSimJob(job);
		}
		simJobs.push_back(job);
		job->stageIterator = --simJobs.end();
	}

	// Parked (not credited; tool cause, not source): native_bulk.harvest only byte-indexes bodies of 6 bytes or more,
	// so a 5-byte `jmp rel32` gets candidates only from its registry name, and 0064d1e0 / 0064d1f0 are placeholders.
	// 0064d1e0 (`jmp 0064d0f0`: tail call to the insert above)
	void SimJobStage::addSimJob(SimJob* job)
	{
		insertSimJob(job);
	}

	// 0064d180 (analog name): hands the job's mechanisms to a neighbour job (004cb480; NULL when it is the only one,
	// SimJob::transferMechanisms 005e53a0), unlinks it from simJobs (erase 005888f0, folded) and clears its assembly's
	// +0x40 back-link (SimJob slot 2).
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

	// 0064d1f0 (`jmp 0064d180`: tail call to the erase above)
	void SimJobStage::removeSimJob(SimJob* job)
	{
		eraseSimJob(job);
	}

	// Declared in v8world/SimJobStage2008.h (public, analog names; registry rows are placeholders).
	// Batch 15 scratch compile with those two declarations: both bodies IDENTICAL to the target (relocs masked), and
	// every relocation names the target's callee (00645830 putInStage, 005e6160 Clump::getBody, 005fb0e0 / 005fb110
	// Kernel::insertBody / removeBody, 005e51e0 AssemblySimJob(Assembly*), 0064d0f0, 005e6110 Clump::getSimJob,
	// 0064d180, 00645840 removeFromStage).

	// 0064d200 (analog name; SleepStage 0064ae90 calls it): puts the assembly (its root Clump, IPipelined) in this
	// stage (IPipelined::putInStage 00645830) and its kernel (slot 1), inserts its body (005e6160) into the kernel
	// (005fb0e0), then links a new AssemblySimJob (0x28, 005e51e0) through insertSimJob 0064d0f0.
	void SimJobStage::addAssembly(Assembly* a)
	{
		a->putInStage(this);
		a->putInKernel(getKernel());
		getKernel()->insertBody(a->getBody());
		insertSimJob(new AssemblySimJob(a));
	}

	// 0064d2a0 (analog name; SleepStage 0064ae90 / 0064b0a0 / 0064c470 call it): erases and deletes the assembly's
	// SimJob (005e6110, eraseSimJob 0064d180, slot 0 with 1), removes its body (005e6160) from the kernel (005fb110),
	// takes it out of the kernel (slot 2) and back upstream (IPipelined::removeFromStage 00645840).
	void SimJobStage::removeAssembly(Assembly* a)
	{
		SimJob* job = a->getSimJob();
		eraseSimJob(job);
		delete job;
		getKernel()->removeBody(a->getBody());
		a->removeFromKernel();
		a->removeFromStage(this);
	}

	// 0064d3d0 (openrbx SimJobStage::notifyMovingPrimitives, there a for_each over the mechanisms; caller 005e9fd0):
	// every job's assembly (SimJob slot 2, asked twice) is told Clump::notifyMoved 005e6170.
	// The loop walks raw list nodes with no checked-iterator calls, as std::for_each does (it unwraps the checked
	// iterators); openrbx uses std::mem_fun(&Mechanism::notifyMovingPrimitives) (SimJob2008.h has no such member).
	// A function pointer gives the target's inlined loop (prove.py inactive_exact). Rejected: an explicit iterator
	// loop (136 B, _SECURE_SCL checks on every ++ / *) and std::for_each with an empty functor (41 B: for_each stays
	// out of line).
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
