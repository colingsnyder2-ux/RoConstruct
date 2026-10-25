// Rebuild glue: class-name strings and statics rbxgs declares extern but never defines.
// Names are the 2008-06 Roblox.exe strings ("NetworkClient", "NetworkServer", "NetworkMarker",
// "NetworkReplicator", "Players", "Player", "Stats"); "NetworkPeer" is not in the exe (abstract class).
#include "util/Log.h"

namespace RBX
{
	namespace Network
	{
		const char* sClient = "NetworkClient";
		const char* sServer = "NetworkServer";
		const char* sPeer = "NetworkPeer";
		const char* sMarker = "NetworkMarker";
		const char* sReplicator = "NetworkReplicator";
		const char* sPlayers = "Players";
		const char* sPlayer = "Player";
	}

	namespace Stats
	{
		const char* sStats = "Stats";
	}

	ILogProvider* Log::provider = NULL;
}
