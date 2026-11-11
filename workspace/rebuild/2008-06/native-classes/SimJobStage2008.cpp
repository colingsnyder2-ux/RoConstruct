// 2008-06 native RBX::SimJobStage (inactive); evidence in native-headers/v8world/SimJobStage2008.h.
// Verified by tests/record_native_kernel_stages.py. Rows built here: onEdgeAdded 0064d060, onEdgeRemoving 0064d090.
// The constructor 0064d300 (with the inline destructor, the scalar deleting destructor 0064d380 and the vtable
// 0084b174) is built from native-classes/SimJobStage2008Ctor.cpp: it news the 2008 Kernel (Kernel2008.h), which cannot
// share a unit with the donor v8world/Edge.h (IPipelined.h includes the donor v8kernel/Kernel.h). The assembly /
// mechanism rows (0064d0f0 .. 0064d2a0, 0064d3d0, 0064d410) need Assembly / Mechanism / ContactManager (not built).
// >>> native-status (generated) -- do not edit >>>
// SimJobStage2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 85b1689e | roc native-status --write
#include "v8world/SimJobStage2008.h"
#include "v8world/SimJob2008.h"
#include "v8world/Edge.h"

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
}
