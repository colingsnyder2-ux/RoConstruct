// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Native 2008-06 IPipelined; declarations and layout evidence in IPipelined2008.h.
#include "v8kernel/IPipelined2008.h"
#include "v8kernel/Kernel2008.h"
namespace RBX {
// 006457e0
// Signed comparison is evidenced by jle at 00645801.
IStage* IPipelined::getStage(IStage::StageType stageType) const
{
    IStage* stage = currentStage;
    while (stage->getStageType() != stageType) {
        stage = static_cast<int>(stage->getStageType()) > static_cast<int>(stageType) ? stage->getUpstream() : stage->getDownstream();
    }
    return stage;
}
// 00645820
void IPipelined::removeFromPipeline(IStage*) { currentStage = NULL; }
// 00645830
void IPipelined::putInKernel(Kernel* kernel) { currentStage = kernel; }
// 00645840
void IPipelined::removeFromStage(IStage*) { currentStage = currentStage->getUpstream(); }
// 00645850
Kernel* IPipelined::getKernel() const
{
    // INFERRED: original 00645850 pushes 7; donor IStage enum has an extra stage.
    return static_cast<Kernel*>(getStage(static_cast<IStage::StageType>(7)));
}
// 00645860
void IPipelined::removeFromKernel() { currentStage = currentStage->getUpstream(); }
}



