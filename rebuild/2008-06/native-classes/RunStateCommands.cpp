// >>> native-status (generated) -- do not edit >>>
// RunStateCommands | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 995261ec | roc native-status --write
#include "../native-headers/StandardVerbs.h"
#include "../native-headers/v8datamodel/Workspace.h"
#include "../native-headers/util/RunStateOwner.h"
#include "../native-headers/v8datamodel/DataModel.h"
#include "../native-headers/v8datamodel/PVInstance.h"
#include "../native-headers/v8datamodel/PartInstance.h"
#include "../native-headers/Network/Players.h"
#include <stdexcept>

namespace RBX {

inline const Name& Verb::getName() const { return name; }
void recordCameraHistory(const char*, const Instance*);

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

void AllCanSelectCommand::doIt(IDataState* state) {
    checkRunPermissions(dataModel);
    Workspace* workspace = dataModel->getWorkspace();
    PartInstance::setLocked(workspace, false);
    recordCameraHistory(getName().c_str(), workspace);
    state->setDirty(true);
}

bool RunCommand::isEnabled() const {
    RunState state = runService->getRunState();
    return !Network::Client::clientIsPresent(dataModel, true) && state != RS_RUNNING;
}

bool ResetCommand::isEnabled() const {
    RunState state = runService->getRunState();
    return (state == RS_RUNNING || state == RS_PAUSED) && !Network::Players::findLocalPlayer(dataModel);
}

bool StopCommand::isEnabled() const {
    return runService->getRunState() == RS_RUNNING;
}

bool FirstPersonCommand::isEnabled() const {
    return dataModel->getWorkspace()->getCamera()->isFirstPersonCamera();
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
