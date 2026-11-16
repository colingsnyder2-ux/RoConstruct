#pragma once
// 2008-06 native RBX::Network::Server::ClientProxy (inactive). A new, non-colliding header (no donor ClientProxy.h).
// Shape after the donor tools/rbxgs Client/Network/Server.cpp; base and evidence below are read from the 2008-06
// binary (tests/record_native_client_proxy.py and tests/record_native_network_replicator2008.py).
//
// Members declared (Replicator2008.h now reaches sizeof 0x2d68). Virtual overrides (slots 16, 17, 19, 21) are not
// declared: Replicator2008.h has no slots 16-21 yet. With the current declarations MSVC names the vtable at +0x2b74
// ??_7ClientProxy@...@6B@ and the one at +0 ...@6B?$GuidItem@...@ (unverified lead: the original's new Replicator
// virtuals would give the primary the bare name), while the registry (rtti-primary-vtable) binds the bare name to the primary
// 00823474; the constructor 004a1ed0 and destructor 004a18c0 bodies are byte-identical apart from that reference.
//   RTTI       vtable 00823474 .?AVClientProxy@Server@Network@RBX@@ (24 bases): Replicator at 0, PluginInterface at
//              mdisp 0x2b74 (vtable 008233c4); nested in Server (Server2008.h forward-declares it).
//   size       0x2d78: Creatable<Instance>::create<ClientProxy> 004a21c0 mallocs 0x2d78.
//   ctor       004a1ed0 (SystemAddress, Server*; ret 0xc): Replicator(address, server->peerInterface() 00609a30)
//              004b9bd0, then +0x2d68 boost::shared_ptr<Player> remotePlayer (zeroed) and +0x2d70 Server* server.
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
		class Player;

		class Server::ClientProxy : public Replicator
		{
		private:
			boost::shared_ptr<Player> remotePlayer;                                 // +0x2d68 (constructor zeroes it; slot 17 004a1a30 returns it)
			Server* server;                                                         // +0x2d70 (slot 16 004a3290 reads its +0x164 name set)

		public:
			ClientProxy(SystemAddress address, Server* server);                    // 004a1ed0 (body in NetworkClientServer2008Server.cpp)
			virtual ~ClientProxy();                                                 // 004a18c0 (body in NetworkClientServer2008Server.cpp)
			// 004a2ac0 (donor Server::ClientProxy::sendTop; open). Body: BitStream; << (unsigned char)0x4b 004a6350;
			// << Guid::getLocalScope() 005a82e0 name string 004a6560; serializeId 004a8ae0 (declared in IdSerializer.h,
			// body blocked on util/GuidItem.h) for each replicationContainers entry; writeProperties 004b7f20 (declared in
			// Replicator2008.h) on replicationContainers[0]; peer->Send(&bs, 2, 3, 0, remotePlayerId, false) (slot 0x34).
			// StringSender::serializeString 004a83e0 and IdSerializer::serializeRef 004a8b90 have landed (serializeValue
			// 004b6890 is exact). Remaining blockers: util/Guid.h (core) does not declare static const Name&
			// Guid::getLocalScope() (005a82e0), and the serializeId 004a8ae0 body waits on the util/GuidItem.h (core)
			// GuidItem<Instance> guid accessor.
			// Server::OnReceive 004a4dc0 calls it non-virtually on the create<ClientProxy> 004a21c0 result.
			void sendTop();
		};
	}
}
