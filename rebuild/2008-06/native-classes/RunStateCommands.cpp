#include "../native-headers/StandardVerbs.h"
#include "../native-headers/v8datamodel/Workspace.h"
#include "../native-headers/util/RunStateOwner.h"
#include "../native-headers/v8datamodel/DataModel.h"
#include "../native-headers/Network/Players.h"
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

void SelectAllCommand::doIt(IDataState*) {
    checkRunPermissions(dataModel);
    dataModel->getWorkspace()->selectAll();
}

void RunCommand::doIt(IDataState*) {
    checkRunPermissions(dataModel);
    RunService* service = runService.operator->();
    service->setRunState(RS_RUNNING);
}

void StopCommand::doIt(IDataState*) {
    checkRunPermissions(dataModel);
    RunService* service = runService.operator->();
    service->setRunState(RS_PAUSED);
}

void ResetCommand::doIt(IDataState*) {
    checkRunPermissions(dataModel);
    RunService* service = runService.operator->();
    service->setRunState(RS_NORMAL);
}

}
