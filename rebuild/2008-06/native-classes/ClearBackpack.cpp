#include "v8datamodel/DataModel.h"
#include "Network/Players.h"
#include "Network/Player.h"
#include "v8datamodel/Backpack.h"
#include "StandardVerbs.h"
#include <stdexcept>
namespace RBX {
namespace Network {
class Client { public: static bool clientIsPresent(const Instance*, bool); };
class Server { public: static bool serverIsPresent(const Instance*, bool); };
}
static __declspec(noinline) void checkRunPermissions(Instance* instance) {
    if (Network::Client::clientIsPresent(instance, true) && !Network::Server::serverIsPresent(instance, true)) {
        std::string message("Insufficinet permissions");
        throw std::runtime_error(message);
    }
}
bool ClearBackpack::isEnabled() const {
    Network::Player* player = Network::Players::findLocalPlayer(dataModel);
    if (player) {
        Backpack* backpack = player->getPlayerBackpack();
        if (backpack) return backpack->numChildren() > 0;
    }
    return false;
}
void ClearBackpack::doIt(IDataState*) {
    checkRunPermissions(dataModel);
    if (Network::Player* player = Network::Players::findLocalPlayer(dataModel))
        player->getPlayerBackpack()->removeAllChildren();
}
}
