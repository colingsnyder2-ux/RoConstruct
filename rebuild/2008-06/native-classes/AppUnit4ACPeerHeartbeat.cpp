// 2008-06 native RBX::Network::Peer::onEvent(const RunService*, Heartbeat) 004add50 (inactive), the Peer Listener
// <RunService, Heartbeat> vtable 0082488c slot 0, declared by the read-only native-headers/Network/Peer2008.h.
// Verified by tests/record_native_app_unit4ac.py. Body (target bytes): tick = G3D::System::getTick() 005083d0 +
// event.step * 0.2f (0x3e4ccccd at 008249f8; /fp:fast folds the division); then rakPeer->Receive() (+0x140, slot 15)
// / DeallocatePacket (slot 16) until no packet is left or the tick passes; then for_eachChild(&checkDisconnect)
// (0045c470, checkDisconnect 004aaf50 declared in AppUnit4AC/PeerHeartbeat.h).
#include "Network/Peer2008.h"
#include "AppUnit4AC/PeerHeartbeat.h"
#include <G3D/System.h>

namespace RBX
{
	namespace Network
	{
		void Peer::onEvent(const RunService* source, Heartbeat event)
		{
			double tick = G3D::System::getTick() + event.step / 5.0;

			do
			{
				Packet* receivedPacket = rakPeer->Receive();
				if (receivedPacket)
					rakPeer->DeallocatePacket(receivedPacket);
				else
					break;
			}
			while (G3D::System::getTick() < tick);

			for_eachChild(&checkDisconnect);
		}
	}
}
