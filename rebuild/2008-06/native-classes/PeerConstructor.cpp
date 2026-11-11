// >>> native-status (generated) -- do not edit >>>
// PeerConstructor | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
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
