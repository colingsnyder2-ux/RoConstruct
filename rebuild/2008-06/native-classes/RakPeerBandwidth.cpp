// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /U_RELEASE /FImalloc.h /I{headers}/../../../tools/openrbx/Client/Network/raknet30/Source /I{headers}/../../../tools/openrbx/util
#include "../native-headers/RakPeer.h"

void RakPeer::SetPerConnectionOutgoingBandwidthLimit(unsigned maxBitsPerSecond)
{
    maxOutgoingBPS = maxBitsPerSecond;
}
