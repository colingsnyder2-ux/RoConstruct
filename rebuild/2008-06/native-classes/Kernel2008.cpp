// 2008-06 native RBX::Kernel (inactive); evidence in native-headers/v8kernel/Kernel2008.h.
// Verified by tests/record_native_kernel_stages.py. Rows: the scalar deleting destructor 005fb0c0 (vtable 0084105c is
// emitted here), numBodies 005faa20, numPoints 005faa30, numConnectors 005faa40. The constructor 005fb650 and the
// destructor 005faca0 are built but not exact: the donor KernelData (0x30, inline destructor) and CodeProfiler
// (0x20040) differ from the 2008 ones (0x3c with an out-of-line destructor 005fa970; 0xc048), see PROPOSALS.
// stepWorld 005fb3f0 and the insert / remove rows are not built (Body / Point / Connector).
// >>> native-status (generated) -- do not edit >>>
// Kernel2008 | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src e8423b3a | roc native-status --write
#include "v8kernel/Kernel2008.h"
#include "v8kernel/KernelData.h"
#include "util/Profiling.h"

namespace RBX
{
	int Kernel::numKernels;

	// 005fb650 (not exact: KernelData / CodeProfiler sizes)
	Kernel::Kernel(IStage* upstream)
		: IStage(upstream, NULL),
		  inStepCode(false),
		  kernelData(new KernelData()),
		  profilingKernel(new Profiling::CodeProfiler("Kernel"))
	{
		++numKernels;
	}

	// 005faca0 (not exact: the donor ~KernelData is inline)
	Kernel::~Kernel()
	{
		--numKernels;
		delete kernelData;
	}

#ifdef NATIVE_KERNEL_STAGES_PENDING
	// 0077d800 (folded `mov eax, 7`); needs the 2008 StageType (generated v8kernel/IStage.h).
	IStage::StageType Kernel::getStageType()
	{
		return KERNEL_STAGE;
	}
#endif

	// 005faa20
	int Kernel::numBodies() const
	{
		return kernelData->bodies.size();
	}

	// 005faa30
	int Kernel::numPoints() const
	{
		return kernelData->points.size();
	}

	// 005faa40
	int Kernel::numConnectors() const
	{
		return kernelData->connectors.size();
	}
}
