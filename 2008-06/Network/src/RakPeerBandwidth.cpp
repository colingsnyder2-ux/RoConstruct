// >>> native-status (generated) -- do not edit >>>
// RakPeerBandwidth | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 9df4c67f | roc native-status --write
#include "RakPeer.h"

void RakPeer::SetPerConnectionOutgoingBandwidthLimit(unsigned maxBitsPerSecond)
{
    maxOutgoingBPS = maxBitsPerSecond;
}
