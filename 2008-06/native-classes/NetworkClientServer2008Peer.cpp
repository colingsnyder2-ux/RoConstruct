// 2008-06 native RBX::Network::Peer (inactive); evidence in native-headers/Network/Peer2008.h.
// Verified by tests/record_native_network_client_server2008.py. Original bodies: constructor 004b4640, destructor
// 004ac830, deleting destructor 004ad7a0, classDescriptor 0049ea10 (atexit 007fba70).
#include "Network/Peer2008.h"

namespace RBX
{
	namespace Network
	{
		const char sPeer[] = "NetworkPeer"; // 008244d8 (classDescriptor 0049ea10)

		Peer::Peer()
			: profilePacketsThread(new Profiling::CodeProfiler("Packets Thread"))
		{
			rakPeer.reset(new ProfiledRakPeer(profilePacketsThread.get()));
			rakPeer->AttachPlugin(this);
		}

		Peer::~Peer()
		{
			rakPeer->DetachPlugin(this);
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::scoped_ptr<PacketLogger>;
template class boost::scoped_ptr<RBX::Profiling::CodeProfiler>;
