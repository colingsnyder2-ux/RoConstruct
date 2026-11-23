// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::AbuseReporter::add 0049c710 and Players::reportAbuse(Player*, std::string) 0049c7b0
// (inactive). Identity: Players.h records both addresses; 0049c7b0 is called by reportAbuse(shared_ptr<Instance>,
// std::string) 0049ca70 (NetworkPlayers.cpp) and calls 0049c710 with (&report, chatHistory +0x178) on abuseReporter
// (+0x174). Bodies: the openrbx 2007 Client/Network/Players.cpp shapes; flags and includes copied from NetworkPlayers.cpp.
#include <RakPeer.h>
#include <PluginInterface.h>
#include "Network/Client2008.h"
#include "Network/Server2008.h"
#include "Network/Players.h"
#include "Network/Player.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "BitStream.h"
#include "security/SecurityContext.h"
#include <algorithm>
#include <boost/bind.hpp>

namespace RBX
{
	namespace Network
	{
		// 0049c710: for_each over the chat history binding AbuseReport::addMessage (00498e40), then under requestSync
		// (do_lock 00594ce0 / do_unlock 00594d00) queue.push (deque push_back 0049bc40), then worker_thread::wake
		// 00595de0 on requestProcessor.
		void AbuseReporter::add(AbuseReport& r, const std::list<ChatMessage>& chatHistory)
		{
			std::for_each(chatHistory.begin(), chatHistory.end(), boost::bind(&AbuseReport::addMessage, boost::ref(r), _1));

			{
				boost::mutex::scoped_lock lock(_data->requestSync);
				_data->queue.push(r);
			}

			requestProcessor->wake();
		}

		// 0049c7b0: with an abuseReporter, "Submitting abuse report from %s" 00822aa4 (player name +0x114 or
		// "[[[anonymous]]]" 00822ac4), an AbuseReport (00499320 / 00499370) with the user ids (+0x1b4) and the comment,
		// then add 0049c710; otherwise "Sending abuse report to game server via Raknet" 00822a74, runtime_error
		// "Can't report abuse: Not in a networked game" 00822a48 without a peer (+0x1a8), and a BitStream (004a5090 /
		// 004a51a0) of ID 0x52, both user ids and the comment sent through peer vtable slot 0x34 (HIGH_PRIORITY,
		// RELIABLE, channel 2, UNASSIGNED_SYSTEM_ADDRESS 00937854, broadcast).
		void Players::reportAbuse(Player* player, std::string comment)
		{
			if (abuseReporter)
			{
				StandardOut::singleton()->print(MESSAGE_INFO, "Submitting abuse report from %s", player ? player->getName().c_str() : "[[[anonymous]]]");

				AbuseReport r;
				r.submitterID = localPlayer ? localPlayer->getUserID() : 0;
				r.allegedAbuserID = player ? player->getUserID() : 0;
				r.comment = comment;
				abuseReporter->add(r, chatHistory);
			}
			else
			{
				StandardOut::singleton()->print(MESSAGE_INFO, "Sending abuse report to game server via Raknet");

				if (!peer)
					throw std::runtime_error("Can't report abuse: Not in a networked game");

				RakNet::BitStream bitStream;
				bitStream << (unsigned char)0x52; // ID_REPORT_ABUSE (2008 numbering, FilePacketLogger 004aae00)
				bitStream << (localPlayer ? localPlayer->getUserID() : 0);
				bitStream << (player ? player->getUserID() : 0);
				bitStream << comment;

				peer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 2, UNASSIGNED_SYSTEM_ADDRESS, true);
			}
		}
	}
}
