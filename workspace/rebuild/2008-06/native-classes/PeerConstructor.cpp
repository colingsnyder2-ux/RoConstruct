#include "Replicator.h"
#include "ProfiledRakPeer.h"

namespace RBX { namespace Network {

Peer::Peer() : profilePacketsThread(new Profiling::CodeProfiler("Packets Thread"))
{
    rakPeer.reset(new ProfiledRakPeer(profilePacketsThread.get()));
    rakPeer->AttachPlugin(this);
}

} }
