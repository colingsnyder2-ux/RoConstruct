// >>> native-status (generated) -- do not edit >>>
// RakPeerBandwidth | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by auto
// <<< native-status | src 9df4c67f | roc native-status --write
#include "RakPeer.h"

void RakPeer::SetPerConnectionOutgoingBandwidthLimit(unsigned maxBitsPerSecond)
{
    maxOutgoingBPS = maxBitsPerSecond;
}
