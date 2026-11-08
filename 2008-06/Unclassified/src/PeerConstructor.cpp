// >>> native-status (generated) -- do not edit >>>
// PeerConstructor | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src ab2762eb | roc native-status --write
#include "Replicator.h"
#include "ProfiledRakPeer.h"

namespace RBX { namespace Network {

Peer::Peer() : profilePacketsThread(new Profiling::CodeProfiler("Packets Thread"))
{
    rakPeer.reset(new ProfiledRakPeer(profilePacketsThread.get()));
    rakPeer->AttachPlugin(this);
}

} }
