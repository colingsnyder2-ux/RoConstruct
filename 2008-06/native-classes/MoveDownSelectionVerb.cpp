// >>> native-status (generated) -- do not edit >>>
// MoveDownSelectionVerb | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 310c2714 | roc native-status --write
#include "StandardVerbs.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/PVInstance.h"
#include "Network/Players.h"
#include "util/Sound.h"
#include "tool/MegaDragger.h"
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

void MoveDownSelectionVerb::doIt(IDataState* state) {
    checkRunPermissions(dataModel);
    FilteredSelection<PVInstance>* selected = ServiceProvider::create<FilteredSelection<PVInstance> >(static_cast<const ServiceProvider*>(dataModel));
    if (selected->size() > 0) {
        MegaDragger dragger(NULL, selected->items(), workspace.get());
        dragger.startDragging();
        G3D::Vector3 moved = dragger.safeMoveNoDrop(G3D::Vector3(0.0f, -1.2f, 0.0f));
        dragger.finishDragging();
        ServiceProvider::create<Soundscape::SoundService>(static_cast<const ServiceProvider*>(dataModel))->playSound(moved.y != 0 ? CLICK_SOUND : BOING_SOUND);
        workspace->raiseDrawChanged();
        recordCameraHistory(getName().c_str(), workspace.get());
        state->setDirty(true);
    }
}
}
