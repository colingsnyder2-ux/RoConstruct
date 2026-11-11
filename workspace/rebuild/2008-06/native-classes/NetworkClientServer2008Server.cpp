// 2008-06 native RBX::Network::Server (inactive); evidence in native-headers/Network/Server2008.h.
// Verified by tests/record_native_network_client_server2008.py. Original bodies: constructor 004a4b30,
// DescribedCreatable<Server> 004a42c0, FactoryProduct<Server> 004a15f0 / ~FactoryProduct 004a1580, destructor
// 004a3540, classDescriptor 0049eba0.
// >>> native-status (generated) -- do not edit >>>
// NetworkClientServer2008Server | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/1 mapped addresses byte-exact | 0 unproved | no mapped strings | by auto
// <<< native-status | src 308c979a | roc native-status --write
#include "Network/Server2008.h"
#include "Network/API.h"

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
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::scoped_ptr<RakPeer>;
template class std::_Tree<std::_Tset_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,0> >;
template class std::allocator<std::_Tree_nod<std::_Tset_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,0> >::_Node *>;
template class std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >;
