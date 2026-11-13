// >>> native-status (generated) -- do not edit >>>
// JoinCommand | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by Espeon (deepseek:deepseek-chat)
// <<< native-status | src 876aa58f | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "StandardVerbs.h"
#include <stdexcept>

namespace RBX {

class MotorFeature {
public:
    static bool canJoin(Instance*, Instance*);
    static void join(Instance*, Instance*);
};

namespace Network {
class Client { public: static bool clientIsPresent(const Instance*, bool); };
class Server { public: static bool serverIsPresent(const Instance*, bool); };
}

static __declspec(noinline) void checkRunPermissions(Instance* instance)
{
    if (Network::Client::clientIsPresent(instance, true) && !Network::Server::serverIsPresent(instance, true)) {
        std::string message("Insufficinet permissions");
        throw std::runtime_error(message);
    }
}

bool JoinCommand::isEnabled() const
{
    Selection* selection = ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
    if (selection->size() == 2) {
        boost::shared_ptr<Instance> first = selection->front();
        boost::shared_ptr<Instance> last = selection->back();
        if (MotorFeature::canJoin(first.get(), last.get())) return true;
    }
    return false;
}

void JoinCommand::doIt(IDataState*)
{
    checkRunPermissions(dataModel);
    Selection* selection = ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
    if (selection->size() == 2) {
        boost::shared_ptr<Instance> first = selection->front();
        boost::shared_ptr<Instance> last = selection->back();
        MotorFeature::join(first.get(), last.get());
    }
}

}
