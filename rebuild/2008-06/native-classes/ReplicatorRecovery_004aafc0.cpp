// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
#include "Network/Replicator2008.h"
#include "Network/Players.h"

namespace RBX { namespace Network {
bool Replicator::canSendItems() { return receivedGlobals; }
Player* Replicator::findTargetPlayer() { return players ? players->getLocalPlayer() : 0; }
} }
