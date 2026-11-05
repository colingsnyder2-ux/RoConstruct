// from server: 100% by sophus
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 roc_unit_d58a6286b29f1d11.cpp

// Candidate translation unit (score above; library headers required).
#include "RakPeer.h"

int RakNet::RakPeer::GetLowestPing(const RakNet::AddressOrGUID systemIdentifier) const
{
    RakNet::RakPeer::RemoteSystemStruct *remoteSystem = GetRemoteSystem(systemIdentifier, false, false);
    if (remoteSystem == 0)
        return -1;
    return *(unsigned short*)((char*)remoteSystem + 0x11c0);
}
