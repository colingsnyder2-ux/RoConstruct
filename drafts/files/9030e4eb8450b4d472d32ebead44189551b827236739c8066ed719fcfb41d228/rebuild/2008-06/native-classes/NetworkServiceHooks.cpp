// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native service-provider / receive hooks of the Network classes (inactive). Declarations are the committed
// native headers Network/Client2008.h and Network/Players.h (read-only here).
//   * Client::onServiceProvider 0049fe50: removeListener 005e5a80 / addListener 004218a0 (Notifier<ServiceProvider,
//     Closing> at ServiceProvider +0x130, listener this + 0x144), removeAllChildren 0055afd0, rakPeer slots 25
//     (CloseConnection) and 10 (Shutdown), ServiceProvider::find<Players>() const 004125d0 / create<Players>() const
//     00412710, Players::setConnection 00496510, Peer::onServiceProvider 004b5700.
#include "Network/Client2008.h"
#include "Network/Players.h"

namespace RBX
{
	namespace Network
	{
		// @0049fe50 ?onServiceProvider@Client@Network@RBX@@MAEXPBVServiceProvider@3@0@Z
		void Client::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
		{
			Notifier<ServiceProvider, Closing>::disconnect(oldProvider, this);

			if (oldProvider)
			{
				// disconnect(3000), inlined in the original (Client::disconnect 0049f0f0 is defined in the
				// NetworkClientServer2008Client.cpp unit here, so the body is spelled out).
				removeAllChildren();
				rakPeer->CloseConnection(serverId, true, 0);
				rakPeer->Shutdown(3000, 0);

				oldProvider->find<Players>()->setConnection(NULL);
			}

			Peer::onServiceProvider(oldProvider, newProvider);

			if (newProvider)
				newProvider->create<Players>()->setConnection(rakPeer.get());

			Notifier<ServiceProvider, Closing>::connect(newProvider, this);
		}
	}
}
