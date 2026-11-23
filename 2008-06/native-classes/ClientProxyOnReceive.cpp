// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::Server::ClientProxy::OnReceive 004a2c20 (inactive; original unit Network/Server.cpp).
// Flags copied from NetworkClientServer2008Server.cpp (same original unit); its own file so that unit's inputs stay
// unchanged. Declared in Network/ClientProxy2008.h (PluginInterface slot 5 of the ClientProxy vtable 008233c4).
// Shape: openrbx Client/Network/Server.cpp Server::ClientProxy::OnReceive (ROBLOX 0x004bc520).
#include "Network/ClientProxy2008.h"
#include "Network/Player.h"
#include "Network/NetworkSettings.h"
#include "util/standardout.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "BitStream.h"
#include <G3D/format.h>
#include <stdexcept>

namespace RBX
{
	namespace Network
	{
		// 004a2c20 (registry placeholder func_004a2c20; thiscall on the PluginInterface subobject +0x2b74, ret 8):
		// SystemAddress != 004a9850 against remotePlayerId (+0x2d54) -> Replicator::OnReceive 004b8c20; data[0] == 0x4c
		// (ID_REQUEST_CHARACTER in the 2008 numbering, FilePacketLogger 004aae00): BitStream(data, length, false)
		// 004a5120, IgnoreBits(8) 004a5470, deserializeInstanceRef 004a8b60; NetworkSettings printInstances (+0x131)
		// "Received remotePlayer %s from %s" 0082359c (readableString(4) 005a8440, ToString 004a98b0);
		// remotePlayer (+0x2d68) = shared_from_dynamic_cast<Player> 004a2950; NULL -> runtime_error 00823584;
		// Player::loadCharacter(true) 004957a0; else runtime_error(G3D::format 00509b10 00823558); catch
		// "Replicator::ClientProxy::OnReceive packet %d: %s" 00823524 (MESSAGE_ERROR); returns RR_STOP_PROCESSING_AND_DEALLOCATE.
		PluginReceiveResult Server::ClientProxy::OnReceive(RakPeerInterface* peer, Packet* packet)
		{
			const SystemAddress& systemAddress = packet->systemAddress;
			if (systemAddress != remotePlayerId)
				return Replicator::OnReceive(peer, packet);

			switch (packet->data[0])
			{
			case 0x4c: // ID_REQUEST_CHARACTER (2008 numbering)
				try
				{
					RakNet::BitStream inBitstream(packet->data, packet->length, false);
					inBitstream.IgnoreBits(8);

					Instance* instance;
					Guid::Data id;
					if (deserializeInstanceRef(inBitstream, instance, id))
					{
						if (NetworkSettings::singleton().printInstances)
						{
							StandardOut::singleton()->print(MESSAGE_INFO, "Received remotePlayer %s from %s", this,
								id.readableString(4).c_str(), systemAddress.ToString());
						}

						remotePlayer = shared_from_dynamic_cast<Player>(instance);

						if (!remotePlayer)
							throw std::runtime_error("remotePlayer is NULL");

						remotePlayer->loadCharacter(true);
					}
					else
					{
						throw std::runtime_error(G3D::format("Couldn't resolve remotePlayer %s from %s",
							id.readableString(4).c_str(), systemAddress.ToString()));
					}
				}
				catch (std::exception& e)
				{
					StandardOut::singleton()->print(MESSAGE_ERROR, "Replicator::ClientProxy::OnReceive packet %d: %s",
						packet->data[0], e.what());
				}
				return RR_STOP_PROCESSING_AND_DEALLOCATE;

			default:
				return Replicator::OnReceive(peer, packet);
			}
		}
	}
}
