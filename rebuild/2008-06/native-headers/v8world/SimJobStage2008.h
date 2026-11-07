#pragma once
// >>> native-status (generated) -- do not edit >>>
// SimJobStage2008 | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 8dab6772 | roc native-status --write
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
#include <list>
#include "v8world/IWorldStage.h"

struct NativeKernelStagesLayout;

namespace RBX
{
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
		virtual StageType getStageType();                 // slot 1 (005cb9d0; NATIVE_KERNEL_STAGES_PENDING)
		virtual void onEdgeAdded(Edge* e);                // slot 4 (0064d060)
		virtual void onEdgeRemoving(Edge* e);             // slot 5 (0064d090)
	};
}
