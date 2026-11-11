// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// RakPeerCompression | 2008-06 | 2 byte-exact, inactive (not link-selected)
// 2/2 mapped addresses byte-exact | 0 unproved | no mapped strings | by colin (+1) (chatgpt:gpt-6.1-sol)
// <<< native-status | src 7bf8d8f2 | roc native-status --write
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
