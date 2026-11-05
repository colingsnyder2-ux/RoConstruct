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
		bool Server::ClientProxy::canSendItems()
		{
			return true;
		}

		PluginReceiveResult Server::ClientProxy::OnReceive(RakPeerInterface* peer, Packet* packet)
		{
			PluginReceiveResult result = Replicator::OnReceive(peer, packet);
			if (result != RR_CONTINUE_PROCESSING || packet->systemAddress != remotePlayerId || packet->data[0] != ID_REQUEST_CHARACTER)
				return result;

			RakNet::BitStream bitStream(packet->data, packet->length, false);
			unsigned char id;
			bitStream >> id;
			Instance* instance = NULL;
			if (deserializeInstanceRef(bitStream, instance))
				if (Player* player = dynamic_cast<Player*>(instance))
				{
					remotePlayer = shared_from(player);
					player->loadCharacter();
				}
			return RR_STOP_PROCESSING_AND_DEALLOCATE;
		}
	}
}
