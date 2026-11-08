// >>> native-status (generated) -- do not edit >>>
// RakPeerCompression | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 93e9cfd3 | roc native-status --write
#include "RakPeer.h"

float RakPeer::GetCompressionRatio() const
{
    if (rawBytesSent > 0)
        return (float)compressedBytesSent / (float)rawBytesSent;
    return 0.0f;
}

float RakPeer::GetDecompressionRatio() const
{
    if (rawBytesReceived > 0)
        return (float)compressedBytesReceived / (float)rawBytesReceived;
    return 0.0f;
}
