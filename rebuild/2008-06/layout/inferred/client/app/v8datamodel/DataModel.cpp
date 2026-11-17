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
