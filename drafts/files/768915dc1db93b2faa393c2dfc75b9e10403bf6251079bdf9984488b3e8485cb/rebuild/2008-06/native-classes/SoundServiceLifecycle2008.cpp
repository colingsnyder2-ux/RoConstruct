// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include "util/Sound.h"
#include "util/RunStateOwner.h"
#include "v8datamodel/Stats.h"
namespace RBX { namespace Soundscape {
// 005bdcf0: provider lookup calls create<RunService> at 00452c80.
void SoundService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider) {
    Listener<RunService, Heartbeat>* listener = this;
    if (oldProvider) {
        if (RunService* rs = oldProvider->create<RunService>()) rs->Notifier<RunService, Heartbeat>::removeListener(listener);
    }
    if (statsItem) { statsItem->setParent(NULL); statsItem.reset(); }
    if (oldProvider) closeFmod();
    Listener<RunService, Heartbeat>& listenerRef = *this;
    if (newProvider) {
        if (RunService* rs = newProvider->create<RunService>()) rs->Notifier<RunService, Heartbeat>::addListener(&listenerRef);
        openFmod(); loadStockSounds();
        if (Stats::StatsService* stats = newProvider->create<Stats::StatsService>()) {
            statsItem = Creatable<Instance>::create<SoundServiceStatsItem>(this);
            statsItem->setParent(stats);
        }
    }
}
} }
