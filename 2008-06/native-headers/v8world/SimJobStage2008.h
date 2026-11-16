#pragma once
// 2008-06 native RBX::SimJobStage (inactive). Declared under a non-colliding name: the original path
// v8world/SimJobStage.h is included by the donor v8world/World.h, so a header at that path would shadow the donor for
// every unit that includes World.h. A unit must not include both this header and the donor v8world/SimJobStage.h (or
// World.h). Bases IStage / IWorldStage are the donor headers (see CleanStage2008.h).
// Every SimJobStage field, slot and size below is read from the 2008-06 binary:
//   RTTI     SimJobStage 0084b174 -> IWorldStage -> IStage (all mdisp 0).
//   slots    7: 0 scalar deleting dtor (0064d380, the destructor inlined), 1 getStageType (005cb9d0 `mov eax, 6`),
//            2 / 3 IStage::stepWorld / getKernel (0064a380 / 0064a390), 4 onEdgeAdded (0064d060), 5 onEdgeRemoving
//            (0064d090), 6 IWorldStage::getMetric (0064a3d0).
//   size     0x2c (SleepStage() 0064b8e0 news 0x2c and calls SimJobStage(this, world) 0064d300).
//   ctor     0064d300: downstream = new Kernel(this) (0x24, 005fb650), upstream +0x4, world +0xc, std::list
//            constructor 0061a200 at +0x10.
//   dtor     ??_G 0064d380: vtable store, list _Tidy 00682b40 and the aux delete at +0x10, then the donor ~IStage body.
//   fields   simJobs +0x10: std::list<SimJob*> (0x1c bytes under these flags); the insert 0064d0f0 links the job and
//            stores the list iterator in the job (+0x1c, SimJob2008.h).
//   jobs     0064d0f0 (129 B, thiscall, ret 4): if job->slot 2 (getAssembly) is non-null, stores the job at that
//            assembly's +0x40; then inserts the job before simJobs.end() (inline _Buynode 0064d0b0, _Incsize 005f26c0)
//            and stores the returned iterator (container +0x1c, node +0x20) in the job. 0064d180 (95 B, ret 4): when
//            simJobs.size() (+0x28) > 1 takes a neighbour job through 004cb480 (folded COMDAT: steps job's
//            iterator, wrapping at end()), else NULL; hands the job's mechanisms to it (cdecl 005e53a0(job, other),
//            SimJob unit); erases job->stageIterator (005888f0, folded list erase); clears the assembly's +0x40 through
//            slot 2. 0064d200 (Assembly in, news AssemblySimJob 0x28) calls 0064d0f0 directly; 0064d2a0 calls 0064d180
//            directly. 0064d1e0 (`jmp 0064d0f0`) and 0064d1f0 (`jmp 0064d180`) are the 5-byte tail-call entries other
//            units call (HumanoidStates3.cpp MovingNoPhysicsBase::release 0066ed50 calls 0064d1f0). Names are analog
//            names (no registry name: all four are placeholders); which pair is public is inferred from the callers.
//            0064d0f0 / 0064d180 are built in SimJobStage2008.cpp through v8world/AssemblyLayout.h (+0x40 SimJob
//            back-link). 004cb480 (146 B, thiscall on the stage, ret 4; folded COMDAT, placeholder) is the neighbour-job
//            helper 0064d180 calls: it = job->stageIterator; ++it; it == simJobs.end() ? *simJobs.begin() : *it.
//            Declared inline in-class below (analog name getNextSimJob). Not byte-exact (parked after 3 trials): this
//            form is 147 B with the same blocks and checks, but keeps the stepped node in ebp for the whole body where
//            the target pushes ebp only around the end() compare (`mov ebx,[ebx]; push ebp; mov ebp,[edi+0x24]`).
//            Rejected: `if (it == end()) it = begin(); return *it;` (112 B, one shared deref) and
//            `return (++it == end()) ? front() : *it;` (156 B, end() hoisted into a stack slot).
#include <list>
#include "v8world/IWorldStage.h"
#include "v8world/SimJob2008.h" // getNextSimJob reads SimJob::stageIterator (+0x1c)

struct NativeKernelStagesLayout;

namespace RBX
{
	class Assembly;
	class SimJob;
	class Edge;
	class World;

	class SimJobStage : public IWorldStage
	{
		friend struct ::NativeKernelStagesLayout; // tests/NativeKernelStagesLayout.cpp offset asserts

	private:
		std::list<SimJob*> simJobs;                       // +0x10

	public:
		SimJobStage(IStage* upstream, World* world);      // 0064d300 (SimJobStage2008Ctor.cpp: 2008 Kernel)
		virtual ~SimJobStage()                            // slot 0 (??_G 0064d380)
		{
		}
		virtual StageType getStageType();                 // slot 1 (005cb9d0; opt-in kernel-stages IStage)
		virtual void onEdgeAdded(Edge* e);                // slot 4 (0064d060)
		virtual void onEdgeRemoving(Edge* e);             // slot 5 (0064d090)

		void addSimJob(SimJob* job);                      // 0064d1e0 (`jmp 0064d0f0`; analog name)
		void removeSimJob(SimJob* job);                   // 0064d1f0 (`jmp 0064d180`; analog name)
		void addAssembly(Assembly* a);                    // 0064d200 (analog name; SleepStage 0064ae90 calls it)
		void removeAssembly(Assembly* a);                 // 0064d2a0 (analog name; SleepStage 0064ae90 / 0064b0a0 / 0064c470)
		void notifyMovingPrimitives();                    // 0064d3d0 (openrbx name; caller 005e9fd0)

	private:
		void insertSimJob(SimJob* job);                   // 0064d0f0 (analog name)
		void eraseSimJob(SimJob* job);                    // 0064d180 (analog name)

		SimJob* getNextSimJob(SimJob* job)                // 004cb480 (folded COMDAT; analog name)
		{
			std::list<SimJob*>::iterator it = job->stageIterator;
			++it;
			if (it == simJobs.end())
			{
				return *simJobs.begin();
			}
			return *it;
		}
	};
}
