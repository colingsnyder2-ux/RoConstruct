// Rebuild glue: class-name strings and statics rbxgs declares extern but never defines.
// Names are the 2008-06 Roblox.exe strings ("NetworkClient", "NetworkServer", "NetworkMarker",
// "NetworkReplicator", "Players", "Player", "Stats"); "NetworkPeer" is not in the exe (abstract class).
// RBX class names likewise (2008 spellings: SpecialShape is "SpecialMesh", DebrisService "Debris",
// StarterPackService "StarterPack", LegacyHopperService "Hopper", ArrowTool "Arrow", BoxSelectCommand
// "BoxSelect"); "IdManager" and "TimerService" are not in the exe and keep their rbxgs names.
#include "util/Log.h"

namespace RBX
{
	namespace Network
	{
		const char* const sPeer = "NetworkPeer";
		const char* const sMarker = "NetworkMarker";
		const char* const sReplicator = "NetworkReplicator";
	}

	namespace Stats
	{
	}


	const char* const sAccoutrement = "Accoutrement";
	const char* const sBackpack = "Backpack";
	const char* const sBackpackItem = "BackpackItem";
	const char* const sBodyColors = "BodyColors";
	const char* const sDataModel = "DataModel";
	char* sDebrisService = "Debris";
	const char* const sDebugSettings = "DebugSettings";
	const char* const sFallingDown = "FallingDown";
	const char* const sFlag = "Flag";
	const char* const sFlagStandService = "FlagStandService";
	const char* const sFlying = "Flying";
	const char* const sFreefall = "Freefall";
	const char* const sGameSettings = "GameSettings";
	const char* const sGettingUp = "GettingUp";
	const char* const sGlobalSettings = "GlobalSettings";
	const char* const sHat = "Hat";
	const char* const sHopperBin = "HopperBin";
	const char* const sJumping = "Jumping";
	const char* const sLegacyHopperService = "Hopper";
	const char* const sLocalBackpack = "LocalBackpack";
	const char* const sLocalBackpackItem = "LocalBackpackItem";
	const char* const sMouse = "Mouse";
	const char* const sNetworkSettings = "NetworkSettings";
	const char* const sRunService = "RunService";
	const char* const sRunning = "Running";
	const char* const sSeated = "Seated";
	const char* const sSelection = "Selection";
	const char* const sShirt = "Shirt";
	const char* const sShirtGraphic = "ShirtGraphic";
	const char* const sSkin = "Skin";
	const char* const sSpawnerService = "SpawnerService";
	const char* const sStarterPackService = "StarterPack";
	const char* const sTool = "Tool";
}
