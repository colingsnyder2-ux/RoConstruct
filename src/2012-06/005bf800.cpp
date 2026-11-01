// from server: 100% by sophus
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 roc_unit_3583487765c2cbdf.cpp

// Candidate translation unit (score above; library headers required).
#include "RakPeer.h"

int RakNet::RakPeer::GetAveragePing(const RakNet::AddressOrGUID systemIdentifier)
{
    int sum, quantity;
    RakNet::RakPeer::RemoteSystemStruct *remoteSystem = GetRemoteSystem(systemIdentifier, false, false);

    if (remoteSystem == 0)
        return -1;

    for (sum = 0, quantity = 0; quantity < 5; quantity++)
    {
        unsigned short pingTime = *(unsigned short*)((char*)remoteSystem + 0x1168 + quantity * 0x10);
        if (pingTime == 65535)
            break;
        else
            sum += pingTime;
    }

    if (quantity > 0)
        return sum / quantity;
    else
        return -1;
}
