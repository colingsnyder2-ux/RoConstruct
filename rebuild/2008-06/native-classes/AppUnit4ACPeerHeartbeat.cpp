// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source /fp:fast
#include "Network/Peer2008.h"
#include "AppUnit4AC/PeerHeartbeat.h"
#include <G3D/System.h>

namespace RBX
{
	namespace Network
	{
		// 004add50
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
