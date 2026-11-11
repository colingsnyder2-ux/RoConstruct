// 2008-06 native RBX::Network::Client (inactive); evidence in native-headers/Network/Client2008.h.
// Verified by tests/record_native_network_client_server2008.py. Original bodies: constructor 004a0990,
// DescribedCreatable<Client> 0049ff10, FactoryProduct<Client> 0049eef0 / ~FactoryProduct 0049edb0, destructor
// 0049f2e0 (deleting 0049f4e0), classDescriptor 0049eb30 (atexit 007fba60).
// >>> native-status (generated) -- do not edit >>>
// NetworkClientServer2008Client | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 5e7de074 | roc native-status --write
#include "Network/Client2008.h"

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
		char sClient[] = "NetworkClient"; // 00938c88 (classDescriptor 0049eb30, constructor setName)

		Client::Client()
		{
			setName(sClient);
		}

		bool Client::clientIsPresent(const Instance* context, bool testInDatamodel)
		{
			return ServiceProvider::find<Client>(ServiceProvider::findServiceProvider(context)) != NULL;
		}

		Client::~Client()
		{
			rakPeer->CloseConnection(serverId, true, 0);
		}

		void Client::disconnect(int blockDuration)
		{
			removeAllChildren();
			rakPeer->CloseConnection(serverId, true, 0);
			rakPeer->Shutdown(blockDuration, 0);
		}

#ifdef NATIVE_NETWORK_CLIENT_PENDING
		// 0049f130 (Listener<ServiceProvider, Closing> slot 0, entered through the +0x144 subobject). Needs a complete
		// RBX::Closing (only forward-declared in the native v8tree/Service.h): header-owner proposal, verified by the
		// recorder against a generated Service.h copy under rebuild/2008-06/out/ (not counted).
		void Client::onEvent(const ServiceProvider* source, Closing event)
		{
			disconnect(3000);
		}
#endif
	}
}
