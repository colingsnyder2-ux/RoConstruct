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
