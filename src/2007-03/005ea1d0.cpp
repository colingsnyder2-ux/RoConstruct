// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/IPipelined.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/IPipelined.h"

#include "v8kernel/Kernel.h"

namespace RBX {

// FUNCTION: WEBSERVICE 0x1010b9b0
IStage* IPipelined::getStage(IStage::StageType stageType) const
{
	IStage* stage = currentStage;

	while (stage->getStageType() != stageType) {
		stage = stage->getStageType() > stageType ? stage->getUpstream() : stage->getDownstream();
	}

	return stage;
}

// FUNCTION: WEBSERVICE 0x1010b9f0
void IPipelined::removeFromPipeline(IStage* stage)
{
	currentStage = 0;
}

// FUNCTION: WEBSERVICE 0x1010ba00
void IPipelined::removeFromStage(IStage* stage)
{
	currentStage = currentStage->getUpstream();
}

// FUNCTION: WEBSERVICE 0x1010ba10
Kernel* IPipelined::getKernel() const
{
	return static_cast<Kernel*>(getStage(IStage::KERNEL_STAGE));
}

// FUNCTION: WEBSERVICE 0x1010ba20
void IPipelined::removeFromKernel()
{
	currentStage = currentStage->getUpstream();
}

// FUNCTION: WEBSERVICE 0x101ae590 FOLDED
void IPipelined::putInPipeline(IStage* stage)
{
	currentStage = stage;
}

// FUNCTION: WEBSERVICE 0x101ae590 FOLDED
void IPipelined::putInStage(IStage* stage)
{
	currentStage = stage;
}

// FUNCTION: WEBSERVICE 0x101ae590 FOLDED
void IPipelined::putInKernel(Kernel* kernel)
{
	currentStage = kernel;
}

} // namespace RBX
