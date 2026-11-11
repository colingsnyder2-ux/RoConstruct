// >>> native-status (generated) -- do not edit >>>
// PlayersSuperSafe | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by tester (claude-opus-5-5)
// <<< native-status | src a9a310e3 | roc native-status --write
#include "Network/Players.h"
#include "Network/Player.h"

bool RBX::Network::Players::superSafeOn() const
{
    if (localPlayer)
        return Player::prop_SuperSafeChat.getValue(localPlayer.get());
    return false;
}
