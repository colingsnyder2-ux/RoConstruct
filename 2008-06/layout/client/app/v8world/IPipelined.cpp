#include "v8kernel/IPipelined2008.h"
#include "v8kernel/Kernel2008.h"
namespace RBX {
IStage* IPipelined::getStage(IStage::StageType stageType) const
{
    IStage* stage = currentStage;
    while (stage->getStageType() != stageType) {
        stage = static_cast<int>(stage->getStageType()) > static_cast<int>(stageType) ? stage->getUpstream() : stage->getDownstream();
    }
    return stage;
}
void IPipelined::removeFromPipeline(IStage*) { currentStage = NULL; }
void IPipelined::putInKernel(Kernel* kernel) { currentStage = kernel; }
void IPipelined::removeFromStage(IStage*) { currentStage = currentStage->getUpstream(); }
Kernel* IPipelined::getKernel() const
{
    // INFERRED: original 00645850 pushes 7; donor IStage enum has an extra stage.
    return static_cast<Kernel*>(getStage(static_cast<IStage::StageType>(7)));
}
void IPipelined::removeFromKernel() { currentStage = currentStage->getUpstream(); }
}
