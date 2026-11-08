// >>> native-status (generated) -- do not edit >>>
// DataModelCreate | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 98cd48d9 | roc native-status --write
#include "v8datamodel/DataModel.h"

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
