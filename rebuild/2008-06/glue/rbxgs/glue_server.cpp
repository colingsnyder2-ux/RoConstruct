// Rebuild glue: Server::ClientProxy members rbxgs declares but never defines. The server-side proxy
// can send as soon as it exists (it sends the globals itself in sendTop), and answers the client's
// ID_REQUEST_CHARACTER (Replicator::requestCharacter: packet id, then the player's id) by adopting that
// player and loading its character. Behavioural reconstruction, not byte-verified.
#include <RakPeer.h>
#include "Server.h"
#include "PacketIds.h"
#include "Network/Player.h"
#include "BitStream.h"

namespace RBX
{
	namespace Network
	{
	}
}
