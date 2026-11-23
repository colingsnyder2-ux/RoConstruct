// =============================================================================
// IPipelined.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8world/IPipelined.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8kernel/IPipelined2008.h"
#include "v8kernel/Kernel2008.h"

namespace RBX
{
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
