#pragma once
// >>> native-status (generated) -- do not edit >>>
// Server2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 5d89f949 | roc native-status --write
// 2008-06 native RBX::Network::Server (inactive). Shape after the donor tools/rbxgs Client/Network/Server.h; every
// base, field and virtual below is read from the 2008-06 binary:
//   RTTI       vtable 0082367c .?AVServer@Network@RBX@@ (26 bases) -> DescribedCreatable<Server, Peer, sServer> (name
//              mangled $1?sServer@23@3PADA, a non-const char array in .data at 00939724 holding "NetworkServer":
//              classDescriptor 0049eba0, constructor setName) and the empty Service (mdisp 0x144). No Listener base.
//   size       0x184: Creatable<Instance>::create<Server> 0049a450 allocates 0x184 (malloc) and calls the constructor
//              004a4b30 (DescribedCreatable<Server> 004a42c0 -> FactoryProduct<Server> 004a15f0 -> Peer 004b4640).
//   fields     constructor 004a4b30 / destructor 004a3540, in declaration order:
//              +0x144 int outgoingPort (constructor 0; ClientProxy start path 004a1e33 stores the movzx'd port),
//              +0x148 shared_ptr<Players> players (onServiceProvider 004a4100: players->setConnection 00496510,
//              reset 00456e80),
//              +0x150 boost::signals::scoped_connection (0x14 bytes; constructor zeroes +0x154/+0x158 and the bytes
//              +0x15c/+0x160; destructor ~scoped_connection 005954b0; onServiceProvider assigns it 00595540),
//              +0x164 std::set<std::string> (0x20 bytes: ctor 004d8680, destructor 004a3470, _Erase 004a27a0 destroys
//              a std::string at node +0x0c; looked up by ClientProxy 004a3290 through 004a2fa0; name provisional).
//              The constructor then calls setName(sServer), rakPeer->SetMaximumIncomingConnections(64) (slot 4) and
//              rakPeer->SetIncomingPassword(API::version.c_str(), API::version.size()) (slot 7; std::string 00970b88).
//   vtable     slot 2 askAddChild 004a3640 (dynamic_cast<const ClientProxy*>), slot 12 onServiceProvider 004a4100,
//              slot 14 write 00416690 (ICF-shared `return NULL`), PluginInterface slot 5 OnReceive 004a4dc0 (all
//              declared only); destructor 004a3540.
//   statics    serverIsPresent 004a40d0: ServiceProvider::find<Server>(findServiceProvider(context)) != NULL
//              (findServiceProvider 004898d0, ServiceProvider::find<Server> 004a3e40).
#include "Network/Peer2008.h"
#include "v8tree/Service.h"
#include <boost/signals/connection.hpp>
#include <boost/shared_ptr.hpp>
#include <set>
#include <string>

class XmlElement;

namespace RBX
{
	namespace Network
	{
		class Players;

		extern char sServer[];

		class Server : public DescribedCreatable<Server, Peer, sServer>,
					   public Service
		{
			friend struct ::NativeNetworkClientServer2008Layout; // NetworkClientServer2008Layout.cpp offset asserts

		public:
			class ClientProxy;

		private:
			int outgoingPort;                                                       // +0x144
			boost::shared_ptr<Players> players;                                     // +0x148
			boost::signals::scoped_connection connection;                           // +0x150 (name provisional)
			std::set<std::string> names;                                            // +0x164 (name provisional)

		public:
			Server();                                                               // 004a4b30
			virtual ~Server();                                                      // 004a3540
			virtual XmlElement* write();                                            // 00416690 (ICF)
			virtual PluginReceiveResult OnReceive(RakPeerInterface* peer, Packet* packet); // 004a4dc0

		protected:
			virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 004a4100
			virtual bool askAddChild(const Instance* instance) const;               // 004a3640

		public:
			// 004a40d0 (evidence name ?serverIsPresent@Server@Network@RBX@@SA_NPBVInstance@3@_N@Z; the bool is not read)
			static bool serverIsPresent(const Instance* context, bool testInDatamodel);
		};
	}
}
