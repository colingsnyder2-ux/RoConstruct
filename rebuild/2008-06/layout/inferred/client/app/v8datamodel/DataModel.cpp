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

double RBX::DataModel::getGameTime() const { return runService->gameTime(); }
double RBX::DataModel::getFrameRate() const { return runService->frameRate(); }
