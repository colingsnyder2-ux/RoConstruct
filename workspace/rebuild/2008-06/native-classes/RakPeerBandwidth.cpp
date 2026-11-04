#include "RakPeer.h"

void RakPeer::SetPerConnectionOutgoingBandwidthLimit(unsigned maxBitsPerSecond)
{
    maxOutgoingBPS = maxBitsPerSecond;
}
