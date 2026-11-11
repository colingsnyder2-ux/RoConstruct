#pragma once
// >>> native-status (generated) -- do not edit >>>
// ClientProxy2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src a031e779 | roc native-status --write
// 2008-06 native RBX::Network::Server::ClientProxy (inactive). A new, non-colliding header (no donor ClientProxy.h).
// Shape after the donor tools/rbxgs Client/Network/Server.cpp; base and evidence below are read from the 2008-06
// binary (tests/record_native_client_proxy.py and tests/record_native_network_replicator2008.py).
//
// PARTIAL DECLARATION: the base is complete, the members are not declared because their offsets follow the
// Replicator size (0x2d68), which native-headers/Network/Replicator2008.h does not reach yet. Only code that does not
// depend on the ClientProxy size or members may be built from it (shared_count<ClientProxy*>,
// dynamic_cast<const ClientProxy*>).
//   RTTI       vtable 00823474 .?AVClientProxy@Server@Network@RBX@@ (24 bases): Replicator at 0, PluginInterface at
//              mdisp 0x2b74 (vtable 008233c4); nested in Server (Server2008.h forward-declares it).
//   size       0x2d78: Creatable<Instance>::create<ClientProxy> 004a21c0 mallocs 0x2d78.
//   ctor       004a1ed0 (SystemAddress, Server*; ret 0xc): Replicator(address, server->peerInterface() 00609a30)
//              004b9bd0, then (pending, not declared) +0x2d68 boost::shared_ptr<Player> remotePlayer and +0x2d70
//              Server* server.
//   dtor       004a18c0 -> ~Replicator 004b96b0.
//   vtable     16 004a3290, 17 findTargetPlayer 004a1a30, 19 onSentMarker 004a1570, 21 00565950; PluginInterface
//              slot 5 OnReceive 004a2c20 (not declared here).
// Server2008.h first: its RakPeer.h pulls winsock2 before the windows.h that Instance.h reaches.
#include "Network/Server2008.h"
#include "Network/Replicator2008.h"

namespace RBX
{
	namespace Network
	{
		class Server::ClientProxy : public Replicator
		{
			// +0x2d68 remotePlayer, +0x2d70 server: pending (see the header comment).
		public:
			ClientProxy(SystemAddress address, Server* server);                    // 004a1ed0 (open)
			virtual ~ClientProxy();                                                 // 004a18c0 (open)
		};
	}
}
