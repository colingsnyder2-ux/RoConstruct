// >>> native-status (generated) -- do not edit >>>
// PlayersSuperSafe | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src a9a310e3 | roc native-status --write
#include "Network/Players.h"
#include "Network/Player.h"

bool RBX::Network::Players::superSafeOn() const
{
    if (localPlayer)
        return Player::prop_SuperSafeChat.getValue(localPlayer.get());
    return false;
}
