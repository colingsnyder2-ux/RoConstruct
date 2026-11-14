// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native service-provider / receive hooks of the Network classes (inactive). Declarations are the committed
// native headers Network/Client2008.h and Network/Players.h (read-only here).
//   * Client::onServiceProvider 0049fe50: removeListener 005e5a80 / addListener 004218a0 (Notifier<ServiceProvider,
//     Closing> at ServiceProvider +0x130, listener this + 0x144), removeAllChildren 0055afd0, rakPeer slots 25
//     (CloseConnection) and 10 (Shutdown), ServiceProvider::find<Players>() const 004125d0 / create<Players>() const
//     00412710, Players::setConnection 00496510, Peer::onServiceProvider 004b5700. The find / create results are
//     named locals: chained calls push the setConnection argument before the find / create call (rejected).
// Open in this unit (declarations missing from the read-only headers): Server::onServiceProvider 004a4100 (needs
// Peer::peerInterface 00609a30 and the Server member 004a31d0 bound into visitDescendents 004a27e0 /
// event_descendentAdded.connect 004a3340), Server::OnReceive 004a4dc0 (needs Server's static signal at 00970ebc and
// the Replicator member 004a2ac0), Client::OnReceive 004a1070 (Client signals), Peer::onServiceProvider 004b5700
// (stats item members), RoundRobinPhysicsSender::sendPackets 004cd420 (0x13c-byte local type 004cbd40 / 004c9a70,
// members 004ca040 / 004cac30 / 004cbad0), Replicator::wantReplicate 004aaf90 and StringReceiver::receive 004a6f70
// (not declared). JointsService::askAddChild 004afb30 is already the inline body in v8datamodel/JointsService.h.
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
