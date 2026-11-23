// =============================================================================
// sleepstage.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8world/sleepstage.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8world/SleepStage2008.h"

namespace RBX
{
    void SleepStage::stepWorld(int worldStepId, int newUiStepId, bool newThrottling, bool moveBodiesTest)
    {
        throttling = newThrottling;
        uiStepId = newUiStepId;
        if (moveBodiesTest)
            sub_0064c850();
        else
            sub_0064c8a0(worldStepId);
        getDownstream()->stepWorld(worldStepId, uiStepId, throttling, moveBodiesTest);
    }

    int SleepStage::getMetric(MetricType metricType)
    {
        switch (metricType)
        {
        case NUM_CONTACTSTAGE_CONTACTS: return numContactsInStage;
        case NUM_STEPPING_CONTACTS: return steppingContacts.size();
        case NUM_TOUCHING_CONTACTS: return numContactsInKernel;
        default: return static_cast<IWorldStage*>(getDownstream())->getMetric(metricType);
        }
    }
}

namespace RBX
{

}
