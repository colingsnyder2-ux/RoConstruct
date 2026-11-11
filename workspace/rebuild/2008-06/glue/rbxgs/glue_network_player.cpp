// Rebuild glue: Network::Player statics and overrides rbxgs declares but never defines. Names are the
// 2008-06 Roblox.exe strings ("Data", "CharacterAppearance", "userId", "Under13", "SuperSafeChat",
// "Chatted", "message", "recipient"). Behavioural reconstruction, not byte-verified.
#include "Network/Player.h"

namespace RBX
{
	namespace Network
	{

		// a player holds its backpack, gui and other per-player instances
		// players are session state: they are never written to a place file
	}
}
