// 2008-06 native Peer::askAddChild / Server::askAddChild (inactive): the two dynamic_cast checks that need the
// native 2008 Replicator / Server::ClientProxy type (their RTTI type descriptors 00938db4 / 009398dc). Peer and
// Server are declared in native-headers/Network/{Peer,Server}2008.h (record_native_network_client_server2008.py,
// which leaves these two bodies open); the definitions live here because they need Replicator2008.h /
// ClientProxy2008.h. Verified by tests/record_native_network_replicator2008.py.
#include "Network/ClientProxy2008.h"

namespace RBX
{
	namespace Network
	{
		bool Peer::askAddChild(const Instance* instance) const          // 0049ee20
		{
			return dynamic_cast<const Replicator*>(instance) != NULL;
		}

		bool Server::askAddChild(const Instance* instance) const        // 004a3640
		{
			return dynamic_cast<const ClientProxy*>(instance) != NULL;
		}
	}
}
