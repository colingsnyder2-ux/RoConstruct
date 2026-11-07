// >>> native-status (generated) -- do not edit >>>
// PeerLifetime | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src f7ffda92 | roc native-status --write
#include <RakPeer.h>
#include "Replicator.h"
namespace RBX { namespace Network {
Peer::~Peer() { rakPeer->DetachPlugin(this); }
}}
