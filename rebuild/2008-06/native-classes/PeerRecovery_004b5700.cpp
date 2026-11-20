// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::Peer::onServiceProvider 004b5700 and Peer::updateNetworkSimulator 004ae950 (inactive). The Peer unit (NetworkClientServer2008Peer.cpp)
// holds the constructor/destructor; this body is kept in its own unit. Declaration in native-headers/Network/Peer2008.h.
// Statement order follows the server-verified mined analog src/2008-06/004b5700.cpp; callees read from the target:
// ServiceProvider::find<StatsService>() 00457b60, Instance::findFirstChildByName 00557950, shared_from_polymorphic_downcast
// 004c7530 (the caller converts to enable_shared_from_this<Instance> +0xe4 with a NULL test), Instance::setParent 0055a8f0,
// ServiceProvider::find<RunService>() 00452c80, Notifier<RunService, Heartbeat>::removeListener 005e5a80 / addListener
// 004218a0 (identical-code folded), Creatable<Instance>::create<Stats::Item> 004b4e50, "Network" 00824384,
// Stats::Item::createBoundChildItem(const Profiler&) 005ca240 with profilePacketsThread (+0x13c).
#include "Network/Peer2008.h"
#include "stats/Stats.h"
#include "util/Profiling.h"
#include "v8tree/Service.h"
#include "Network/NetworkSettings.h"

namespace RBX
{
	namespace Network
	{
		// 004b5700
		void Peer::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
		{
			if (oldProvider)
			{
				if (Stats::StatsService* stats = oldProvider->find<Stats::StatsService>())
				{
					boost::shared_ptr<Instance> network = shared_from_polymorphic_downcast<Instance>(stats->findFirstChildByName("Network"));
					if (network)
						network->setParent(NULL);
				}
			}

			Listener<RunService, Heartbeat>* listener = this;
			if (oldProvider)
			{
				if (RunService* runService = oldProvider->find<RunService>())
					runService->Notifier<RunService, Heartbeat>::removeListener(listener);
			}

			Listener<RunService, Heartbeat>* newListener = this;
			if (newProvider)
			{
				if (RunService* runService = newProvider->find<RunService>())
					runService->Notifier<RunService, Heartbeat>::addListener(newListener);

				if (Stats::StatsService* stats = newProvider->find<Stats::StatsService>())
				{
					boost::shared_ptr<Stats::Item> item = Creatable<Instance>::create<Stats::Item>();
					item->setName("Network");
					item->setParent(stats);
					item->createBoundChildItem(*profilePacketsThread);
				}
			}
		}
	}
}

namespace RBX
{
	namespace Network
	{
		// 004ae950 (donor Replicator.cpp Peer::updateNetworkSimulator; NetworkSettings::singleton 0049e890, rakPeer
		// slot 0x100 ApplyNetworkSimulator(double, unsigned short, unsigned short))
		void Peer::updateNetworkSimulator()
		{
			rakPeer->ApplyNetworkSimulator(
				NetworkSettings::singleton().maxSendBPS,
				NetworkSettings::singleton().minExtraPing,
				NetworkSettings::singleton().extraPingVariance
			);
		}
	}
}
