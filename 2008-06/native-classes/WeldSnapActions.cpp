// >>> native-status (generated) -- do not edit >>>
// WeldSnapActions | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 4b977c25 | roc native-status --write
#include "../native-headers/StandardVerbs.h"
#include "../native-headers/v8datamodel/Workspace.h"
#include "../native-headers/v8datamodel/DataModel.h"
#include "../native-headers/v8datamodel/Selection.h"
#include "../native-headers/Network/Players.h"
#include "../native-headers/util/Sound.h"
#include <stdexcept>
#include <boost/bind.hpp>

namespace RBX {

inline const Name& Verb::getName() const { return name; }
void recordCameraHistory(const char*, const Instance*);
void weldInstance(boost::shared_ptr<Instance>);
void snapInstance(boost::shared_ptr<Instance>);

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

void WeldSelectionVerb::doIt(IDataState* state) {
    checkRunPermissions(dataModel);
    ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
    std::for_each(selection->selection->begin(), selection->selection->end(), boost::bind(weldInstance, _1));
    Soundscape::SoundService* sound = ServiceProvider::create<Soundscape::SoundService>(static_cast<const ServiceProvider*>(dataModel));
    sound->playSound(PING_SOUND);
    recordCameraHistory(getName().c_str(), workspace.get());
    state->setDirty(true);
}

void SnapSelectionVerb::doIt(IDataState* state) {
    checkRunPermissions(dataModel);
    ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
    std::for_each(selection->selection->begin(), selection->selection->end(), boost::bind(snapInstance, _1));
    Soundscape::SoundService* sound = ServiceProvider::create<Soundscape::SoundService>(static_cast<const ServiceProvider*>(dataModel));
    sound->playSound(PING_SOUND);
    recordCameraHistory(getName().c_str(), workspace.get());
    state->setDirty(true);
}

}
