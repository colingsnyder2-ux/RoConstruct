// >>> native-status (generated) -- do not edit >>>
// DataModelCreate | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/1 mapped addresses byte-exact | 0 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
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
