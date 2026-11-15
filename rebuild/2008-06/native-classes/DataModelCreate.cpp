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
