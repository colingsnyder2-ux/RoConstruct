// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Players::superSafeOn (00497600) - native 2008-06.
// >>> native-status (generated) -- do not edit >>>
// PlayersSuperSafe | 2008-06 | draft (byte proof at 00497600)
// 1/1 mapped addresses byte-exact | no mapped strings | by colin
// <<< native-status | src a9a310e3 | roc native-status --write
#include "Network/Players.h"
#include "Network/Player.h"

bool RBX::Network::Players::superSafeOn() const
{
    if (localPlayer)
        return Player::prop_SuperSafeChat.getValue(localPlayer.get());
    return false;
}
