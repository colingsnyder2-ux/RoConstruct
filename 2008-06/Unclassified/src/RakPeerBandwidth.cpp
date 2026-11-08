// >>> native-status (generated) -- do not edit >>>
// RakPeerBandwidth | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 9df4c67f | roc native-status --write
#include "RakPeer.h"

void RakPeer::SetPerConnectionOutgoingBandwidthLimit(unsigned maxBitsPerSecond)
{
    maxOutgoingBPS = maxBitsPerSecond;
}
