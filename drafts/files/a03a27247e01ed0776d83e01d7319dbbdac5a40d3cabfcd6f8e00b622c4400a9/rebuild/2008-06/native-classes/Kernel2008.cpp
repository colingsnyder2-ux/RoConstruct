// 2008-06 native RBX::Kernel (inactive); evidence in native-headers/v8kernel/Kernel2008.h.
// Verified by tests/record_native_kernel_stages.py. Rows: the scalar deleting destructor 005fb0c0 (vtable 0084105c is
// emitted here), numBodies 005faa20, numPoints 005faa30, numConnectors 005faa40. The constructor 005fb650 and the
// destructor 005faca0 are built but not exact: the donor KernelData (0x30, inline destructor) and CodeProfiler
// (0x20040) differ from the 2008 ones (0x3c with an out-of-line destructor 005fa970; 0xc048), see PROPOSALS.
// stepWorld 005fb3f0 and the insert / remove rows are not built (Body / Point / Connector).
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

	// 0077d800 (folded `mov eax, 7`); KERNEL_STAGE is 7 in 2008.
	IStage::StageType Kernel::getStageType()
	{
		return (IStage::StageType)7;
	}

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
