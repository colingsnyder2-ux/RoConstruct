// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/util/Sound.h"

namespace RBX {
namespace Soundscape {
void SoundService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	Listener<RunService, Heartbeat>* listener = this;
	if (oldProvider)
	{
		if (RunService* runService = ServiceProvider::find<RunService>(oldProvider))
			runService->Notifier<RunService, Heartbeat>::removeListener(listener);
	}
	if (statsItem)
	{
		statsItem->setParent(NULL);
		statsItem.reset();
	}
	if (oldProvider)
		closeFmod();
	Listener<RunService, Heartbeat>& listenerRef = *this;
	if (newProvider)
	{
		if (RunService* runService = ServiceProvider::find<RunService>(newProvider))
			runService->Notifier<RunService, Heartbeat>::addListener(&listenerRef);
		openFmod();
		loadStockSounds();
		if (Stats::StatsService* stats = ServiceProvider::create<Stats::StatsService>(newProvider))
		{
			statsItem = Creatable<Instance>::create<SoundServiceStatsItem>(this);
			statsItem->setParent(stats);
		}
	}
}
}
}
