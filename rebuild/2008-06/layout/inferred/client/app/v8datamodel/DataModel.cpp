#include "CRobloxView.h"

void CRobloxWnd::finishAttach() {
    (void)this->dataModel;
    (void)this->dataModelPtr;
    (void)this->adorn;
}

#include "v8datamodel/DataModel.h"
#include "util/Name.h"

namespace RBX {

boost::shared_ptr<boost::recursive_mutex> __cdecl DataModel::getMutex(Instance* context)
{
	if (!context)
		return boost::shared_ptr<boost::recursive_mutex>();

	Instance* root = context;
	if (context->getParent())
		root = context->getRootAncestor();

	DataModel* dataModel = dynamic_cast<DataModel*>(root);
	if (!dataModel)
		return boost::shared_ptr<boost::recursive_mutex>();

	return dataModel->getMutex();
}

}

#include "v8tree/Service.h"

namespace RBX {
	bool ServiceProvider::askAddChild(const Instance* instance) const
	{
		return dynamic_cast<const Service*>(instance) != NULL;
	}
}

namespace RBX {
extern template boost::shared_ptr<DataModel> Creatable<Instance>::create<DataModel>();

boost::shared_ptr<DataModel> DataModel::createDataModel(bool start) {
    boost::shared_ptr<DataModel> result = Creatable<Instance>::create<DataModel>();
    Lock lock(result);
    result->initializeContents(start);
    result->renderEnabled = true;
    return result;
}
}

#include "util/RunStateOwner.h"

double RBX::DataModel::getDutyCycle() const { return runService->dutyCycle(); }

#include "v8datamodel/Workspace.h"

namespace RBX { typedef DescendantAdded DescendentAdded; typedef DescendantRemoving DescendentRemoving; }
#include "v8datamodel/LocalBackpack.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/JointsService.h"
#include "gui/Gui.h"
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

template class boost::shared_ptr<RBX::LocalBackpack>;
template class std::_Vector_const_iterator<RBX::Listener<RBX::RunService,RBX::RunTransition> *,std::allocator<RBX::Listener<RBX::RunService,RBX::RunTransition> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::RunService,RBX::RunTransition> *,std::allocator<RBX::Listener<RBX::RunService,RBX::RunTransition> *> >;

double RBX::DataModel::getGameTime() const { return runService->gameTime(); }
double RBX::DataModel::getFrameRate() const { return runService->frameRate(); }
