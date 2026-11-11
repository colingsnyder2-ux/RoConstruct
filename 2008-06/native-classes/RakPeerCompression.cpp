// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
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
