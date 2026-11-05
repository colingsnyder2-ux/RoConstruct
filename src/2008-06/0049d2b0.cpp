// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-net-dll roc_unit_6c49d58814f5c5bd.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("Network/Players.h", "roc_unit_7c451a3daa7e6ece.cpp")
#pragma include_alias("Replicator.h", "roc_unit_4d84ac61494c2cdb.cpp")
#include <RakPeer.h>
#include "v8datamodel/Stats.h"
#include "Server.h"
#include "PacketIds.h"
#include "util/standardout.h"
namespace RBX { namespace Network {
PluginReceiveResult Server::OnReceive(RakPeerInterface* peer, Packet* packet)
		{
			PluginReceiveResult result = PluginInterface::OnReceive(peer, packet);
			if (result != RR_CONTINUE_PROCESSING)
				return result;

			Server* owner = reinterpret_cast<Server*>(reinterpret_cast<char*>(static_cast<PluginInterface*>(this)) - 0x130);

			if (packet->data[0] == ID_NEW_INCOMING_CONNECTION)
			{
				try
				{
					StandardOut::singleton()->print(MESSAGE_INFO, "New connection from %s\n", packet->systemAddress.ToString());

					boost::shared_ptr<ClientProxy> proxy = Creatable::create<ClientProxy>(packet->systemAddress, owner);
					proxy->setParent(owner);
					proxy->sendTop();

					event_IncommingConnection.fire((owner ? reinterpret_cast<Reflection::SignalSource*>(reinterpret_cast<char*>(owner) + 0x14) : NULL), packet->systemAddress.ToString(), proxy);
				}
				catch (std::exception& e)
				{
					StandardOut::singleton()->print(MESSAGE_ERROR, "Server::OnReceive packet %d: %s", packet->data[0], e.what());
				}
			}

			return RR_CONTINUE_PROCESSING;
		}

		
}}
