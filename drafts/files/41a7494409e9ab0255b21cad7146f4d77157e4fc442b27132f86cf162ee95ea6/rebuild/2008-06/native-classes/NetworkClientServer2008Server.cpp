// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::Server (inactive); evidence in native-headers/Network/Server2008.h.
// Verified by tests/record_native_network_client_server2008.py. Original bodies: constructor 004a4b30,
// DescribedCreatable<Server> 004a42c0, FactoryProduct<Server> 004a15f0 / ~FactoryProduct 004a1580, destructor
// 004a3540, classDescriptor 0049eba0.
// >>> native-status (generated) -- do not edit >>>
// NetworkClientServer2008Server | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/1 mapped addresses byte-exact | 0 unproved | no mapped strings | by auto
// <<< native-status | src 308c979a | roc native-status --write
#include "Network/Server2008.h"
#include "Network/ClientProxy2008.h"
#include "Network/Players.h"
#include "Network/API.h"
#include "script/Script.h"
#include "util/standardout.h"
#include "MessageIdentifiers.h"
#include <boost/bind.hpp>

namespace RBX
{
	// Template members the shared headers only declare (same definitions as TimerService.cpp / ClickDetector.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	namespace Network
	{
		char sServer[] = "NetworkServer"; // 00939724 (classDescriptor 0049eba0, constructor setName)

		Server::Server()
			: outgoingPort(0)
		{
			setName(sServer);
			rakPeer->SetMaximumIncomingConnections(64);
			rakPeer->SetIncomingPassword(API::version.c_str(), (int)API::version.size());
		}

		bool Server::serverIsPresent(const Instance* context, bool testInDatamodel)
		{
			return ServiceProvider::find<Server>(ServiceProvider::findServiceProvider(context)) != NULL;
		}

		Server::~Server()
		{
		}

		// 004a31d0 (name provisional; see Server2008.h)
		void Server::registerScript(boost::shared_ptr<Instance> instance)
		{
			if (Script* script = dynamic_cast<Script*>(instance.get()))
			{
				if (script->getScriptId().isNull())
					names.insert(script->getEmbeddedCode());
				else
					names.insert(script->getScriptId().toString());
			}
		}

		// 004a4100 (donor Server.cpp onServiceProvider; 2008 adds the script-name bookkeeping through registerScript
		// 004a31d0: visitDescendents 004a27e0 and event_descendentAdded.connect 004a3340, group 10)
		void Server::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
		{
			if (oldProvider)
			{
				players->setConnection(NULL);

				if (rakPeer->IsActive())
					rakPeer->Shutdown(1000);

				removeAllChildren();

				players.reset();

				connection.disconnect();
			}

			Peer::onServiceProvider(oldProvider, newProvider);

			if (newProvider)
			{
				players = shared_from(newProvider->create<Players>());

				players->setConnection(peerInterface());

				newProvider->visitDescendents(boost::bind(&Server::registerScript, this, _1));
				connection = Instance::event_descendentAdded.connect(const_cast<ServiceProvider*>(newProvider), boost::bind(&Server::registerScript, this, _1), 10);
			}
		}

		// 004a4dc0 (donor Server.cpp OnReceive; strings 00823bcc "New connection from %s\n", "Server::OnReceive packet
		// %d: %s"; create<ClientProxy> 004a21c0, setParent 0055a8f0, sendTop 004a2ac0, fire 0049d2b0 on 00970ebc)
		PluginReceiveResult Server::OnReceive(RakPeerInterface* peer, Packet* packet)
		{
			PluginReceiveResult result = PluginInterface::OnReceive(peer, packet);
			if (result != RR_CONTINUE_PROCESSING)
				return result;

			if (packet->data[0] == ID_NEW_INCOMING_CONNECTION)
			{
				try
				{
					StandardOut::singleton()->print(MESSAGE_INFO, "New connection from %s\n", packet->systemAddress.ToString());

					boost::shared_ptr<ClientProxy> proxy = Creatable<Instance>::create<ClientProxy>(packet->systemAddress, this);
					proxy->setParent(this);
					proxy->sendTop();

					event_IncommingConnection.fire(this, packet->systemAddress.ToString(), proxy);
				}
				catch (std::exception& e)
				{
					StandardOut::singleton()->print(MESSAGE_ERROR, "Server::OnReceive packet %d: %s", packet->data[0], e.what());
				}
			}

			return RR_CONTINUE_PROCESSING;
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::scoped_ptr<RakPeer>;
template class std::_Tree<std::_Tset_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,0> >;
template class std::allocator<std::_Tree_nod<std::_Tset_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,0> >::_Node *>;
template class std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >;
