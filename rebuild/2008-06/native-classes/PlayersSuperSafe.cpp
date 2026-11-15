#include "Network/Players.h"
#include "Network/Player.h"

bool RBX::Network::Players::superSafeOn() const
{
    if (localPlayer)
        return Player::prop_SuperSafeChat.getValue(localPlayer.get());
    return false;
}
