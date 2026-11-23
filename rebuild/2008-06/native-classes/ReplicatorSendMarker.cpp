// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::Replicator::sendMarker 004b9210 (inactive; original unit Network/Replicator.cpp).
// Flags copied from NetworkReplicator2008Items.cpp (same original unit). Shape: donor tools/rbxgs
// Client/Network/Replicator.cpp and openrbx Client/Network/Replicator.cpp (ROBLOX 0x004d2d30) Replicator::sendMarker.
// Its own unit so ReplicatorMarker.cpp (which emits the Marker COMDAT bodies through newMarker's address) and
// NetworkReplicator2008Items.cpp keep their inputs unchanged.
#include "Network/Replicator2008.h"
#include "Network/ReplicatorMarker.h"
#include "Network/NetworkSettings.h"
#include "util/standardout.h"
#include "RakPeerInterface.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "BitStream.h"

namespace RBX
{
	namespace Network
	{
		// 004b9210: newMarker 004b9190; BitStream 004a5090; << (unsigned char)0x4f (ID_REQUEST_MARKER in the 2008
		// numbering, FilePacketLogger 004aae00) 004a6350; << (int)id 004a61a0; NetworkSettings::singleton() 0049e890
		// printInstances (+0x131) -> StandardOut::singleton() 00569620 print 005693a0 (MESSAGE_INFO, 008252a0,
		// remotePlayerId.ToString() 004a98b0); incomingMarkers (+0x2cdc) push 004b0c10; peer (+0x2d50) slot 0x34
		// Send(&bitStream, HIGH_PRIORITY, RELIABLE, 0, remotePlayerId, false).
		boost::shared_ptr<Reflection::DescribedBase> Replicator::sendMarker()
		{
			boost::shared_ptr<Marker> marker = Marker::newMarker();

			// INFERRED: the donor Marker::id() is `reinterpret_cast<long>(this)` (the target pushes the Marker pointer);
			// native-headers/Network/ReplicatorMarker.h does not declare id() (proposal), so the cast is spelled here.
			long id = reinterpret_cast<long>(marker.get());

			RakNet::BitStream bitStream;
			bitStream << (unsigned char)0x4f;
			bitStream << (int)id;

			if (NetworkSettings::singleton().printInstances)
			{
				StandardOut::singleton()->print(MESSAGE_INFO, "Replicator: Requesting Marker %d of %s", (int)id, remotePlayerId.ToString());
			}

			incomingMarkers.push(marker);
			peer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 0, remotePlayerId, false);

			return marker;
		}
	}
}
