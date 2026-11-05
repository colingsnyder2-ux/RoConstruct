#include "StandardVerbs.h"
#include "v8datamodel/Workspace.h"
#include "util/RunStateOwner.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "Network/Players.h"
#include "util/Sound.h"
#include <stdexcept>
#include "tool/MegaDragger.h"
#include <boost/bind.hpp>
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
void MoveUpSelectionVerb::doIt(IDataState* state) {
 checkRunPermissions(dataModel);
 FilteredSelection<PVInstance>* selected = ServiceProvider::create<FilteredSelection<PVInstance> >(static_cast<const ServiceProvider*>(dataModel));
 if (selected->size() > 0) {
  MegaDragger dragger(NULL, selected->items(), workspace.get());
  dragger.startDragging();
  dragger.safeMoveNoDrop(G3D::Vector3(0.0f, moveUpHeight, 0.0f));
  dragger.finishDragging();
  ServiceProvider::create<Soundscape::SoundService>(static_cast<const ServiceProvider*>(dataModel))->playSound(CLICK_SOUND);
  workspace->raiseDrawChanged();
  recordCameraHistory(getName().c_str(), workspace.get());
  state->setDirty(true);
 }
}
}
