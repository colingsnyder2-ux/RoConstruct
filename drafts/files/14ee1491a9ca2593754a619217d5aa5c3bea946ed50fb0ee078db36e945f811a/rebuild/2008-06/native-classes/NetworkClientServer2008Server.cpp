// 2008-06 native RBX::Network::Server (inactive); evidence in native-headers/Network/Server2008.h.
// Verified by tests/record_native_network_client_server2008.py. Original bodies: constructor 004a4b30,
// DescribedCreatable<Server> 004a42c0, FactoryProduct<Server> 004a15f0 / ~FactoryProduct 004a1580, destructor
// 004a3540, classDescriptor 0049eba0.
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
