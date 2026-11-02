#include "v8datamodel/DataModel.h"
#include "Network/Players.h"
#include "Network/Player.h"
#include "v8datamodel/Backpack.h"
#include "StandardVerbs.h"
namespace RBX {
bool ClearBackpack::isEnabled() const {
    Network::Player* player = Network::Players::findLocalPlayer(dataModel);
    if (player) {
        Backpack* backpack = player->getPlayerBackpack();
        if (backpack) return backpack->numChildren() > 0;
    }
    return false;
}
}
