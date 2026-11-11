// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// >>> native-status (generated) -- do not edit >>>
// MoveUpSelectionVerb | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by EspClaude (deepseek:deepseek-chat)
// <<< native-status | src 8a34306c | roc native-status --write
#include "../native-headers/StandardVerbs.h"
#include "../native-headers/v8datamodel/Workspace.h"
#include "../native-headers/util/RunStateOwner.h"
#include "../native-headers/v8datamodel/DataModel.h"
#include "../native-headers/v8datamodel/Selection.h"
#include "../native-headers/v8datamodel/PVInstance.h"
#include "../native-headers/Network/Players.h"
#include "../native-headers/util/Sound.h"
#include "../native-headers/tool/MegaDragger.h"
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
