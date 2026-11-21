// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::Players::chat 0049cb30 (inactive). The Players unit is NetworkPlayers.cpp (its funcChat
// BoundFuncDesc 009704d8 binds this member); this body is kept in its own unit. Declaration in
// native-headers/Network/Players.h. Shape after the donor tools/rbxgs Client/Network/Players.cpp Players::chat; callees
// read from the target: runtime_error 00409d50 ("No local Player to chat from" 00822ad4), BitStream 004a5090,
// operator<<(uchar) 004a6350 with 0x51 (2008 ID_CHAT_ALL), GuidItem<Instance>::registerGuid 0049bba0, operator<<(const
// std::string&) 004a6560, operator<<(int) 004a61a0, peer slot 0x34 Send(HIGH_PRIORITY, RELIABLE, channel 2,
// UNASSIGNED_SYSTEM_ADDRESS 00937854, broadcast), ChatMessage(const char*, shared_ptr<Player>) 00496c20, copy 00496480,
// Notifier<Players, ChatMessage>::raise 00496d90, ~ChatMessage 004963c0.
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
		// 0049cb30
		void Players::chat(std::string message)
		{
			if (!localPlayer)
				throw std::runtime_error("No local Player to chat from");

			RakNet::BitStream bitStream;
			bitStream << (unsigned char)0x51; // ID_CHAT_ALL (2008 numbering: ID_DATA is 0x4e, ID_PHYSICS 0x50)

			// INFERRED: the target registers the guid (0049bba0) before reading it inline (+8 scope, +0xc index); the
			// donor reads it through getGuid().extract().
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
