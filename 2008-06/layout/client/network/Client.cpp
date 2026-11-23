// =============================================================================
// Client.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/network/Client.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
		void Client::onEvent(const ServiceProvider* source, Closing event)
		{
			disconnect(3000);
		}
#endif
	}
}

#include "Network/Players.h"

namespace RBX
{
	namespace Network
	{
		void Client::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
		{
			Notifier<ServiceProvider, Closing>::disconnect(oldProvider, this);

			if (oldProvider)
			{
				removeAllChildren();
				// disconnect(3000), inlined in the original.
				rakPeer->CloseConnection(serverId, true, 0);
				rakPeer->Shutdown(3000, 0);

				Players* p = oldProvider->find<Players>();
				p->setConnection(NULL);
			}

			Peer::onServiceProvider(oldProvider, newProvider);

			if (newProvider)
			{
				Players* p = newProvider->create<Players>();
				p->setConnection(rakPeer.get());
			}

			Notifier<ServiceProvider, Closing>::connect(newProvider, this);
		}
	}
}

#include "AppLeaves2008/Exposer2008.h"

const char* Exposer::IDTOString(int id)
{
	Exposer exposer;
	return exposer.PacketLogger::IDTOString((unsigned char)id);
}
