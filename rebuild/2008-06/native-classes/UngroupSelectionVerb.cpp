#include "StandardVerbs.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/ModelInstance.h"
#include "Network/Players.h"
#include "util/Sound.h"
#include <boost/bind.hpp>
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
struct UngroupOperation {
    std::vector<Instance*>* children;
    bool* changed;
    UngroupOperation(std::vector<Instance*>& c, bool& b) : children(&c), changed(&b) {}
    void operator()(const boost::shared_ptr<Instance>&) const;
};

void UngroupSelectionVerb::doIt(IDataState* state) {
    checkRunPermissions(dataModel);
    FilteredSelection<ModelInstance>* models = ServiceProvider::create<FilteredSelection<ModelInstance> >(static_cast<const ServiceProvider*>(dataModel));
    std::vector<boost::shared_ptr<Instance> > stable;
    for (std::vector<ModelInstance*>::const_iterator iter = models->items().begin(); iter != models->items().end(); ++iter) {
        Instance* current = *iter;
        stable.push_back(current->shared_from_this());
    }
    std::vector<Instance*> children;
    bool changed = false;
    std::for_each(stable.begin(), stable.end(), UngroupOperation(children, changed));
    if (changed) {
        models->rootSelection->setSelection(children.begin(), children.end());
        ServiceProvider::create<Soundscape::SoundService>(static_cast<const ServiceProvider*>(dataModel))->playSound(PING_SOUND);
    }
    recordCameraHistory(getName().c_str(), workspace.get());
    state->setDirty(true);
}
}
