#include <RakPeer.h>
#include <PluginInterface.h>
#include "Network/Players.h"
#include "Network/Player.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "BitStream.h"
#include <stdexcept>

namespace RBX
{
	namespace Network
	{
		void Players::chat(std::string message)
		{
			if (!localPlayer)
				throw std::runtime_error("No local Player to chat from");

			RakNet::BitStream bitStream;
			bitStream << (unsigned char)0x51; // ID_CHAT_ALL (2008 numbering: ID_DATA is 0x4e, ID_PHYSICS 0x50)

			// INFERRED: the target registers the guid (0049bba0) before reading it inline (+8 scope, +0xc index); the
			Player* player = localPlayer.get();
			player->registerGuid();
			Guid::Data data;
			player->getGuid().extract(data);

			bitStream << data.scope->toString();
			bitStream << data.index;
			bitStream << message;

			peer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 2, UNASSIGNED_SYSTEM_ADDRESS, true);

			ChatMessage event(message.c_str(), localPlayer);
			Notifier<Players, ChatMessage>::raise(event);
		}
	}
}

bool RBX::Network::Players::superSafeOn() const
{
    if (localPlayer)
        return Player::prop_SuperSafeChat.getValue(localPlayer.get());
    return false;
}
