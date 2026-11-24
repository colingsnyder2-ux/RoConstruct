// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
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

    // 0064c850 (registry func_0064c850; only caller stepWorld 0064ca27 on the moveBodiesTest path): wakeAssemblies
    // 0064c6b0 over wakePending +0x100 (state 2), recursiveWakePending +0xe0 (1), sleepingChecking +0x140 (4) and
    // sleepingDeeply +0x160 (5), all with recurse depth 0, in that order.
    void SleepStage::sub_0064c850()
    {
        wakeAssemblies(wakePending, 0, Sim::WAKE_PENDING);
        wakeAssemblies(recursiveWakePending, 0, Sim::RECURSIVE_WAKE_PENDING);
        wakeAssemblies(sleepingChecking, 0, Sim::SLEEPING_CHECKING);
        wakeAssemblies(sleepingDeeply, 0, Sim::SLEEPING_DEEPLY);
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
