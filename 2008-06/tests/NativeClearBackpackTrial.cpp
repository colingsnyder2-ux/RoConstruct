#include "StandardVerbs.h"
#include "v8datamodel/DataModel.h"
#include <stdexcept>
namespace RBX {
class Backpack : public Instance {};
namespace Network {
class Player { public: Backpack* getPlayerBackpack() const; };
class Players { public: static Player* findLocalPlayer(const Instance*); };
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
    if (Network::Player* player = Network::Players::findLocalPlayer(dataModel))
        if (Backpack* backpack = player->getPlayerBackpack()) return backpack->numChildren() > 0;
    return false;
}
void ClearBackpack::doIt(IDataState*) {
    checkRunPermissions(dataModel);
    if (Network::Player* player = Network::Players::findLocalPlayer(dataModel))
        player->getPlayerBackpack()->removeAllChildren();
}
}
