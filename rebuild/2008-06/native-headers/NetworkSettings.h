#pragma once
// >>> native-status (generated) -- do not edit >>>
// NetworkSettings | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 9c152d5f | roc native-status --write
#include "v8datamodel/GlobalSettings.h"

namespace RBX
{
	extern char sNetworkSettings[];

	class NetworkSettings : public GlobalSettingsItem<NetworkSettings, sNetworkSettings>
	{
	public:
		bool clientPhysics;
		float clientPhysicsSpeed;
		float clientPhysicsLifetime;
		bool printPhysicsErrors;
		bool printInstances;
		bool printProperties;
		bool printPacketBuffer;
		bool logPackets;
		int maxDataModelSendBuffer;
		float dataPacketSize;
		float sendRate;
		int maxSendBPS;
		int minExtraPing;
		int extraPingVariance;

	public:
		NetworkSettings();
	};
}
