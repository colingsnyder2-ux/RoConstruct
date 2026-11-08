// >>> native-status (generated) -- do not edit >>>
// CDataModelPropGridUpdate | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 1254405e | roc native-status --write
#include "CDataModelPropGrid.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"

void CDataModelPropGrid::update(boost::shared_ptr<RBX::DataModel> model,
                              boost::shared_ptr<RBX::DataModel>)
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
