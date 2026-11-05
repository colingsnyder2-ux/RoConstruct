#include "StandardVerbs.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "util/Sound.h"
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

void GroupSelectionVerb::doIt(IDataState* state) {
    checkRunPermissions(dataModel);
    Selection* current = ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
    Instance* group = workspace->group(current->selection->begin(), current->selection->end()).get();
    current->setSelection(group);
    Soundscape::SoundService* sound = ServiceProvider::create<Soundscape::SoundService>(static_cast<const ServiceProvider*>(dataModel));
    sound->playSound(PING_SOUND);
    recordCameraHistory(getName().c_str(), workspace.get()); state->setDirty(true);
}

}
