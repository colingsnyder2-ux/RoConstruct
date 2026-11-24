// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
#include "Network/Replicator2008.h"
#include "Network/Players.h"
#include "AppUnit4AC/PeerHeartbeat.h"

// 004aaf50: donor Replicator.cpp checkDisconnect (pushed by Peer::onEvent 004add50 for for_eachChild): removes
// replicators whose +0x2d4d disconnected flag is set (setParent 0055a8f0).
void checkDisconnect(RBX::Instance* instance)
{
	RBX::Network::Replicator* repl = dynamic_cast<RBX::Network::Replicator*>(instance);

	if (repl && repl->disconnected)
	{
		repl->setParent(NULL);
	}
}

namespace RBX { namespace Network {
bool Replicator::canSendItems() { return receivedGlobals; }
Player* Replicator::findTargetPlayer() { return players ? players->getLocalPlayer() : 0; }
} }
