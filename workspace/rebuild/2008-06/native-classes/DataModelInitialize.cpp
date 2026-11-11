// >>> native-status (generated) -- do not edit >>>
// DataModelInitialize | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src ffa526b5 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
namespace RBX { typedef DescendantAdded DescendentAdded; typedef DescendantRemoving DescendentRemoving; }
#include "v8datamodel/LocalBackpack.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/JointsService.h"
#include "gui/Gui.h"
#include "util/RunStateOwner.h"
#include "util/Sound.h"

namespace RBX {
class PhysicsService;
template<> PhysicsService* ServiceProvider::create<PhysicsService>() const;

void DataModel::initializeContents(bool start) {
    workspace->setParent(this);
    guiRoot->setParent(this);
    guiHooks->setParent(this);
    localBackpack = shared_from(ServiceProvider::create<LocalBackpack>());
    starterPackService = shared_from(ServiceProvider::create<StarterPackService>());
    runService = shared_from(ServiceProvider::create<RunService>());
    ServiceProvider::create<Soundscape::SoundService>();
    workspace->setNullMouseCommand();
    workspace->setVerbParent(this);
    if (start) runService->start();
    Notifier<RunService, RunTransition>::connect(runService, this);
    ServiceProvider::create<JointsService>();
    ServiceProvider::create<PhysicsService>();
}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::LocalBackpack>;
template class std::_Vector_const_iterator<RBX::Listener<RBX::RunService,RBX::RunTransition> *,std::allocator<RBX::Listener<RBX::RunService,RBX::RunTransition> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::RunService,RBX::RunTransition> *,std::allocator<RBX::Listener<RBX::RunService,RBX::RunTransition> *> >;
