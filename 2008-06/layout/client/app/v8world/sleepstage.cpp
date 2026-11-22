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
