#include "CDataModelPropGrid.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"

void CDataModelPropGrid::update(boost::shared_ptr<RBX::DataModel> model,
                              boost::shared_ptr<RBX::Instance>)
{
    if (dataModel) {
        RBX::DataModel::Lock lock(dataModel);
        setSelection(NULL);
    }
    dataModel = model.get();
    if (dataModel) {
        RBX::DataModel::Lock lock(dataModel);
        setSelection(RBX::ServiceProvider::create<RBX::Selection>(dataModel));
    }
}
