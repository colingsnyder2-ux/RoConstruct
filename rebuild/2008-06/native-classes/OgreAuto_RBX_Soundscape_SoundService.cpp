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

namespace RBX {
namespace Soundscape {
SoundService::~SoundService()
{
}
}
}

namespace RBX {
namespace Soundscape {
SoundService::SoundService()
	: system(0),
	  fmod_version(0),
	  stockSounds(),
	  dopplerscale(1.0f),
	  distancefactor(10.0f),
	  rolloffscale(1.0f),
	  statsItem(),
	  ambientReverb(NoReverb),
	  nextGarbageCollectTime(G3D::System::getTick()),
	  loadedSounds(),
	  loaded3DSounds(),
	  mySoundDisabled(false)
{
	setName("Soundscape");
}
}
}

