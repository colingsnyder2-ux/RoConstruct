// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
#include "Network/Client2008.h"
#include "Network/Players.h"

namespace RBX
{
	namespace Network
	{
		// 0049fe50
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
