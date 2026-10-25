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

	const char* sAccoutrement = "Accoutrement";
	const char* sArrowTool = "Arrow";
	const char* sBackpack = "Backpack";
	const char* sBackpackItem = "BackpackItem";
	const char* sBodyColors = "BodyColors";
	const char* sBoxSelectCommand = "BoxSelect";
	const char* sControllerService = "ControllerService";
	const char* sDataModel = "DataModel";
	const char* sDebrisService = "Debris";
	const char* sDebugSettings = "DebugSettings";
	const char* sExplosion = "Explosion";
	const char* sFallingDown = "FallingDown";
	const char* sFlag = "Flag";
	const char* sFlagStand = "FlagStand";
	const char* sFlagStandService = "FlagStandService";
	const char* sFlying = "Flying";
	const char* sFreefall = "Freefall";
	const char* sGameSettings = "GameSettings";
	const char* sGettingUp = "GettingUp";
	const char* sGlobalSettings = "GlobalSettings";
	const char* sGroupDragTool = "GroupDragTool";
	const char* sHat = "Hat";
	const char* sHint = "Hint";
	const char* sHopperBin = "HopperBin";
	const char* sHumanoid = "Humanoid";
	const char* sIdManager = "IdManager";
	const char* sJumping = "Jumping";
	const char* sLegacyHopperService = "Hopper";
	const char* sLocalBackpack = "LocalBackpack";
	const char* sLocalBackpackItem = "LocalBackpackItem";
	const char* sMessage = "Message";
	const char* sMouse = "Mouse";
	const char* sNetworkSettings = "NetworkSettings";
	const char* sNewNullTool = "NewNullTool";
	const char* sPart = "Part";
	const char* sPartDragTool = "PartDragTool";
	const char* sRunService = "RunService";
	const char* sRunning = "Running";
	const char* sSeat = "Seat";
	const char* sSeated = "Seated";
	const char* sSelection = "Selection";
	const char* sShirt = "Shirt";
	const char* sShirtGraphic = "ShirtGraphic";
	const char* sSkin = "Skin";
	const char* sSky = "Sky";
	const char* sSpawnLocation = "SpawnLocation";
	const char* sSpawnerService = "SpawnerService";
	const char* sSpecialShape = "SpecialMesh";
	const char* sStarterPackService = "StarterPack";
	const char* sTexture = "Texture";
	const char* sTimerService = "TimerService";
	const char* sTool = "Tool";
	const char* sToolMouseCommand = "ToolMouseCommand";
	const char* sVisit = "Visit";
	const char* sWorkspace = "Workspace";
}
